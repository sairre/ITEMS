/*************************************************************************
	> File Name: iPhone.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 15 Jun 2015 10:34:38 PM CST
 ************************************************************************/

#include "Phone.h"
#include <iostream>
#ifndef CH_IPHONE_H
#define CH_IPHONE_H

namespace Ch
{
class iPhone:public Phone
{
public:	
	iPhone();
	iPhone(std::string str):m_name(str)
	{}
	~iPhone();
	void ShowDecoreate();
private:
	std::string m_name;
};
}
#endif
