/*************************************************************************
	> File Name: NokiaPhone.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Sat 13 Jun 2015 11:32:23 AM CST
 ************************************************************************/
#include "NokiaPhone.h"
namespace Ch
{
NokiaPhone::NokiaPhone()
{
std::cout<<"default NokiaPhone constructor"<<std::endl;
}
NokiaPhone::~NokiaPhone()
{
	std::cout<<"default NokiaPhone destroy"<<std::endl;
}
void NokiaPhone::ShowDecoreate()
{
	std::cout<<"NokiaPhone"<<m_name<<" ShowDecoreate "<<std::endl;
}
}
