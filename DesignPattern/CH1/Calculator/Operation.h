/*************************************************************************
	> File Name: Operation.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 09 May 2015 10:58:22 PM CST
 ************************************************************************/

#ifndef CAL_OPERATION_H
#define CAL_OPERATION_H
#include <iostream>
#include <string>
#include "Noncopyable.h"
namespace Cal
{
class Operation:private Noncopyable
{
public:
	Operation();
	virtual ~Operation();
	void SetLeft(int);
	int GetLeft();
	void SetRight(int);
	int GetRight();
	void SetTot(int);
	int GetTot();
	virtual int MyOperator();
private:
	static int OperLeft;
	static int OperRight;
	static int OperTot;
};
}
#endif
