/*************************************************************************
	> File Name: client.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Thu 14 May 2015 09:33:21 PM CST
 ************************************************************************/

#include<iostream>
#include "StrategyFactory.h"
#include "Strategy.h"
#include "CashContext.h"
using namespace Cash;
int main(void)
{
	CashContext cc(StrategyFactory::StrategyFactoryCreate("discount",234.3,0.5));
	std::cout<<cc.SetCashContext()<<std::endl;
}
