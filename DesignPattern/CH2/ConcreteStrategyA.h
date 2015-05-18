/*************************************************************************
	> File Name: ConcreteStrategyA.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 13 May 2015 10:04:11 PM CST
 ************************************************************************/

#ifndef CASH_CONRETESTRATEGYA_H
#define CASH_CONCRETESTRATEGYA_H
#include "Strategy.h"

namespace Cash
{
class ConcreteStrategyA:public Strategy
{
public:
	ConcreteStrategyA(double money):Strategy(money)
	{}
	double AlgorithmInterface();
};
}
#endif
