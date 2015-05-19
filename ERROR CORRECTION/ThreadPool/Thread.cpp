/*************************************************************************
	> File Name: Thread.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 02:47:07 PM CST
 ************************************************************************/

#include "Thread.h"
Thread::Thread()
	:pthId_(0),
	isRunning_(false)
{}
Thread::~Thread()
{
	pthread_detach(pthId_);
}
void Thread::start()
{
	pthread_create(&pthId_,NULL,runInThread,this);
	isRunning_=true;
}
void Thread::join()
{
	pthread_join(pthId_,NULL);
	isRunning_=false;
}
void * Thread::runInThread(void * arg)
{
	Thread * pThread=static_cast<Thread *>(arg);
	pThread->run();

	return NULL;
}

