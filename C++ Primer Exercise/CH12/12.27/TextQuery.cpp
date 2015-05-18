/*************************************************************************
	> File Name: TextQuery.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 04:24:31 PM CST
 ************************************************************************/

#include "TextQuery.h"
TextQuery::TextQuery()
{
	std::cout<<"textquery constructor"<<std::endl;
}
TextQuery::TextQuery(ifstream & infile):infile_(new vector<string>)
{
	std::stirng text;
	while(getline(cin,text))
	{
		infile_->
	}
}
