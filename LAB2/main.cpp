#include<iostream>
#include "lab2.h"
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<time.h>
#include<map>
#include <sys/time.h>

//vector<pair<string,int> >v;

using namespace std;
//const char *str1;

int main(int argc, char* argv[])
{	
	vector<pair <string,int> > v,insertionByKeyOut,insertionByValueOut,mergeByValueOut,mergeByKeyOut,heapByKeyOut,heapByValueOut;
	vector<pair <string,int> > v2;
	 char *str1;
	VectorSorting *vs;
	if(argc!=2)
	{
	cout<<"Please enter an input file :-";
	return 0;
	}
	
	str1=argv[1];
	FileReader reader;
	std::string s=reader.readFile(str1);
	timeval start,end;
	double difference,t1,t2;
	//cout<<"The map contains : ----->"<<endl;	
	WordCount word;
	v=word.count(s);
	
	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	
	word.quickSortByValue(0,(word.final.size()-1));
	
	gettimeofday(&end, NULL);
 	
	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;
	
	for(int i=0;i<word.final.size();i++)
	{
		for(int j=i+1;j<word.final.size();j++)
		{
			if((word.final[i].second==word.final[j].second) && (word.final[i].first>word.final[j].first))
			{
				
				swap(word.final[i],word.final[j]);
			}
		}
	}
	
	cout<<"QuickSort by Values"<<endl;
	word.print(word.final);
	//cout<<"Quick Sort By Values Run time :"<<difference*1000000<<" microseconds"<<endl;

	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
			
	word.quickSortByKey(0,(word.final.size()-1));
	gettimeofday(&end, NULL);
 	
	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;

	cout<<"QuickSort by Keys"<<endl;
	word.print(word.final);

	//cout<<"Quick Sort By Keys Run time :"<<difference*1000000<<" microseconds"<<endl;

	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;


	mergeByValueOut=vs->MergeSort(v);
	gettimeofday(&end, NULL);
 	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;


	int totalCount2=0;
		int value2;
		int innercount2;
		int vectorcount2;
		int size2=mergeByValueOut.size();
		
		while(totalCount2<(size2-1))
		{
			innercount2=totalCount2;
			value2=mergeByValueOut[totalCount2].second;
			vectorcount2=0;
			vector< pair <string,int > > temp;
					
			while((mergeByValueOut[innercount2].second==value2) && (mergeByValueOut.size()>innercount2))
			{
				
				
				temp.push_back(mergeByValueOut[innercount2]);
					
				vectorcount2++;	
				innercount2++;
				
			}
			temp=vs->MergeSortByKey(temp);
			
			
			for(int i=0;i<temp.size();i++)
				mergeByValueOut[i+totalCount2]=temp[i];
			
			
			
			temp.erase(temp.begin(),temp.end());
			
			totalCount2+=vectorcount2;
			
		
		}
		


	cout<<"MergeSort by Values"<<endl;
	vs->print(mergeByValueOut);
	
	//cout<<"Merge Sort By Values Run time :"<<difference*1000000<<" microseconds"<<endl;

	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	
	mergeByKeyOut= vs->MergeSortByKey(mergeByValueOut);
	
	gettimeofday(&end, NULL);
 	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;

	cout<<"MergeSort by Keys"<<endl;
	vs->print(mergeByKeyOut);
	//cout<<"Merge Sort By Keys Run time :"<<difference*1000000<<" microseconds"<<endl;

	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	
	heapByValueOut = word.heapSortValue(v);	

	gettimeofday(&end, NULL);
 	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;


	int totalCount1=0;
		int value1;
		int innercount1;
		int vectorcount1;
		int size1=heapByValueOut .size();
		
		while(totalCount1<(size1-1))
		{
			innercount1=totalCount1;
			value1=heapByValueOut[totalCount1].second;
			vectorcount1=0;
			vector< pair <string,int > > temp;
					
			while((heapByValueOut [innercount1].second==value1) && (heapByValueOut .size()>innercount1))
			{
				
				
				temp.push_back(heapByValueOut [innercount1]);
					
				vectorcount1++;	
				innercount1++;
				
			}
			temp=word.HeapSort(temp);
			
			
			for(int i=0;i<temp.size();i++)
				heapByValueOut [i+totalCount1]=temp[i];
			
			
			
			temp.erase(temp.begin(),temp.end());
			
			totalCount1+=vectorcount1;
			
		
		}
		
	
	
	cout<<"HeapSort by Values"<<endl;
	word.print(heapByValueOut);

	//cout<<"Heap Sort By Values Run time :"<<difference*1000000<<" microseconds"<<endl;

	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	
	heapByKeyOut=word.HeapSort(heapByValueOut);
	gettimeofday(&end, NULL);
 	t2 = end.tv_sec + end.tv_usec/1000000.0;
	difference=t2 - t1;

	
	cout<<"HeapSort by Keys"<<endl;
	word.print(heapByKeyOut);
	//cout<<"Heap Sort By Keys Run time :"<<difference*1000000<<" microseconds"<<endl;


	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;

	insertionByValueOut=word.insertionSortByValue(heapByKeyOut);
	
	gettimeofday(&end, NULL);
 	t2 = end.tv_sec + end.tv_usec/1000000.0;

	difference=t2 - t1;
	
	cout<<"InsertionSort by Values"<<endl;
	word.print(insertionByValueOut);
	//cout<<"Insertion Sort By Values Run time :"<<difference*1000000<<" microseconds"<<endl;

	
	gettimeofday(&start, NULL);
	t1 = start.tv_sec + start.tv_usec/1000000.0;
	
	insertionByKeyOut = word.insertionSortByKey(insertionByValueOut);

	gettimeofday(&end, NULL);
 	t2 = end.tv_sec + end.tv_usec/1000000.0;

	difference=t2 - t1;

	cout<<"InsertionSort by Keys"<<endl;
	word.print(insertionByKeyOut);
	//cout<<"Insertion Sort By Keys Run time :"<<difference*1000000<<" microseconds"<<endl;

return 0;	
}
