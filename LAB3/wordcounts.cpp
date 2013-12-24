#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#include<ctype.h>
#include"wordcounts.h"

using namespace std;

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
	//for ( mapIterator=listMap.begin() ; mapIterator!= listMap.end(); mapIterator++ )			//print map contents
    //	cout << (*mapIterator).first << " " << (*mapIterator).second << endl;	


	
}
