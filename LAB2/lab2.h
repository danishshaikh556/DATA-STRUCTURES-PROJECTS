#ifndef _MYHEADER_H_
#define _MYHEADER_H_
#include<iostream>
#include<string>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

class FileReader
{
 public:	
	std::string readFile(char *);
	friend class WordCount;
};


class WordCount
{
	
 public:
 	vector<pair<string,int> > final;		
	vector<pair<string,int> > count(string);
	
	vector <pair <string,int> >  insertionSortByValue(vector <pair <string,int> > &);
	vector<pair<string,int> > insertionSortByKey(vector <pair <string,int> > &);
	

	void maxHeapify(vector<pair<string,int> > &, int, int); 
	vector<pair<string,int> >HeapSort(vector<pair<string,int> > &);
		
	void maxHeapifyValue(vector<pair<string,int> >&,int,int);
	int buildMaxHeapValue(vector<pair<string,int> >&);
	vector<pair<string,int> > heapSortValue(vector<pair<string,int> >&);
	
	void quickSortByValue(int,int);
	int partition(int,int);
	
	void quickSortByKey(int,int);
	int partitionKey(int,int);
	
	void print(vector<pair<string,int> >&);
	
};

class VectorSorting
{
	public:
		
	VectorSorting(vector<pair<string,int> > v);
	~VectorSorting();
	void print(vector<pair<string,int> >&);
	
	vector<pair<string,int> > MergeSort(vector<pair<string,int> > &); 
	vector<pair<string,int> >MergeKey(vector<pair<string,int> > &, vector<pair<string,int> >&); 
	vector<pair<string,int > >MergeSortByKey(vector<pair<string,int > >&); 
	vector<pair<string,int> > Merge(vector<pair<string,int> > &, vector<pair<string,int> > &); 
	
	private:
	vector<pair<string,int> > vnew;
};

#endif
