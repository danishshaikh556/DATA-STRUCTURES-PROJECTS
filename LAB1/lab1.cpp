#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#include<ctype.h>
#include"lab1.h"

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

void WordCount::count(string lowerString)
{
	map<string,int> listMap;
  	pair<map<string,int>::iterator,bool> returnValue;
	map<string,int>::iterator mapIterator;

	string subString;
	stringstream stringToken(lowerString);
	
	while(stringToken>>subString)				//extract only words from stream
	{		
	returnValue=listMap.insert (pair<string,int>(subString,1) );
	
	if (returnValue.second==false)		//check return value of insert
  	 {
		listMap[subString]++;			//count no. of times the key has occured	
		//cout<<listMap[subString]<<endl;
 		listMap.insert(pair<string,int>(subString,listMap[subString]));	//insert in map
	 } 
	
	}		
	for ( mapIterator=listMap.begin() ; mapIterator!= listMap.end(); mapIterator++ )			//print map contents
    	cout << (*mapIterator).first << " " << (*mapIterator).second << endl;	


	
}
