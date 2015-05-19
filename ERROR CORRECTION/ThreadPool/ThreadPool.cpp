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
		Thread * pThread =new MypoolThread(*this);
		threadsVec_.push_back(pThread);
	}
}
void ThreadPool::start()
{
	std::vector<Thread *>::iterator it=threadsVec_.begin();
}


