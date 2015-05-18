/*************************************************************************
	> File Name: Condition.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 10:49:31 AM CST
 ************************************************************************/

#ifndef CONDITION_H
#define CONDITION_H

#include "MutexLock.h"
#include <pthread.h>
#include <assert.h>
//class MutexLock;
class Condition
{
public:
	Condition(MutexLock & mutex);
	~Condition();
	void wait();
	void notify();
	void notifyall();

private:
	pthread_cond_t cond_;
	MutexLock & mutex_;
};
#endif

