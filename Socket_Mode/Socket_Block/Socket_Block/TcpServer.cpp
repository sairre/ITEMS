#include "TcpServer.h"

bool SocketBlock::TcpServer::InitMember(void)
{
	memset(bufRecv, 0, sizeof(bufRecv));
	memset(bufSend, 0, sizeof(bufSend));

	ServerSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;

	StatusConn = FALSE;
	return TRUE;
}
bool SocketBlock::TcpServer::InitWinDll(int minorVer /* = 2 */,int majorVer /* = 2 */ )
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(minorVer, majorVer);
	if (::WSAStartup(sockVersion, &wsaData) != 0)
	{
		ShowSocketMsg("Can't find a usable windows sockets dll");
		return FALSE;
	}
	if (LOBYTE(wsaData.wVersion) != minorVer || HIBYTE(wsaData.wVersion) != majorVer)
	{
		ShowSocketMsg("Can't find a usable windows sockets dll");
		return FALSE;
	}
	return TRUE;
}
bool SocketBlock::TcpServer::CreateServerSocket(void)
{
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == ServerSocket)
	{
		return HandleSocketError("Failed scoekt()!");
	}
	return TRUE;
}
bool SocketBlock::TcpServer::BindSocket(void)
{
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(SERVERPORT);
	addrServ.sin_addr.s_addr = INADDR_ANY;
	int ret = bind(ServerSocket,(const sockaddr *)&addrServ, sizeof(addrServ));
	if (SOCKET_ERROR == ret)
	{
		closesocket(ServerSocket);
		return HandleSocketError("Failed Bind()!");
	}
	return TRUE;
}
bool SocketBlock::TcpServer::ListenSocket(void)
{
	int ret = listen(ServerSocket, 100);
	if (SOCKET_ERROR == ret)
	{
		closesocket(ServerSocket);
		return HandleSocketError("Failed listen()!");
	}

	std::cout << "Server Starts Successfully!" << std::endl;
	std::cout << "Waiting For New Clients ..." << std::endl;

	return TRUE;
}
bool SocketBlock::TcpServer::AcceptSocekt(void)
{
	SOCKADDR_IN addrClient;
	int addrClientLen = sizeof(addrClient);
	ClientSocket = accept(ServerSocket, (sockaddr *)&addrClient, &addrClientLen);
	if (INVALID_SOCKET == ClientSocket)
	{
		closesocket(ServerSocket);
		return HandleSocketError("Failed accept()!");
	}
	else
	{
		StatusConn = TRUE;
	}
	char * pClientIp = inet_ntoa(addrClient.sin_addr);
	unsigned int clientPort = ntohs(addrClient.sin_port);
	std::cout << "Accept A Client:" << std::endl;
	std::cout << "IP:" << pClientIp << std::endl;
	std::cout << "Port:" << clientPort << std::endl;
	return TRUE;

}
bool SocketBlock::TcpServer::CreateSocket(void)
{
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == ServerSocket)
	{
		ShowErrorMsg();
		::WSACleanup();
		return FALSE;
	}
	return TRUE;
}
void SocketBlock::TcpServer::ShowErrorMsg(void)
{
	int nErrCode = WSAGetLastError();
	HLOCAL hlocal = NULL;

	//获取错误的文本字符串
	BOOL forMsg = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, \
		nErrCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),(LPWSTR)&hlocal,0,NULL);

	if (hlocal != NULL)
	{
		MessageBox(NULL, (LPCWSTR )LocalLock(hlocal),(LPCWSTR)"CLIENT ERROR", MB_OK);
		LocalFree(hlocal);
	}

}
bool SocketBlock::TcpServer::ReadDataThread(void)
{
	int nTotal = 0;         //n bytes have been read into buffer.
	int nRead = 0;          // n bytes received by "recv" function practically    
	int nLeft = 0;          // n bytes remaining to read
	int nBytes = 0;         // It is the postion that where the current data is 
	while (!ToQuit)
	{
		nTotal = 0;
		nLeft = NUM_TO_READ;
		while (nTotal != NUM_TO_READ)
		{
			nRead = recv(ClientSocket, &buff[nBytes], nLeft, 0);
			if (nRead == SOCKET_ERROR)
			{
				std::cout << "error" << std::endl;
				return FALSE;
			}
			nTotal += nRead;
			nLeft -= nRead;
			nBytes = nTotal;

		}

		SetEvent(hEvent);             //设置事件为有信号状态
		return TRUE;

	}
}	
bool SocketBlock::TcpServer::HandleDataThread(void)
{
	while (!ToQuit)
	{
		WaitForSingleObject(hEvent, INFINITE);
		HandleData(buff);
		return TRUE;
	}
	return FALSE;
}
bool SocketBlock::TcpServer::HandleData(const char * buff)
{

}
int SocketBlock::TcpServer::HandleSocketError(const char * str)
{
	ShowSocketMsg(str);
	WSACleanup();
	return FALSE;
}
void SocketBlock::TcpServer::ShowSocketMsg(const char * str)
{
	MessageBox(NULL, (LPCWSTR)str, L"ERROR", MB_OK);
}
