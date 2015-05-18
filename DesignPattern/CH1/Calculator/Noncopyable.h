/*************************************************************************
	> File Name: Noncopyable.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 09 May 2015 11:31:23 AM CST
 ************************************************************************/

#ifndef CAL_NONCOPYABLE_H
#define CAL_NONCOPYABLE_H
namespace Cal
{
class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &rhs);
	Noncopyable & operator=(const Noncopyable &rhs);
};
}
#endif
