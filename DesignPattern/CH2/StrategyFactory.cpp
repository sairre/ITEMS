/*************************************************************************
	> File Name: StrategyFactory.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Thu 14 May 2015 09:19:02 PM CST
 ************************************************************************/

#include "StrategyFactory.h"

namespace Cash
{
Strategy * StrategyFactory::StrategyFactoryCreate(std::string str,double money,double rate)
{
	Strategy *pstrategy=NULL;
	if(str=="normal")
		pstrategy=new ConcreteStrategyA(money);
	if(str=="discount")
		pstrategy=new ConcreteStrategyB(money,rate);

	return pstrategy;
	
}
}
