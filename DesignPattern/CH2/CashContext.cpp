/*************************************************************************
	> File Name: CashContext.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Thu 14 May 2015 02:42:17 PM CST
 ************************************************************************/

#include "CashContext.h"

namespace Cash
{
	CashContext::CashContext()
	{}
	CashContext::CashContext(Strategy * pstrategy_):pstrategy(pstrategy_)
	{
		//warning
	}
	double CashContext::SetCashContext()
	{
		return pstrategy->AlgorithmInterface();
	}
	Strategy * CashContext::GetStrategy()
	{
		return pstrategy;
	}
}
