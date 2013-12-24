#include<iostream>
#include"graph.h"

using namespace std;

int main(int argc, char* argv[])
{
	
	FileReader reader;
	char* str1;	
	if(argc!=2)
	{
	cout<<"Please enter an input file :-";
	return 0;
	}
	
	str1=argv[1];
	reader.readFile(str1);
			
	
}                     
