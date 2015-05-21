/*************************************************************************
	> File Name: istream.cpp
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Wed 20 May 2015 08:16:01 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <istream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
std::istream & fun(std::istream & in)
{
	int v;
	while(in>>v,!in.eof())
	{
		if(in.bad())
		{
		//	throw_runtime_error("IO streamline error");
			std::cout<<"IO streamline error"<<std::endl;
		}
		if(in.fail())
		{
			std::cout<<"data error,try again"<<std::endl;
			in.clear();
			in.ignore(100,'\n');
			continue;
		}
		std::cout<<v<<std::endl;

	}
	in.clear();
	return in;
}
int main(void)
{
//	std::cout<<"input some intergers"<<std::endl;
//	fun(std::cin);	
	std::ifstream input("./a.txt");
	std::ofstream output;
	if(!input)
	{
		std::cout<<"open fail"<<std::endl;
	}
	output.open("b.txt");
	if(!output)
	{
		std::cout<<"output fail"<<std::endl;
		exit(1);
	}
	char  line[1024];
	std::cout<<" ...."<<std::endl;
	memset(line,0,sizeof(line));
	input.read(line,1024);
	
		std::cout<<"/////////"<<std::endl;
		std::string str(line);
		std::cout<<str<<std::endl;
		output.write(line,1024);
		memset(line,0,sizeof(line));
	
	input.close();
	output.close();

	

}
