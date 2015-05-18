/*************************************************************************
	> File Name: fileQuery.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 04:49:11 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctype.h>
using line_no=std::vector<std::string>::size_type;
std::vector<std::string> file;       //to store the whole file 
std::map<std::string,std::set<line_no>> wordMapNo;

//return string without dots nor blank
std::string cleanup_str(const std::string & word)
{
	std::string ret;
	for(auto it= word.begin();it!=word.end();++it)
		if(!ispunct(*it))
			ret+=tolower(*it);
	return ret;
}
void input_text(ifstream &is)            
{
	std::string text;
	while(getline(is,text))           //fetch each line once until 'is' gets ended
	{
		file.push_back(text);
		int no=file.size()-1;

		//break down  a line into words
		istringstream line(text);
		std::string word;
		while(line>>word)
		{
			wordMapNo[cleanup_str[word]].insert(no);
		}

	}
}

ostream & query_and_print(const std::string &sought,ostream &os)
{
	auto loc=wordMapNo.find(sought);
	if(loc==wordMapNo.end())
	{
		os<<sought<<" appear 0 time"<<std::endl;
	}
	else
	{
		auto lno=loc->second;
		os<<sought<<" appears"<<lin
	}
}
