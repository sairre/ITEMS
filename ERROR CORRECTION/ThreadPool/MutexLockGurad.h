/*************************************************************************
	> File Name: MutexLockGurad.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 11:35:22 AM CST
 ************************************************************************/

#ifndef MUTEXLOCKGURAD_H
#define MUTEXLOCKGURAD_H
#include "MutexLock.h"
class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex):mutex_(mutex)
	{
		mutex_.lock();
	}
	~MutexLockGuard()
	{
		mutex_.unlock();
	}
private:
	MutexLock & mutex_;
};
#endif

