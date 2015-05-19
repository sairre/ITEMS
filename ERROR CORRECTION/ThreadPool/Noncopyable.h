/*************************************************************************
	> File Name: Noncopyable.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 11:16:27 AM CST
 ************************************************************************/

#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H
class Noncopyable
{
protected:
	Noncopyable()
	{}
	~Noncopyable()
	{}
private:
	Noncopyable(const Noncopyable &rhs);
	Noncopyable & operator=(const Noncopyable & rhs);
};
#endif
