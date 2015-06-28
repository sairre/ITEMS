/*************************************************************************
	> File Name: NokiaPhone.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 13 Jun 2015 11:11:25 AM CST
 ************************************************************************/
#ifndef CH_NOKIAPHONE_H
#define CH_NOKIAPHONE_H
#include <string>
#include <iostream>
#include "Phone.h"
namespace Ch
{
class NokiaPhone:public Phone
{
public:	
	NokiaPhone();
	NokiaPhone(std::string str):m_name(str)
	{
		std::cout<<"NokiaPhone copy constructor"<<std::endl;
	}

	~NokiaPhone();
	void ShowDecoreate();
private:
	std::string m_name;
};
}
#endif
