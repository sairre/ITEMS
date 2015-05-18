/*************************************************************************
	> File Name: ./Operation.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 09 May 2015 11:03:45 PM CST
 ************************************************************************/

#include "Operation.h"
 
namespace Cal
{
int Operation::OperLeft=0;
int Operation::OperRight=0;
int Operation ::OperTot=0;
Operation::Operation()
{
	std::cout<<"default constructor"<<std::endl;
	
}
Operation::~Operation()
{
	std::cout<<"~Operation"<<std::endl;
}
void Operation::SetLeft(int Left)
{
	std::cout<<"SetLeft"<<std::endl;
	OperLeft=Left;
}
int Operation::GetLeft(void)
{
	return OperLeft;
}
void Operation::SetRight(int Right)
{
	std::cout<<"SetRight"<<std::endl;
	OperRight=Right;
}
int Operation::GetRight(void)
{
	return OperRight;
}
void Operation::SetTot(int Tot)
{
	OperTot=Tot;
}
int Operation::GetTot(void)
{
	return OperTot;
}
int  Operation::MyOperator()
{
	std::cout<<"default abastrct opertor"<<std::endl;
}
}
