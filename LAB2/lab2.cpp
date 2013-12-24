#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<map>
#include<math.h>
#include<sstream>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include"lab2.h"
#include<cstdlib>
#include<ctime>

vector<pair<string,int> > v;	
using namespace std;
//typedef std ::vector<pair <string,int> >:: iterator vit;

VectorSorting::VectorSorting(vector<pair<string,int> > v):vnew(v)
{}


void VectorSorting :: print(vector<pair<string, int> > & v)
{
	for(int i=0;i<v.size();i++)
	cout<<v[i].first<<" "<<v[i].second<<endl;

}

		
VectorSorting:: ~VectorSorting()
{}


void WordCount :: print(vector<pair< string, int> >& v)
{
	for(int i=0;i<v.size();i++)
	cout<<v[i].first<<" "<<v[i].second<<endl;
}

std::string FileReader::readFile(char *str1)
//string FileReader::readFile()

{
//char *str1;
	
string getFileContents,newString;
int i=0;	
std::string withoutSpecial;
stringstream final;

fstream fileRead(str1);	
while(!fileRead.eof())		//read file contentsgetFileContents
	{	
		
	 getline(fileRead,getFileContents);	 
	//cout<<"New String:-"<<getFileContents<<endl;
	newString.append(" ");
	newString.append(getFileContents);
	//cout<<"Final String :-"<<newString<<endl;		
	}
	//cout<<"Final String :-"<<newString<<endl;		

	fileRead.close();
		
	std::string lowerString(newString); 			//Convert to lower case
	std::transform(lowerString.begin(), lowerString.end(), lowerString.begin(), ::tolower);
	
	//cout<<endl<<"*****************New String to lower case"<<lowerString<<endl;	

	for(i=0;i<lowerString.length();i++)				//Remove special characters and punctuation
	{
		if((isalnum(lowerString[i]))||(lowerString[i]==' '))
			{
				withoutSpecial=lowerString[i];
				final<<withoutSpecial;
			}		
       
	}
	//cout<<"new string to lower case without special chars :-"<<final.str();
	//string finalString(final.str());
	//cout<<"Last:-"<<final.str;

return final.str();	
}

vector<pair < string,int> > WordCount::count(string lowerString)
{
	map<string,int> listMap;
  	pair<map<string,int>::iterator,bool> returnValue;
	map<string,int>::iterator mapIterator;
	vector<pair<string,int> > v;
	vector<pair<string,int> >:: iterator i;
	//vector<pair<string,int> >:: iterator j;	
	//int j=0;
	//int val=0;

	string subString;
	stringstream stringToken(lowerString);
	
	while(stringToken>>subString)				//extract only words from stream
	{		
	
		
	//cout<<"Substring "<<subString<<endl;
	returnValue=listMap.insert (pair<string,int>(subString,1) );
	
	if (returnValue.second==false)		//check return value of insert
  	 {
		listMap[subString]++;			//count no. of times the key has occured	
		//cout<<listMap[subString]<<endl;
 		listMap.insert(pair<string,int>(subString,listMap[subString]));	//insert in map
	 } 
	
	}		
	//for ( mapIterator=listMap.begin() ; mapIterator!= listMap.end(); mapIterator++ )			//print map contents
    	//cout << (*mapIterator).first << " " << (*mapIterator).second << endl;	
	
	
	
	//copy(listMap.begin(), listMap.end(), back_inserter(v));
	copy(listMap.begin(), listMap.end(), back_inserter(final));	//copy map elements in vector
	//cout<<"vector contains :"<<endl;
	//for(int i = 0; i < final.size(); ++i)
       //cout << final[i].first <<" "<<final[i].second << endl;
	
		

	return final;	 	
}
	
/* ----------------------------MERGE SORT BY VALUE-------------------------------*/

vector<pair<string,int> > VectorSorting :: Merge(vector<pair<string,int> > &LeftVector, vector<pair<string,int> > &RightVector) 
{
	vector<pair<string,int> > Result;				
	while (LeftVector.size() > 0 && RightVector.size() > 0)
	 {
		if (LeftVector[0].second <= RightVector[0].second) 
		{					
			Result.push_back(LeftVector[0]);	// add first element to result vector
			LeftVector.erase(LeftVector.begin());	// remove first element from left vector
		} 
		else
	        {
			Result.push_back(RightVector[0]);	// add first element to result vector
			RightVector.erase(RightVector.begin());	// remove first element from right vector
		}
		
		//for(int i =0;i<Result.size();i++)
		//cout<<Result[i].second<<endl;

		//cout<<"-------";

			
	}
	if (LeftVector.size() > 0) 
	{										// if left still has elements remaining
		Result.insert(Result.end(), LeftVector.begin(), LeftVector.end());	// append remaining left elements to result
	
	} 
	else
	 {
		Result.insert(Result.end(), RightVector.begin(), RightVector.end());// append remaining right elements to result
	 }
	return Result;					// return sorted merge of left and right
}

