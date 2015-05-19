/*************************************************************************
	> File Name: main.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 10:44:25 AM CST
 ************************************************************************/

#include<iostream>
#include <unistd.h>
#include "ThreadPool.h"
#include "Task.h"
#include "MyTask.h"
int main(void)
{
	ThreadPool threadpool(5,10);
	threadpool.start();

	Task * pTask=new MyTask();
	
	while(1)
	{
		static int i=0;
		threadpool.addTask(pTask);
		sleep(5);
		std::cout<<"task"<<++i<<std::endl;

	}
	delete pTask;


	return 0;
}
