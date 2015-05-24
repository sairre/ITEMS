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
//mis-judge words like XXX,BBB for XXXBBB
std::string cleanup_str(const std::string & word)
{
	std::string ret;
	for(auto it= word.begin();it!=word.end();++it)
		if(!ispunct(*it))
			ret+=tolower(*it);
	return ret;
}
void input_text(std::ifstream &is)            
{
	std::string text;
	while(getline(is,text))           //fetch each line once until 'is' gets ended
	{
		file.push_back(text);
		int no=file.size()-1;

		//break down  a line into words
		std::istringstream line(text);
		std::string word;
		while(line>>word)
		{
			wordMapNo[cleanup_str(word)].insert(no);
		}

	}
}

std::ostream & query_and_print(const std::string &sought,std::ostream &os)
{
	auto loc=wordMapNo.find(sought);
	if(loc==wordMapNo.end())
	{
		os<<sought<<" appear 0 time"<<std::endl;
	}
	else
	{
		auto lines=loc->second;
		os<<sought<<" appears"<<lines.size()<<" times"<<std::endl;
		for(auto num :lines)
		{
			os<<"\t"<<num+1<<"-th"<<"line"<<*(file.begin()+num)<<std::endl;
		}
	}
	return os;
}
void runQueries(std::ifstream & infile)
{
	input_text(infile);

	while(true)
	{
		std::cout<<"enter the word to look for ,or q to quit:"<<std::endl;
		std::string s;
		if(!(std::cin>>s)||s=="q")
			break;
		query_and_print(s,std::cout)<<std::endl;
	}
}
int main(void)
{
	std::ifstream infile;
	infile.open("b.txt");
	if(!infile.is_open())
	{
	
		std::cout<<"open failed"<<std::endl;
		exit(1);
	}
	runQueries(infile);

}
