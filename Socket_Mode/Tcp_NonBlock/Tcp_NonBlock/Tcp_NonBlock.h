#ifndef  TCPNONBLOCK_H
#define  TCPNONBLOCK_H
#include <WinSock2.h>
#include <windows.h>
#include <list>
#include <iostream>
#include <process.h>
#define TIMEFOR_THREAD_EXIT      5000
#define MAX_NUM_BUF              2048
#define SERVER_SETUP_FALL         1                            //����������ʧ��
#define CLIENT_SETUP_FALL         2                            //�ͻ��˴���ʧ��
#define CLIENT_CREATETHREAD_FALL  3                            //�����߳�ʧ��
#pragma  comment(lib,"WS2_32")
#pragma  once
class CClient;
typedef std::list<CClient *> CLIENTLIST;

extern HANDLE hThreadAccept;                 //���ܿͻ��������߳̾��
extern HANDLE hThreadHelp;                   //�ͷ���Դ�߳̾��
extern SOCKET serverSocket;                  //�����������׽���
extern BOOL bServerRunning;                  //�������Ĺ���״̬
extern HANDLE hServerEvent;                  //�������˳��¼�����
extern CLIENTLIST clientlist;                //�������ӵ�����
extern CRITICAL_SECTION csClientList;         //����������ٽ�������

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