#include "Tcp_NonBlock.h"
bool InitServer(void)
{
	InitMember();
	InitSocket();
	return TRUE;
}
void InitMember(void)
{
	InitializeCriticalSection(&csClientList);
	hServerEvent  = CreateEvent(NULL, TRUE, FALSE, NULL);   //手动设置事件，初始化为无信号状态
	hThreadAccept = NULL;
	hThreadHelp   = NULL;
	serverSocket = INVALID_SOCKET;
	bServerRunning = FALSE;
	clientlist.clear();
}

bool InitWinDll(int minorVer /* = 2 */, int majorVer /* = 2 */)
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(minorVer, majorVer);
	if (::WSAStartup(sockVersion, &wsaData) != 0)
	{
		ShowMsg("Can not find a usable Windows Sockets DLL !");
		return FALSE;
	}
	if (LOBYTE(wsaData.wVersion) != minorVer || HIBYTE(wsaData.wVersion) != majorVer)
	{
		ShowMsg("Can not find a usable Windows Sockets DLL !");
		return FALSE;
	}
	return TRUE;
}
BOOL InitSocket(void)
{
	InitWinDll();
	CreateServerSocket();

		//设置非阻塞模式
	unsigned long u = 1;
	int retVal = ioctlsocket(serverSocket, FIONBIO, (unsigned long *)&u);
	if (retVal == SOCKET_ERROR)
	{
		int ErrCode = WSAGetLastError();
		ShowSocketMsg(ErrCode, "SET IOCTRL Failed!");
		return FALSE;
	}
	BindSocket(5678, "127.0.0.1");
	ListenSocket();

	return TRUE;

}
bool CreateServerSocket(void)
{
	serverSocket = CreateSocket();
	return TRUE;
}
SOCKET CreateSocket(void)
{
	SOCKET newSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == newSocket)
	{
		//	ShowErrorMsg();
		int ErrCode = WSAGetLastError();
		ShowSocketMsg(ErrCode, "Create Socket Failed !");
		::WSACleanup();
		return INVALID_SOCKET;
	}
	return newSocket;
}
BOOL StartServerService(void)
{
	BOOL retVal = TRUE;
	ShowMsg("Chose for Server >>");
	char cInput;
	do 
	{
		std::cin >> cInput;
		if ('s' == cInput || 'S' == cInput)
		{
			if (CreateHelperAndAcceptThread())
			{
				ShowMsg("Clean Thread Created Successful!");
			}
			else
				retVal = FALSE;

			break;
		}
		else
		{
			ShowMsg("Chose for Server >>");
		}
		

	} while (cInput !='s' && cInput != 'S');

	return retVal;
	
}
BOOL CreateHelperAndAcceptThread(void)
{
	bServerRunning = TRUE;
	
	//创建释放资源线程
	unsigned int uThreadId;
	hThreadHelp = (HANDLE)_beginthreadex(NULL, 0, HelperThread, NULL, 0, &uThreadId);
	if (NULL == hThreadHelp)
	{
		bServerRunning = FALSE;
		return FALSE;
	}
	else
	{
		CloseHandle(hThreadHelp);
	}
	//创建接收客户端请求线程
	hThreadAccept = (HANDLE)_beginthreadex(NULL, 0, AcceptThread, NULL, 0, &uThreadId);
	if (NULL == hThreadAccept)
	{
		bServerRunning = FALSE;
		return FALSE;
	}
	else
	{
		CloseHandle(hThreadAccept);
	}

	return TRUE;

}
void StopService(void)
{
	BOOL retVal = TRUE;
	ShowMsg("Whether to Quit Server");
	char cInput;
	while (bServerRunning)
	{
		std::cin >> cInput;
		if (cInput == 'e' || cInput == 'E')
		{
			break;
		}
		else
			Sleep(TIMEFOR_THREAD_EXIT);                          //线程睡眠，让出cpu


	}
	bServerRunning = FALSE;
	ShowMsg("Server is Exiting...");
	Sleep(TIMEFOR_THREAD_EXIT);                           //给时间让其他线程退出
	WaitForSingleObject(hServerEvent, INFINITE);          //等待清理资源线程发送的事件，之后才能退出
	return;
	 
}
void ExitServer(void)
{
	DeleteCriticalSection(&csClientList);
	CloseHandle(hServerEvent);
	closesocket(serverSocket);
	WSACleanup();
}
void ShowSocketMsg(int ErrCode, const char * str)
{
	//Determine the way show the msg according to your need.As follows is a sample.
	std::cerr << "ErrCode :" << ErrCode << " " << str << std::endl;
}
void ShowMsg(const char * str)
{
	//Determine the way show the msg according to your need.As follows is a sample.
	std::cout << str << std::endl;
}
bool BindSocket(int port, char * ip)
{
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(port);
	addrServ.sin_addr.s_addr = inet_addr(ip);
	int ret = bind(serverSocket, (const sockaddr *)&addrServ, sizeof(addrServ));
	if (SOCKET_ERROR == ret)
	{

		int ErrCode = WSAGetLastError();
		ExitSocket(serverSocket);
		ShowSocketMsg(ErrCode, "Bind Failed!");
		return FALSE;
	}
	return TRUE;
}
bool ListenSocket(void)
{
	int ret = listen(serverSocket, 100);
	if (SOCKET_ERROR == ret)
	{
		int ErrCode = WSAGetLastError();
		ExitSocket(serverSocket);
		ShowSocketMsg(ErrCode, "Listen Failed !");
		return FALSE;
	}

	ShowMsg("Server Starts Successfully!");
	ShowMsg("Waiting For New Clients ...");

	return TRUE;
}

