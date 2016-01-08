#ifndef TCPSERVER_H
#define TCPSERVER_H
#define  SERVERPORT 4567
#define NUM_TO_READ 1024
#define BUF_MAX_SIZE 2048
#define  SERVER_DLL_ERROR  1          // call windows sockets dll failed
#include <tchar.h>
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <windows.h>

#pragma comment(lib, "WS2_32")
//HANDLE hEvent;
//char  buff[BUF_MAX_SIZE];
//bool   ToQuit;

namespace SocketBlock
{
	class Socket
	{
	public:
		Socket();
		~Socket();
		bool InitWinDll(int minorVer = 2, int majorVer = 2);
		SOCKET CreateSocket(void);
		int RecvMsg(SOCKET RecvSocket,SOCKET SendSocket,std::string & msg);
		int SendMsg(SOCKET RecvSocket,SOCKET SendSocket, std::string & msg);
		void ShowSocketMsg(int ErrCode,const char * str);
		void ShowMsg(const char * str);
		bool GetConStatus()const{ return statusConn; }
		void SetConStatus(bool conn) { statusConn = conn; }
		void ExitSocket(SOCKET newSocket){ closesocket(newSocket); }

	private:
		char bufRecv[BUF_MAX_SIZE];
		char bufSend[BUF_MAX_SIZE];
		bool statusConn;
		
	};
	class TcpServer:public Socket
	{
	public:
		
		
		bool CreateServerSocket(void);
		bool BindSocket(int port,char * ip);
		bool ListenSocket(void);
		bool AcceptSocekt(void);
		
		void ServerRecvMsg(std::string & msg);
		void ServerSendMsg(std::string & msg);
		bool ExitClient(void);
		
		bool ReadDataThread(void);
		bool HandleDataThread(void);
		bool HandleData(const char * buff);
		int HandleSocketError(const char * str);
		void ShowErrorMsg(void);
	private:
		
		SOCKET serverSocket;
		SOCKET clientSocket;
		
	};
	
	class TcpClient :public Socket
	{
	public:
		bool CreateClientSocket(void);
		bool ConnectToServe(int port,char * ip);

		void ServerRecvMsg(std::string & msg);
		void ServerSendMsg(std::string & msg);
		bool ExitClient(void);
	private:
		SOCKET serverSocket;
		SOCKET clientSocket;

	};
}

#endif
