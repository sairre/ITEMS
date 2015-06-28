/*************************************************************************
	> File Name: client.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 16 Jun 2015 09:25:03 AM CST
 ************************************************************************/

#include <iostream>
#include "Phone.h"
#include "iPhone.h"
#include "NokiaPhone.h"
using namespace Ch;
int main(void)
{
Phone * myphone=new NokiaPhone("mi");
myphone->ShowDecoreate();

delete myphone;

}
