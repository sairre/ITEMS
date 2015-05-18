/*************************************************************************
	> File Name: TextQuery.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Mon 18 May 2015 04:22:56 PM CST
 ************************************************************************/

#ifndef TEXTQUERY_H
#define TEXTQEURY_H
#include <ifstream>
#include <string>
class TextQuery
{
public:
	TextQuery();
	TextQuery(ifstream &);
private:
	std::shared_ptr<std::vector<std::string>> infilePtr_;
	std::map<std::string,std::shared_ptr<std::set<line_no>>> wordMap;
};
#endif
