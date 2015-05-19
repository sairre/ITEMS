/*************************************************************************
	> File Name: ThreadPool.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 10:45:48 AM CST
 ************************************************************************/

#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "Noncopyable.h"
#include "Buffer.h"
#include <vector>
#include "Thread.h"

class ThreadPool:private Noncopyable
{
public:
	ThreadPool(std::size_t bufSize,std::size_t threadsNum);
	~ThreadPool();

	void start();
	void stop();
	void addTask(Task * task);
	Task * getTask();
	void runInThread();

private:
	Buffer buffer_;
	std::size_t threadsNum_;
	std::vector<Thread *> threadsVec_;
	bool isStarting_;
};
