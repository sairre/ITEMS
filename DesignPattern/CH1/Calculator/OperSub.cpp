/*************************************************************************
	> File Name: OperSub.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sun 10 May 2015 11:09:23 PM CST
 ************************************************************************/

#include "OperSub.h"
namespace Cal
{
int OperSub::MyOperator(void)
{
	SetTot(GetLeft()-GetRight());
	return GetTot();
}
}
