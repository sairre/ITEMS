#include "Tcp_NonBlock.h"
//int client()
//{
//	if (!InitClient())
//	{
//		ExitClient();
//		return CLIENT_SETUP_FALL;
//	}
//
//	//����server
//	if (ConnectServer())
//	{
//		ShowMsg("Connect to Server...");
//	} 
//	else
//	{
//		ShowMsg("Connect Fail!");
//		return CLIENT_SETUP_FALL;
//	}
//	//�������ͺͽ��������߳�
//	if (!CreateeSendAndRecvThread())
//	{
//		ExitClient();
//		return CLIENT_CREATETHREAD_FALL;
//	}
//	InputAndOutput();
//
//	ExitClient();
//	
//	return 0;
//}
HANDLE hThreadAccept;                 //���ܿͻ��������߳̾��
HANDLE hThreadHelp;                   //�ͷ���Դ�߳̾��
SOCKET serverSocket;                  //�����������׽���
BOOL bServerRunning;                  //�������Ĺ���״̬
HANDLE hServerEvent;                  //�������˳��¼�����
CLIENTLIST clientlist;                //�������ӵ�����
CRITICAL_SECTION csClientList;         //����������ٽ�������

int main(void)
{
	if (!InitServer())
	{
		ExitServer();
		return SERVER_SETUP_FALL;
	}

	if (!StartServerService())
	{
		ShowMsg("START SERVER FAILED!");
		ExitServer();
		return SERVER_SETUP_FALL;
	}

	StopService();

	ExitServer();

	return 0;

}