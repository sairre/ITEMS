/*************************************************************************
	> File Name: 8.4.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Thu 21 May 2015 04:08:32 PM CST
 ************************************************************************/

#include<iostream>
#include <fstream>
#include <string>
#include <vector>
int main(void)
{
	std::ifstream in("data");
	if(!in)
	{
		std::cerr<<"open in fail"<<std::endl;
		return -1;
	}
	std::string line;
	std::vector<std::string> words;
	while(getline(in,line))
//	while(in>>line)
	{
		words.push_back(line);
	}
	in.close();
	std::vector<std::string>::const_iterator it=words.begin();
	while(it!=words.end())
	{
		std::cout<<*it<<std::endl;
		++it;
	}
}
