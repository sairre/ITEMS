/*************************************************************************
	> File Name: MyPoolThread.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 03:20:56 PM CST
 ************************************************************************/

#include "MyPoolThread.h"
void MyPoolThread::run()
{
	threadpool_.runInThread();
}