vector<pair<string,int > > VectorSorting :: MergeSort(vector<pair<string,int > > &v) 
{
	if (v.size() <= 1) 
	{
		return v;
	}
	
	// break numbers into two smaller vectors
	vector<pair<string,int> > LeftVector, RightVector;
	
	 int Middle = v.size() / 2;				// pivot
	for ( int i = 0; i < Middle; i++) {
		LeftVector.push_back(v[i]);
	}
	for (int i = Middle; i < v.size(); i++) 
	{
		RightVector.push_back(v[i]);
	}
	
	//VectorSorting *vs1, *vs2;
	//vs1= new VectorSorting(Left);
	MergeSort(LeftVector);
	
	//vs2= new VectorSorting(Right);
	MergeSort(RightVector);
	
	v = Merge(LeftVector, RightVector);
	return v;
		
	vector <pair <string,int> >  insertionSortByValue(vector <pair <string,int> > &);
}

/* ----------------------------MERGE SORT BY VALUE END-------------------------------*/


/* ----------------------------MERGE SORT BY KEY-------------------------------*/

vector<pair<string,int> > VectorSorting :: MergeKey(vector<pair<string,int> > &LeftVector, vector<pair<string,int> > &RightVector) 
{
	vector<pair<string,int> > Result;				
	while (LeftVector.size() > 0 && RightVector.size() > 0)
	 {
		if (LeftVector[0].first <= RightVector[0].first) 
		{					
			Result.push_back(LeftVector[0]);	// add first element to result vector
			LeftVector.erase(LeftVector.begin());	// remove first element from left vector
		} 
		else
	        {
			Result.push_back(RightVector[0]);	// add first element to result vector
			RightVector.erase(RightVector.begin());	// remove first element from right vector
		}
		
		//for(int i =0;i<Result.size();i++)
		//cout<<Result[i].second<<endl;

		//cout<<"-------";

			
	}
	if (LeftVector.size() > 0) 
	{										// if left still has elements remaining
		Result.insert(Result.end(), LeftVector.begin(), LeftVector.end());	// append remaining left elements to result
	
	} 
	else
	 {
		Result.insert(Result.end(), RightVector.begin(), RightVector.end());// append remaining right elements to result
	 }
	return Result;									// return sorted merge of left and right
}

vector<pair<string,int > > VectorSorting :: MergeSortByKey(vector<pair<string,int > > &v) 
{
	if (v.size() <= 1) 
	{
		return v;
	}
	
	// break numbers into two smaller vectors
	vector<pair<string,int> > LeftVector, RightVector;
	
	 int Middle = v.size() / 2;	// pivot
	for ( int i = 0; i < Middle; i++) {
		LeftVector.push_back(v[i]);
	}
	for (int i = Middle; i < v.size(); i++) 
	{
		RightVector.push_back(v[i]);
	}
	
	//VectorSorting *vs1, *vs2;
	//vs1= new VectorSorting(LeftVector);
	MergeSortByKey(LeftVector);
	
	//vs2= new VectorSorting(Right);
	MergeSortByKey(RightVector);
	
	v = MergeKey(LeftVector, RightVector);	
	return v;
	
}

/* ----------------------------MERGE SORT BY KEY END-------------------------------*/



/* ----------------------------INSERTION SORT BY VALUE-------------------------------*/

vector<pair <string,int> >  WordCount::insertionSortByValue(vector<pair <string,int> >& v)
{
		
	int j=0;
	int value;
	for(int i = 1; i < v.size(); i++)
	{
     		value= v[i].second;
	       j = i- 1; 
      	  while(j >=0 && v[j].second > value)
	    	{
			swap(v[j+1],v[j]);			
           		j = j - 1;
		}

	 	 v[j + 1].second = value;
		
  	}
      
	for(int i=1;i<=v.size();i++)
	{
		for(int j=i+1;j<=v.size();j++)
		{
			if(v[i].second==v[j].second && v[i].first>v[j].first)
			swap(v[i],v[j]);



		}
	}
		
	
	return v;
	
}

/* ----------------------------END OF INSERTION SORT BY VALUE-------------------------------*/


/* ----------------------------INSERTION SORT BY KEY-------------------------------*/

