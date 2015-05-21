/*************************************************************************
	> File Name: stream.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 20 May 2015 03:04:46 PM CST
 ************************************************************************/

#include<iostream>
#include <string>
#include <sstream>
int main(void)
{
	std::string str="hello word";
	std::stringstream ss;
	ss<<str<<"99999";
	str="we have a job";
	ss.clear();
	ss<<str;
	std::string s2;
	ss>>s2;
	std::cout<<s2<<std::endl;
	ss>>s2;
	std::cout<<s2<<std::endl;
	ss>>s2;
	std::cout<<s2<<std::endl;

	ss<<"..."<<23<<std::endl;
	ss.str("xxxxx");
	std::cout<<ss.str();
	ss.str();
	std::cout<<"///"<<std::endl;
	std::cout<<ss.str();
	std::ostringstream os;
	std::cout<<"......................."<<std::endl;
	std::string str2="lvhai";
	os<<str2;
	std::cout<<os.good()<<std::endl;
	
}
