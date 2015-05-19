/*************************************************************************
	> File Name: wordCount.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 05:24:51 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
#include <string>
#include <set>
int main(void)
{
	std::map<std::string,int> wordcount;
	std::set<std::string> exclude={",",".","!","?"};
	std::cout<<"input a sentence "<<std::endl;
	std::string word;
	while(std::cin>>word)
	{
		if(word=="+++")
			break;
		if(exclude.find(word)==exclude.end())
			++wordcount[word];
	}
	std::map<std::string,int>::iterator it=wordcount.begin();
	for(;it!=wordcount.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}


}
