#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#include<ctype.h>
#include"filereader.h"

using namespace std;

std::string FileReader::readFile(char *str1)
{
	
string getFileContents,newString;
int i=0;	
std::string withoutSpecial;
stringstream final;

fstream fileRead(str1);	
while(!fileRead.eof())		//read file contents
	{	
	 getline(fileRead,getFileContents);	 
	 newString.append(" ");
	 newString.append(getFileContents);
	}
	fileRead.close();
		
	std::string lowerString(newString); 			//Convert to lower case
	std::transform(lowerString.begin(), lowerString.end(), lowerString.begin(), ::tolower);
	
	for(i=0;i<lowerString.length();i++)				//Remove special characters and punctuation
	{
		if((isalnum(lowerString[i]))||(lowerString[i]==' '))
			{
				withoutSpecial=lowerString[i];
				final<<withoutSpecial;
			}		
       
	}
	
return final.str();	
}

