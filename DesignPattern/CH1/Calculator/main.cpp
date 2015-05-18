/*************************************************************************
	> File Name: main.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sun 10 May 2015 09:02:53 PM CST
 ************************************************************************/

#include "OperationFactory.h"
int main(void)
{
	using namespace Cal;

	std::string str;
	Operation * oper=OperationFactory::CreateOper(str);
	int val;
	std::cin>>val;
	oper->SetLeft(val);
	std::cin>>str;
	oper=OperationFactory::CreateOper(str);
	
	

	std::cin>>val;
	oper->SetRight(val);
	oper->MyOperator();
	std::cout<<oper->GetTot()<<std::endl;
}
