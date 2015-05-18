/*************************************************************************
	> File Name: ConcreteStrategyA.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 13 May 2015 10:04:05 PM CST
 ************************************************************************/

#include "ConcreteStrategyA.h"
#include <iostream>
namespace Cash
{
double ConcreteStrategyA::AlgorithmInterface()
{
	std::cout<<"ConcreteStrategyA"<<std::endl;
	return GetMoney();
}
}
