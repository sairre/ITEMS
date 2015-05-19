/*************************************************************************
	> File Name: ThreadPool.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 10:50:28 AM CST
 ************************************************************************/

#include "ThreadPool.h"

ThreadPool::ThreadPool(std::size_t bufSize,std::size_t threadsNum):
	buffer_(bufSize),
	threadsNum_(threadsNum),
	isStarting_(false)
{
	for(std::size_t idx=0;idx!=threadsNum_;++idx)
	{
		Thread * pThread =new MyPoolThread(*this);
		threadsVec_.push_back(pThread);
	}
}
void ThreadPool::start()
{
	std::vector<Thread *>::iterator it=threadsVec_.begin();
	for(;it!=threadsVec_.end();++it)
	{
		(*it)->start();
	}
	isStarting_=true;
}
void ThreadPool::stop()
{
	if(isStarting_)
	{
		while(!buffer_.empty())
			buffer_.deleteElement();
		std::vector<Thread *>::iterator it=threadsVec_.begin();
		for(;it!=threadsVec_.end();++it)
		{
			(*it)->join();
		}
		threadsVec_.clear();
	}
	isStarting_=false;
}
void ThreadPool::addTask(Task * pTask)
{
	buffer_.addElement(pTask);
}

Task * ThreadPool::getTask()
{
	Task *pTask=buffer_.deleteElement();
	return pTask;
}
void ThreadPool::runInThread()
{
	while(1)
	{
		Task *pTask=getTask();
		pTask->process();
	}
}
ThreadPool::~ThreadPool()
{
	stop();
}
























