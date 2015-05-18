/*************************************************************************
	> File Name: MutexLock.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 10:17:15 AM CST
 ************************************************************************/

#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H
#include <pthread.h>
class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	bool GetisLocking_();
	void SetisLocking_(bool );
	pthread_mutex_t * GetMutexPtr();
private:
	pthread_mutex_t mutex_;
	bool isLocking_;
};
#endif
