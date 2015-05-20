/*************************************************************************
	> File Name: homemap.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 19 May 2015 10:50:02 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
int main(void)
{
	std::ifstream infile("./a.txt");
	if(!infile)
	{
		std::cout<<"open fail"<<std::endl;
		exit(1);
	}
	std::map<std::string,std::vector<std::string> > homemap;
	std::string line;
	while(getline(infile,line))
	{
		std::istringstream line_(line);
		std::string word;
		std::string first_name;
		line_>>first_name;

		while(line_>>word)
		{
			homemap[first_name].push_back(word);
		}
	}
	std::map<std::string,std::vector<std::string> >::iterator it=homemap.begin();
	std::cout<<it->first<<std::endl;
	std::vector<std::string>::iterator vit=(it->second).begin();
	std::vector<std::string>::iterator vend=(it->second).end();
	for(;vit!=vend;vit++)
		std::cout<<*vit<<std::endl;


	std::cout<<"input some information about new families"<<std::endl;







	

}
