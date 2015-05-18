/*************************************************************************
	> File Name: ConcreteStrategyB.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 13 May 2015 09:47:03 PM CST
 ************************************************************************/

#ifndef CASH_CONCRETESTRATEGYB_H
#define CASH_CONCRETESTRATEGYB_H
#include "Strategy.h"

namespace Cash
{
class ConcreteStrategyB:public Strategy
{
public:
	ConcreteStrategyB(double l,double r):Strategy(l),rate(r)
	{}
	double  AlgorithmInterface();
	double GetRate()
	{
		return rate;
	}
private:
	double rate;
};
}
#endif
