/*************************************************************************
	> File Name: Buffer.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 11:14:17 AM CST
 ************************************************************************/

#ifndef BUFFER_H
#define BUFFER_H
#include "Task.h"
#include "Condition.h"
#include "MutexLock.h"
#include "MutexLockGuard.h"
#include "Noncopyable.h"
#include <cstddef>
#include <queue>
class Buffer:private Noncopyable
{
public:
	Buffer(std::size_t size);
	~Buffer();
	void addElement(Task * elem);
	Task * deleteElement();
	bool empty();
private:
		MutexLock mutex_;
		Condition notFull_;
		Condition notEmpty_;
		std::size_t size_;
		std::queue<Task *> queue_;
};
#endif
