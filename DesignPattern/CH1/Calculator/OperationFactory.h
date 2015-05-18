/*************************************************************************
	> File Name: OperationFactory.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sun 10 May 2015 11:18:32 PM CST
 ************************************************************************/

#ifndef CAL_OPERATIONFACTORY_H
#define CAL_OPERATIONFACTORY_H
#include "OperPlus.h"
#include "OperSub.h"
#include <string>
namespace Cal
{
class OperationFactory
{
public:
	static Operation * CreateOper(std::string &str);
};
}
#endif
