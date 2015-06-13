/*************************************************************************
	> File Name: Phone.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 16 May 2015 10:33:24 PM CST
 ************************************************************************/

#include "Phone.h"
#include <iostream>
namespace Ch
{
	Phone::Phone()
	{
		std::cout<<"Phone constructor"<<std::endl;
	}
	Phone::~Phone()
	{
		std::cout<<"Phone destory"<<std::endl;
	}
	Phone::ShowDecoreate()
	{
		std::cout<<"default virtual ShowDecoreate";
	}
}
