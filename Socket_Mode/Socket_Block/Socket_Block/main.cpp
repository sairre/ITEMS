#include "TcpServer.h"
int main(void)
{
	SocketBlock::TcpServer server;
	server.InitWinDll();
	
	server.CreateServerSocket();
	server.BindSocket(3545,"127.0.0.1");
	server.ListenSocket();
	server.AcceptSocekt();
	std::string msg;
	while (true)
	{
//	server.RecvMsg(msg);
	std::cout << msg << std::endl;
	}
	

}