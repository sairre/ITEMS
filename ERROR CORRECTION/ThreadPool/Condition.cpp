/*************************************************************************
	> File Name: Condition.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 10:54:30 AM CST
 ************************************************************************/

#include "Condition.h"
#include <iostream>
Condition::Condition(MutexLock & mutex):mutex_(mutex)
{
	pthread_cond_init(&cond_,NULL);
	std::cout<<"Condition pthread_cond_init(&cond_,NULL)"<<std::endl;
}
Condition::~Condition()
{
	pthread_cond_destroy(&cond_);
	std::cout<<"~Condition()"<<std::endl;
}
void Condition::wait()
{
	assert(mutex_.GetisLocking_());
	pthread_cond_wait(&cond_,mutex_.GetMutexPtr());
	std::cout<<"cond_ wait()"<<std::endl;
}
void Condition::notify()
{
	pthread_cond_signal(&cond_);
	std::cout<<"cond notify()"<<std::endl;
}
void Condition::notifyall()
{
	pthread_cond_broadcast(&cond_);
	std::cout<<"cond broadcast()"<<std::endl;
}

