/*************************************************************************
	> File Name: OperationFactory.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sun 10 May 2015 11:22:59 PM CST
 ************************************************************************/

#include "OperationFactory.h"
namespace Cal
{
	 Operation * OperationFactory::CreateOper(std::string &str)
	{
		Operation * oper=NULL;
		if(str=="+")
			oper=new OperPlus();
		else if(str=="-")
			oper=new OperSub();
		else
			oper=new Operation();
		return oper;
	}
}
