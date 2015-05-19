/*************************************************************************
	> File Name: MyPoolThread.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 03:17:26 PM CST
 ************************************************************************/

#ifndef MYPOOLTHREAD_H
#define MYPOOLTHREAD_H
#include "Thread.h"
#include "ThreadPool.h"

class ThreadPool;

class MyPoolThread:public Thread
{
public:
	MyPoolThread(ThreadPool & threadpool):
		threadpool_(threadpool)
	{}
	void run();

private:
	ThreadPool & threadpool_;
};
#endif
