/*************************************************************************
	> File Name: MutexLock.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 10:26:07 AM CST
 ************************************************************************/

#include "MutexLock.h"
#include <iostream>
MutexLock::MutexLock():isLocking_(false)
{
	pthread_mutex_init(&mutex_,NULL);
	std::cout<<"MutexLock(),pthread_mutex_init(&mutex_,NULL)"<<std::endl;
}
MutexLock::~MutexLock()
{
	std::cout<<"~MutexLock()"<<std::endl;
	pthread_mutex_destroy(&mutex_);
}
void MutexLock::lock()
{
	pthread_mutex_lock(&mutex_);
	isLocking_=true;
	std::cout<<"lock()"<<std::endl;
}
void MutexLock::unlock()
{
	pthread_mutex_unlock(&mutex_);
	isLocking_=false;
	std::cout<<"unlock()"<<std::endl;
}
bool MutexLock::GetisLocking_()
{
	return isLocking_;
}
pthread_mutex_t * MutexLock::GetMutexPtr()
{
	return &mutex_;
}
void MutexLock::SetisLocking_(bool val)
{
	isLocking_=val;
}


