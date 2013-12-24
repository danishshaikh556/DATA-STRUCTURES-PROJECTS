#ifndef _MYHEADER1_H_
#define _MYHEADER1_H_
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<limits.h>
//WHITE=2
//BLACK=0
//GRAY=1 
using namespace std;

class Vertex
{
	public:
		string name;
		vector<pair<int,Vertex *> > adj;
		int dist;
		int wt;
		int color;
		int time;
		int ftime;
		int key;
		Vertex *path;
		Vertex();
		Vertex(string &);
		void reset(map<string,Vertex *>);
};



typedef map<string,Vertex *> vmap;
typedef pair<string,Vertex *>vpair;
class Graph
{
	public:
		typedef pair<int,Vertex *> temp;	
		vector<pair<int,Vertex *> > Q;	//priority queue
		Graph();
		~Graph();
		vector<Vertex *>allVertices;
		vmap vertexMap;
		
		void minHeapify(int i,int heapsize);
		void addEdge(string &,string &,int &);
		void BFS(Vertex*);
		void DFS(vmap &);
		void DFSVisit(Vertex *);
		void Prims(Vertex*);		
		Vertex * getVertex(string &);		
};
class FileReader
{
 public:	
	void readFile(char *);	
};
#endif
