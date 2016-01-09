#ifndef  TCPNONBLOCK_H
#define  TCPNONBLOCK_H
#include <WinSock2.h>
#include <windows.h>
#include <list>
#include <iostream>
#include <process.h>
#define TIMEFOR_THREAD_EXIT      5000
#define MAX_NUM_BUF              2048
#define SERVER_SETUP_FALL         1                            //启动服务器失败
#define CLIENT_SETUP_FALL         2                            //客户端创建失败
#define CLIENT_CREATETHREAD_FALL  3                            //创建线程失败
#pragma  comment(lib,"WS2_32")
#pragma  once
class CClient;
typedef std::list<CClient *> CLIENTLIST;

extern HANDLE hThreadAccept;                 //接受客户端连接线程句柄
extern HANDLE hThreadHelp;                   //释放资源线程句柄
extern SOCKET serverSocket;                  //服务器监听套接字
extern BOOL bServerRunning;                  //服务器的工作状态
extern HANDLE hServerEvent;                  //服务器退出事件对象
extern CLIENTLIST clientlist;                //管理连接的链表
extern CRITICAL_SECTION csClientList;         //保护链表的临界区对象

class CClient
{
public:
	CClient(const SOCKET clientSocket, const sockaddr_in &addrClient);
	virtual ~CClient();

public:
	BOOL StartRuning(void);
	void HandleData(const char * pExpr);
	BOOL IsConning(void)const{ return m_bConning; }
	void DisConning(void){ m_bConning = FALSE; }
	BOOL IsExit(void){ return m_bExit; }
public:
	static unsigned int WINAPI RecvDataThread(void * pParam);
	static unsigned int WINAPI SendDataThread(void * pParam);
private:
	CClient();
private:
	SOCKET m_socket;
	sockaddr_in m_addr;
	char RecvBuf[MAX_NUM_BUF];
	char SendBuf[MAX_NUM_BUF];
	HANDLE m_hEvent;
	HANDLE m_hThreadSend;
	HANDLE m_hThreadRecv;
	CRITICAL_SECTION m_cs;
	
	BOOL m_bConning;
	BOOL m_bExit;

};
bool InitServer(void);
void InitMember(void);
BOOL InitSocket(void);
bool InitWinDll(int minorVer = 2, int majorVer = 2);
SOCKET CreateSocket(void);
bool CreateServerSocket(void);
bool BindSocket(int port, char * ip);
bool ListenSocket(void);
bool AcceptSocket(void);
BOOL StartServerService(void);
BOOL CreateHelperAndAcceptThread(void);
void StopService(void);
void ExitServer(void);
void ShowSocketMsg(int ErrCode, const char * str);
void ShowMsg(const char * str);
void ExitSocket(SOCKET newSocket); 
unsigned int WINAPI AcceptThread(void * pParam);
unsigned int WINAPI HelperThread(void * pParam);

#endif