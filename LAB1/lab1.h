#ifndef _MYHEADER_H_
#define _MYHEADER_H_
#include<iostream>
#include<string>
#include<algorithm>
#include<ctype.h>

using namespace std;
class FileReader
{
 public:	
	std::string readFile(char *);
	//friend class WordCount;
};


class WordCount
{
 public:
	void count(string);
};

#endif
