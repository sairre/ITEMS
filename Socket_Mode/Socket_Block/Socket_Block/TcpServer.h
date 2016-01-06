#ifndef TCPSERVER_H
#define TCPSERVER_H
#define  SERVERPORT 5678
#define NUM_TO_READ 1024
#define BUF_MAX_SIZE 2048
#define  SERVER_DLL_ERROR  1          // µ÷ÓÃwindows sockets dll Ê§°Ü
#include <tchar.h>
#include <iostream>
#include <windows.h>
HANDLE hEvent;
char  buff[BUF_MAX_SIZE];
bool   ToQuit;

namespace SocketBlock
{
	class TcpServer
	{
	public:
		bool InitMember(void);
		bool InitWinDll(int minorVer = 2,int majorVer = 2 );
		bool CreateServerSocket(void);
		bool BindSocket(void);
		bool ListenSocket(void);
		bool AcceptSocekt(void);
		bool CreateSocket(void);
		bool ReadDataThread(void);
		bool HandleDataThread(void);
		bool HandleData(const char * buff);
		int HandleSocketError(const char * str);
		void ShowErrorMsg(void);
		void ShowSocketMsg(const char * str);
		

	private:
		char bufRecv[BUF_MAX_SIZE];
		char bufSend[BUF_MAX_SIZE];
		SOCKET ServerSocket;
		SOCKET ClientSocket;
		bool StatusConn;
	};
}

#endif
