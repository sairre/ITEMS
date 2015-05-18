/*************************************************************************
	> File Name: Strategy.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 13 May 2015 09:30:52 PM CST
 ************************************************************************/

#ifndef CASH_STRATEGY_H
#define CASH_STRATEGY_H

namespace Cash
{
class Strategy
{
public:
	//explicit
	Strategy()
	{}
	Strategy(double val):money(val)
	{}
	virtual double AlgorithmInterface();
	double GetMoney()
	{
		return money;
	}
private:
    double money;
};
}
#endif
