/*************************************************************************
	> File Name: main.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 10:44:25 AM CST
 ************************************************************************/

#include<iostream>
#include <unistd.h>
#include "MutexLock.h"
int main(void)
{
	MutexLock m;
	m.lock();
	sleep(4);
	m.unlock();
	return 0;
}