vector<pair<string,int> > WordCount::insertionSortByKey(vector <pair <string,int> >& v)
{

	int j=0;
	string value;
	for(int i = 1; i < v.size(); i++)
	{
     		value= v[i].first;
		
	       j = i- 1; 
      	  while(j >=0 && v[j].first > value)
	    	{
			swap(v[j+1],v[j]);			
           		j = j - 1;
			
		}
	 	 v[j + 1].first = value;
		
  	}
  
	return v;

	
}

/* ----------------------------END OF INSERTION SORT BY KEY-------------------------------*/

 
/* ----------------------------HEAP SORT BY KEY-------------------------------*/

void WordCount :: maxHeapify(vector<pair<string,int> > &v, int Start, int End) 
{
	
	int Root = Start;
	while (Root * 2 + 1 <= End)
	 {			    			
		int Child = Root * 2 + 1;
		if (Child < End && v[Child].first < v[Child + 1].first)
		 {
			Child++;
		}
		if (v[Root].first < v[Child].first) 
		{
			swap(v[Root], v[Child]);
			Root = Child;			            
		}
		 else
		 {
			return;
		}
	}
	return;
}

vector<pair<string,int> > WordCount :: HeapSort(vector<pair<string,int> > &v)
 {
	// put numbers in max-heap order
	for (int i = (v.size() - 2) / 2; i >= 0; i--) {
		maxHeapify(v, i, v.size() - 1);
	}

	for (int i = v.size() - 1; i > 0; i--) {
		swap(v[0], v[i]);	    // swap root (max value) with last element of heap
		maxHeapify(v, 0, i - 1);		    // put numbers back in max-heap order
	}
		
	return v;
}

/* ----------------------------END OF HEAP SORT BY KEY-------------------------------*/

/* ----------------------------HEAP SORT BY VALUE -------------------------------*/

void WordCount :: maxHeapifyValue(vector<pair<string,int> >&v,int i,int heapsize)
 {
    int l;
    int r;
    int largest;

    l=2*i+1;
    r=2*i+2;

    if ((l<heapsize) && (v[l].second>v[i].second)) 
		largest=l;
    else 
		largest=i;
	
	
    if ((r<heapsize) && (v[r].second>v[largest].second)) 
		largest=r;

    if (largest!=i)
    {
		swap(v[largest],v[i]);        		
		maxHeapifyValue(v,largest,heapsize);
    }


	
 }

int WordCount:: buildMaxHeapValue(vector<pair<string,int> >&v)
{
	int heapsize=v.size();
    for (int j=((v.size()) / 2)-1;j>=0;j--) 
		maxHeapifyValue(v,j,heapsize);
	return heapsize;
}

vector<pair<string,int> >WordCount:: heapSortValue(vector<pair<string,int> >&v)
{
    int t;
    int k;
    int heapsize=buildMaxHeapValue(v);
    for (k=v.size()-1;k>=1;k--)
    {
		swap(v[0],v[k]);
		heapsize--;
        maxHeapifyValue(v,0,heapsize);
    }
	
	return v;
}

/* ----------------------------END OF HEAP SORT BY VALUE-------------------------------*/

/* ----------------------------QUICK SORT BY VALUE-------------------------------*/
void WordCount :: quickSortByValue(int left, int right)
{	
	
	 if(left < right) 
    {
        int mid = partition(left,right);
        quickSortByValue(left, mid-1);
        quickSortByValue(mid+1, right);
    }



}


  int WordCount :: partition(int left, int right)

{
    int pivot = final[right].second;			//select pivot as the last element
    int pivotIdx = right;
    int i = left -1;
 
    for(int j=left; j<=right-1; j++)
    {
        if(final[j].second <= pivot)
        {
            i = i+1;
            swap(final[i], final[j]);
        }
    }
 
    swap(final[i+1], final[pivotIdx]);
    return i+1;
}

void WordCount :: quickSortByKey(int left, int right)
{	
	
	 if(left < right) 
    {
        int mid = partitionKey(left,right);
        quickSortByKey(left, mid-1);
        quickSortByKey(mid+1, right);
    }

}


  int WordCount :: partitionKey(int left, int right)

{

	//srand(time(NULL));	
    //int pivotIdx = left + rand() % (right-left+1);
    string pivot = final[right].first;
    //swap(final[pivotIdx], final[right]); // move pivot element to the end
    int pivotIdx = right;
    int i = left -1;
 
    for(int j=left; j<=right-1; j++)
    {
        if(final[j].first <= pivot)
        {
            i = i+1;
            swap(final[i], final[j]);
        }
    }
 
    swap(final[i+1], final[pivotIdx]);
    return i+1;
}

