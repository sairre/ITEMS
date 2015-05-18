/*************************************************************************
	> File Name: OperPlus.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 09 May 2015 11:19:59 PM CST
 ************************************************************************/

#include "OperPlus.h"
namespace Cal
{
int OperPlus::MyOperator(void)
{
	SetTot(GetLeft()+GetRight());
	return GetTot();
}
}
