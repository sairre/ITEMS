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
#include <cstddef>
int main(void)
{
	std::size_t i;
	std::map<std::string,std::size_t> wordcount;
	std::set<std::string> exclude={",",".","!","?"};
	std::cout<<"input a sentence "<<std::endl;
	std::string word;
	
	while(std::cin>>word)
	{
		if(word=="+")
			break;
		if(exclude.find(word)==exclude.end())
		{
			word[0]=tolower(word[0]);
			++wordcount[word];

		}
		
	}
	
	std::map<std::string,std::size_t>::iterator it=wordcount.begin();
	for(;it!=wordcount.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}
	


}
