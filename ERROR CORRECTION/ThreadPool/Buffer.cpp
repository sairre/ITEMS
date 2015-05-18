/*************************************************************************
	> File Name: Buffer.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 11:29:10 AM CST
 ************************************************************************/

#include "Buffer.h"
Buffer::Buffer(std::size_t size):
	mutex_(),
	notFull_(mutex_),
	notEmpty_(mutex_),
	size_(size)
{}

Buffer::~Buffer()
{}

void Buffer::addElement(Task * elem)
{
	MutexLockGuard mutexGurad(mutex_);
	while(size_==queue_.size())
		notFull_.wait();
	queue_.push(elem);
	notEmpty_.notify();
}
Task * Buffer::deleteElement()
{
	MutexLockGuard mutexGuard(mutex_);
	while(queue_.empty())
		notEmpty_.wait();
	Task * ptask=queue_.front();
	queue_.pop();
	notFull_.notify();
	return ptask;
}

bool Buffer::empty()
{
	MutexLockGuard mutexGuard(mutex_);
	return queue_.empty();
}
