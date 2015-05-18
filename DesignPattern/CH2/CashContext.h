/*************************************************************************
	> File Name: CashContext.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 13 May 2015 10:09:10 PM CST
 ************************************************************************/

#ifndef CASH_CASHCONTEXT_H
#define CASH_CASHCONTEXT_H
#include "Strategy.h"
namespace Cash
{
class CashContext
{
public:
	CashContext();
	CashContext(Strategy * pstrategy);
	double SetCashContext();
	Strategy * GetStrategy();
private:
	Strategy * pstrategy;
};
}
#endif
