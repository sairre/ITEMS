/*************************************************************************
	> File Name: Thread.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 02:43:00 PM CST
 ************************************************************************/

#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
#include "Noncopyable.h"
class Thread:private Noncopyable
{
public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
	virtual void run()=0;
	static void * runInThread(void *);
private:
	pthread_t pthId_;
	bool isRunning_;
};
#endif
