#include<iostream>
#include "lab1.h"
#include<algorithm>
#include<ctype.h>

using namespace std;

int main(int argc, char* argv[])
{	
	
	 char *str1;

	if(argc!=2)
	{
	cout<<"Please enter an input file :-";
	return 0;
	}
	
	str1=argv[1];
	FileReader reader;		//Instantiate class FileReader
	std::string s=reader.readFile(str1);//Call to function read
	
	WordCount word;			//Instantiate class word
	word.count(s);			//call to function count
	
return 0;	
}