unsigned int  WINAPI AcceptThread(void * pParam)
{
	SOCKET clientSocket = INVALID_SOCKET;
	SOCKADDR_IN addrClient;
	while (bServerRunning)
	{
		memset(&addrClient, 0, sizeof(addrClient));
		int lenClient = sizeof(addrClient);
		clientSocket = accept(serverSocket, (sockaddr *)&addrClient, &lenClient);
		if (INVALID_SOCKET == clientSocket)
		{
			int ErrCode = WSAGetLastError();
			if (ErrCode == WSAEWOULDBLOCK)
			{
				Sleep(TIMEFOR_THREAD_EXIT);
				continue;
			}
			else
			{
				ShowSocketMsg(ErrCode, "Accept Failed!");
				return FALSE;
			}
		}
		CClient * pClient = new CClient(clientSocket, addrClient);
		EnterCriticalSection(&csClientList);
		clientlist.push_back(pClient);
		LeaveCriticalSection(&csClientList);
		pClient->StartRuning();
	}
}
CClient::CClient(const SOCKET clientSocket, const sockaddr_in &addrClient):
m_hThreadRecv(NULL), m_hThreadSend(NULL), m_socket(clientSocket), m_addr(addrClient),
m_bConning(FALSE), m_bExit(FALSE)
{
	memset(RecvBuf, 0, MAX_NUM_BUF);
	memset(SendBuf, 0, MAX_NUM_BUF);
	m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	InitializeCriticalSection(&m_cs);
}
CClient::~CClient()
{
	closesocket(m_socket);
	m_socket = INVALID_SOCKET;
	DeleteCriticalSection(&m_cs);
	CloseHandle(m_hEvent);
}
BOOL CClient::StartRuning(void)
{
	m_bConning = TRUE;
	//创建接收数据线程
	unsigned int uThreadId;
	m_hThreadRecv = (HANDLE)_beginthreadex(NULL, 0, RecvDataThread, this, 0, &uThreadId);
	if (NULL == m_hThreadRecv)
	{
		return FALSE;
	}
	else
	{
		CloseHandle(m_hThreadRecv);
	}

	//创建接收数据线程
	m_hThreadSend = (HANDLE)_beginthreadex(NULL, 0, SendDataThread, this, 0, &uThreadId);
	if (NULL == m_hThreadSend)
	{
		return FALSE;
	}
	else
	{
		CloseHandle(m_hThreadSend);
	}
	return TRUE;
}
unsigned int CClient::RecvDataThread(void * pParam)
{
	CClient * pClient = static_cast<CClient *>(pParam);
	int retVal;
	char temp[MAX_NUM_BUF];
	memset(temp, 0, MAX_NUM_BUF);

	while (pClient->m_bConning)
	{
		retVal = recv(pClient->m_socket, pClient->RecvBuf, MAX_NUM_BUF, 0);

		if (SOCKET_ERROR == retVal)
		{
			int ErrCode = WSAGetLastError();
			if (WSAEWOULDBLOCK == ErrCode)
			{
				continue;
			}
			else
			{
				ShowSocketMsg(ErrCode, "RecvData Failed");
				break;
			}
		}
		if (retVal == 0)
		{
			break;
		}
		std::cout << "GET::" << pClient->RecvBuf << std::endl;
		memset(pClient->RecvBuf, 0, MAX_NUM_BUF);
	}
	
	//接收到数据，通知发送线程启动，否则连接断开，不启动发送线程
	//if (retVal > HEADERLEN)
	//{
	//	pClient->HandleData(temp);
	//	SetEvent(pClient->m_hEvent);                              //通知发送线程
	//	memset(temp, 0, MAX_NUM_BUF);
	//}
	

	Sleep(TIMEFOR_THREAD_EXIT);
	//接收到数据后线程就退出，短连接。如果接收失败=也退出。
	pClient->m_bConning = FALSE;							//与客户端断开
	SetEvent(pClient->m_hEvent);                             //通知发送线程退出
	return 0;
}
void CClient::HandleData(const char * pExpr)
{
	std::cout << "Handle" << std::endl;

	
}

