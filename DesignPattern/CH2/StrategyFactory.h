/*************************************************************************
	> File Name: StrategyFactory.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Thu 14 May 2015 09:12:03 PM CST
 ************************************************************************/

#ifndef CASH_STRATEGYFACTORY_H
#define CASH_STRATEGYFACTORY_H
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Strategy.h"
#include <iostream>
#include <string>
namespace Cash
{
class StrategyFactory
{
public:
	static Strategy * StrategyFactoryCreate(std::string str,double money,double rate=1);
};
}
#endif
