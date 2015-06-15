/*************************************************************************
	> File Name: NokiaPhone.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 13 Jun 2015 11:11:25 AM CST
 ************************************************************************/
#ifndef CH_PHONE_H
#define CH_PHONE_H
#include <string>
#include <iostream>
#include "Phone.h"
namespace Ch
{
class NokiaPhone:Public Phone
{
public:	
	NokiaPhone();
	NokiaPhone(std::string str):m_name(str)
	{}

	~NokiaPhone();
	void ShowDecoreate();
private:
	std::string m_name;
};
}
