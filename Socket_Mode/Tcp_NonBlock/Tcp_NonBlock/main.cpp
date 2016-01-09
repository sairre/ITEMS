#include "Tcp_NonBlock.h"
//int client()
//{
//	if (!InitClient())
//	{
//		ExitClient();
//		return CLIENT_SETUP_FALL;
//	}
//
//	//连接server
//	if (ConnectServer())
//	{
//		ShowMsg("Connect to Server...");
//	} 
//	else
//	{
//		ShowMsg("Connect Fail!");
//		return CLIENT_SETUP_FALL;
//	}
//	//创建发送和接收数据线程
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
HANDLE hThreadAccept;                 //接受客户端连接线程句柄
HANDLE hThreadHelp;                   //释放资源线程句柄
SOCKET serverSocket;                  //服务器监听套接字
BOOL bServerRunning;                  //服务器的工作状态
HANDLE hServerEvent;                  //服务器退出事件对象
CLIENTLIST clientlist;                //管理连接的链表
CRITICAL_SECTION csClientList;         //保护链表的临界区对象

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