unsigned int CClient::SendDataThread(void * pParam)
{
	CClient * pClient = static_cast<CClient *>(pParam);
	
	while (pClient->m_bConning)
	{
		if (WAIT_OBJECT_0 == WaitForSingleObject(pClient->m_hEvent, INFINITE))
		{
			if (!pClient->m_bConning)
			{
				pClient->m_bExit = TRUE;
				break;
			}
			else
			{
				//客户端连接正常，可发送数据
				EnterCriticalSection(&pClient->m_cs);
			//	传入数据
				return 0;
				int retVal = send(pClient->m_socket, pClient->SendBuf, MAX_NUM_BUF, 0);
				if (SOCKET_ERROR == retVal)
				{
					int ErrCode = WSAGetLastError();
					if (WSAEWOULDBLOCK == ErrCode)
					{
						continue;
					}
					else
					{
						ShowSocketMsg(ErrCode, "SEND Failed");
						LeaveCriticalSection(&pClient->m_cs);
						pClient->m_bConning = FALSE;
						pClient->m_bExit = TRUE;
						break;
					}
				}
				LeaveCriticalSection(&pClient->m_cs);
				ResetEvent(&pClient->m_hEvent);
			}

		}
	}

	return 0;
}
unsigned int WINAPI HelperThread(void * pParam)
{
	while (bServerRunning)
	{
		EnterCriticalSection(&csClientList);
		CLIENTLIST::iterator it = clientlist.begin();

		while (it != clientlist.end())
		{
			CClient * pClient = (CClient *)(*it);
			if (pClient->IsExit())
			{
				clientlist.erase(it++);
				delete pClient;
				pClient = NULL;
			}
			else
				it++;
			
		}
		LeaveCriticalSection(&csClientList);
		Sleep(TIMEFOR_THREAD_EXIT);

	}

	if (!bServerRunning)
	{
		EnterCriticalSection(&csClientList);
		CLIENTLIST::iterator it = clientlist.begin();
		
		while (it != clientlist.end())
		{
			CClient * pClient = (CClient *)(*it);
			if (pClient->IsConning())
			{
				pClient->DisConning();
			}
			it++;
		}
		LeaveCriticalSection(&csClientList);

		Sleep(TIMEFOR_THREAD_EXIT);

		//设置退出后线程后回收资源

		while (0 != clientlist.size())
		{
			it = clientlist.begin();
			while (it != clientlist.end())
			{
				CClient * pClient = (CClient *)(*it);
				if (pClient->IsExit())
				{
					clientlist.erase(it++);
					delete pClient;
					pClient = NULL;
				}
				else
				{
					//等待线程退出
					it++;
					Sleep(TIMEFOR_THREAD_EXIT);
				}
				
			}
		}

		LeaveCriticalSection(&csClientList);
	}
	SetEvent(hServerEvent);             //通知主线程退出
	return 0;
}
void ExitSocket(SOCKET newSocket)
{ closesocket(newSocket); }