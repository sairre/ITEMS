/*************************************************************************
	> File Name: map.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 04:40:16 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
#include <string>
int main(void)
{
	std::map<std::string,int> m;
	m["any"]=1;
	m["pity"]=2;
	m["dong"]=1;

	//use iterator and first ,second
	std::map<std::string,int>::iterator p=m.begin();
	std::cout<<p->first<<std::endl;
	std::cout<<p->second<<std::endl;

	//use count
	std::cout<<m.count("any")<<std::endl;
}
