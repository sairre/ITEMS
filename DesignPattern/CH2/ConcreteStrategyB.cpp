/*************************************************************************
	> File Name: ConcreteStrategyB.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 13 May 2015 09:54:03 PM CST
 ************************************************************************/

#include "ConcreteStrategyB.h"
#include <iostream>
namespace Cash
{
double ConcreteStrategyB::AlgorithmInterface()
{
	std::cout<<"GetMOney():"<<GetMoney()<<std::endl;
	std::cout<<"rate:"<<rate<<std::endl;
	return GetMoney()*rate;
}
}
