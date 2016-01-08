#include "TcpServer.h"

SocketBlock::Socket::Socket() :statusConn(FALSE)
{
	memset(bufRecv, 0, sizeof(bufRecv));
	memset(bufSend, 0, sizeof(bufSend));
	InitWinDll(2, 2);
}
SocketBlock::Socket::~Socket()
{
	WSACleanup();
}
bool SocketBlock::Socket::InitWinDll(int minorVer /* = 2 */,int majorVer /* = 2 */ )
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
bool SocketBlock::TcpServer::CreateServerSocket(void)
{
	serverSocket = CreateSocket();
	return TRUE;
}
bool SocketBlock::TcpServer::BindSocket(int port,char * ip)
{
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(port);
	addrServ.sin_addr.s_addr = inet_addr(ip);
	int ret = bind(serverSocket,(const sockaddr *)&addrServ, sizeof(addrServ));
	if (SOCKET_ERROR == ret)
	{

		int ErrCode = WSAGetLastError();
		ExitSocket(serverSocket);
		ShowSocketMsg(ErrCode,"Bind Failed!");
		return FALSE;
	}
	return TRUE;
}
bool SocketBlock::TcpServer::ListenSocket(void)
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
bool SocketBlock::TcpServer::AcceptSocekt(void)
{
	SOCKADDR_IN addrClient;
	int addrClientLen = sizeof(addrClient);
	clientSocket = accept(serverSocket, (sockaddr *)&addrClient, &addrClientLen);
	if (INVALID_SOCKET == clientSocket)
	{
		int ErrCode = WSAGetLastError();
		ExitSocket(serverSocket);
		ShowSocketMsg(ErrCode, "Accept Failed !");
		return FALSE;
	}
	else
	{
		SetConStatus(TRUE);
		
	}
	char * pClientIp = inet_ntoa(addrClient.sin_addr);
	unsigned int clientPort = ntohs(addrClient.sin_port);
	ShowMsg("Accept A Client !");
	return TRUE;

}
void SocketBlock::TcpServer::ServerRecvMsg(std::string & msg)
{
	RecvMsg(clientSocket, serverSocket, msg);
}
void SocketBlock::TcpServer::ServerSendMsg(std::string & msg)
{
	SendMsg(clientSocket, serverSocket, msg);
}
int SocketBlock::Socket::RecvMsg(SOCKET RecvSocket, SOCKET SendSocket, std::string & msg)
{
	int nRecvLen = 0;          //n bytes received practically once
	int nDataLen = 0;		   //Data full length;
	int nTotData = 0;         // n bytes received practically  in total
	int ErrCode = 0;
	if (statusConn)
	{
		memset(bufRecv, 0, sizeof(bufRecv));
		nRecvLen = recv(SendSocket, ( char *)&nDataLen, 4, 0);
	//	nDataLen = (int)bufRecv;
		if (SOCKET_ERROR == nRecvLen)
		{
			ErrCode = WSAGetLastError();
			ShowSocketMsg(ErrCode, "ServerSocket:Receive header msg failed");
			SetConStatus(FALSE);
			return SOCKET_ERROR;
		}
		else if (0 == nRecvLen)
		{
			ShowMsg("ServerSocket:ClientSocket has been closed");
			SetConStatus(FALSE);
			return 0;
		}
		nRecvLen = 0;
		memset(bufRecv, 0, sizeof(bufRecv));
	}
	while (statusConn && (nTotData < nDataLen))
	{
		nRecvLen = recv(SendSocket, bufRecv + nTotData, nDataLen - nTotData, 0);
		if (SOCKET_ERROR == nRecvLen)
		{
			ErrCode = WSAGetLastError();
			ShowSocketMsg(ErrCode,"ServerSocket:Receive  msg failed");
			SetConStatus(FALSE);
			return SOCKET_ERROR;
		}
		else if (0 == nRecvLen)
		{
			ShowMsg("ServerSocket:ClientSocket has been closed");
			SetConStatus(FALSE);
			return 0;
		}
		nTotData += nRecvLen;

	}
	msg = bufRecv;
	return nRecvLen;
	
}
int SocketBlock::Socket::SendMsg(SOCKET RecvSocket, SOCKET SendSocket, std::string & msg)
{
	int nSendLen = 0;
	int nTotData = 0;
	int nDataLen = msg.length();
	int ErrCode = 0;

	memset(bufSend, 0, sizeof(bufSend));

	if (statusConn)
	{
		
		nSendLen = send(RecvSocket, (const char *)(&nDataLen), 4, 0);
		
		if (SOCKET_ERROR == nSendLen)
		{
			ErrCode = WSAGetLastError();
			ShowSocketMsg(ErrCode,"ClientSocket:Send header msg failed");
			SetConStatus(FALSE);
			return SOCKET_ERROR;
		}
	
		nSendLen = 0;
	}
	while (statusConn && (nTotData < nDataLen))
	{
		nSendLen = send(RecvSocket, msg.c_str() + nTotData, msg.length() - nTotData, 0);
		if (SOCKET_ERROR == nSendLen)
		{
			ErrCode = WSAGetLastError();
			ShowSocketMsg(ErrCode, "ClientSocket:Send  msg failed");
			SetConStatus(FALSE);
			return SOCKET_ERROR;
		}
		
		nTotData += nSendLen;

	}
	
	return nTotData;


}
SOCKET SocketBlock::Socket::CreateSocket(void)
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

/*
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
*/
/*
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
*/


void SocketBlock::Socket::ShowSocketMsg(int ErrCode,const char * str)
{
	//Determine the way show the msg according to your need.As follows is a sample.
	std::cerr << "ErrCode :" << ErrCode << " " << str << std::endl;
}
void SocketBlock::Socket::ShowMsg(const char * str)
{
	//Determine the way show the msg according to your need.As follows is a sample.
	std::cout << str << std::endl;
}
bool SocketBlock::TcpClient::CreateClientSocket(void)
{
	clientSocket = CreateSocket();
	return TRUE;
}
bool SocketBlock::TcpClient::ConnectToServe(int port, char * ip)
{
	SOCKADDR_IN addrClient;
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(port);
	addrClient.sin_addr.s_addr = inet_addr(ip);
	
	int ret = connect(clientSocket, (const sockaddr *)&addrClient, sizeof(addrClient));
	if (SOCKET_ERROR == ret)
	{
		int ErrCode = WSAGetLastError();
		ShowSocketMsg(ErrCode, "ClientSocket:Connect failed");
		SetConStatus(FALSE);
		return FALSE;
	}
	SetConStatus(TRUE);
	return TRUE;

}
