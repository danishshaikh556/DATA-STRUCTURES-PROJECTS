#include "wordcounts.h"
#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<sstream>
#include "filereader.h"
#include"rbtree.h"
#include<time.h>
#include <sys/time.h>

using namespace std;

int main(int argc, char* argv[])
{	
	timeval start,end;
	double difference,t1,t2;
	 char *str1;
	string str2;
	int cnt=1;
	int i=0;	
	if(argc!=2)
	{
	cout<<"Please enter an input file :-";
	return 0;
	}
	
	str1=argv[1];
	FileReader reader;		//Instantiate class FileReadermas
	std::string s=reader.readFile(str1);	//Call to function read
	
	WordCount word;			//Instantiate class word
	
	
	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	word.count(s);			//call to function count		
	
	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;

	//cout<<"Map time:"<<difference*1000000<<" microseconds"<<endl;
	
	Node* n;
	Tree* t = new Tree();
	stringstream str(s);
	
	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	
	while(str>>str2)
	{
		
				
		t->insert(pair<string,int>(str2,cnt));
		
	}
		
	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;

	//cout<<"Red Black Tree time:"<<difference*1000000<<" microseconds"<<endl;
	
	t->inorder(t->getRoot());
	//t->height(t->getRoot());
		
return 0;	
}
