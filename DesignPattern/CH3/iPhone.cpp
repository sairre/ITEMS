/*************************************************************************
	> File Name: iPhone.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 15 Jun 2015 10:39:00 PM CST
 ************************************************************************/

#include "iPhone.h"
namespace Ch
{
iPhone::iPhone()
{
	std::cout<<"default iPhone constructor"<<std::endl;

}
iPhone::~iPhone()
{
	std::cout<<m_name<<" destroty"<<std::endl;
}
void iPhone::ShowDecoreate()
{
	std::cout<<m_name<<"ShowDecoreate destroy"<<std::endl;
}
}
