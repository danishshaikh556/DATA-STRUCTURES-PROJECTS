#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<queue>
#include"graph.h"
using namespace std;


int INFINITY=INT_MAX;
int timer=0;
int ftime=0;

void Vertex::reset(map<string, Vertex *> v)
{
	Graph g;
	vmap::iterator itr;
	for(itr=v.begin();itr!=v.end();itr++)
		{
			itr->second->color=2;
			itr->second->dist=INFINITY;
			itr->second->wt=0;
			itr->second->path=NULL;
			itr->second->key=60;

		}
}
Vertex::Vertex(){}
Vertex::Vertex(string &n)
{
	name=n;
	color=2;
	dist=INFINITY;
	wt=0;
	path=NULL;
	key=60;
}

Graph::Graph(){}
Graph::~Graph()
{
	for(int i=0;i<allVertices.size();i++)
		delete allVertices[i];
}
void Graph::addEdge(string &sourceName, string &destName,int &weight)
{
	vector<Vertex *>::iterator it;
	Vertex * v=getVertex(sourceName);
	Vertex * w=getVertex(destName);
	
	v->adj.push_back(pair<int,Vertex *> (weight,w));
	
	
}

Vertex * Graph::getVertex(string &vertexName)
{
	vmap::iterator itr = vertexMap.find( vertexName );
	if( itr == vertexMap.end( ) )
    		{
       		 Vertex *newv = new Vertex( vertexName );
        		// allVertices.push_back( newv );
        		 vertexMap.insert( vpair( vertexName, newv ) );
			 return newv;
    		}
    return (*itr).second;
}
void FileReader::readFile(char *filename)
{

Graph g;
Vertex *v;
vmap::iterator itr;
string str2,str1,str4;		
fstream fileRead(filename);
fstream fileRead2(filename);
int wt;
	string source, dest,str3;
	
getline(fileRead2,str1);


//cout<<str1;
stringstream iss(str1);

while(iss>>str3)
{	
	//cout<<str3<<endl;
	v=g.getVertex(str3);
}	

 while(getline( fileRead, str2 ) )
    {
	//cout<<str2<<endl;
	if(str2=="\n")
		break;
	
	else if(!fileRead.eof())
	{
		//cout<<str2<<endl;					
		fileRead>>source;
		fileRead>>dest;
		fileRead>>wt;
	
        	g.addEdge(source,dest,wt);
		if(source!=dest)
		g.addEdge(dest,source,wt);

	}
 }



fileRead2.close();
	itr=g.vertexMap.begin();
	g.BFS(itr->second);

	//g.BFS(g.allVertices[0]);
	
	v->reset(g.vertexMap);
	g.DFS(g.vertexMap);
	

	itr=g.vertexMap.begin();	
	g.Prims(itr->second);	
	
	
}

void Graph::BFS(Vertex * v)
{
	queue<Vertex *> Q;
	Vertex * u;
	v->color=1;
	v->dist=0;
	v->path=NULL;
	
	Q.push(v);
	//enqueue(Q,v);
	
	while(!Q.empty())
	{
		//cout<<Q.front()<<endl;
		//cout<<u->name<<endl;		
		u=Q.front();
		
		Q.pop();
		for(int i=0;i<u->adj.size();i++)
		{
			if(u->adj[i].second->color==2)
				{
					u->adj[i].second->color=1;
					u->adj[i].second->dist=u->dist+1;
					u->adj[i].second->path=u;
				
				Q.push(u->adj[i].second);
				}
		}
		u->color=0;
		cout<<"Visiting vertex: "<<u->name<<" "<<"Distance: "<<u->dist<<endl; 	
	}
			
}

void Graph::DFS(map<string, Vertex * > &v)

{	
	vmap::iterator itr;
	for ( itr=v.begin();itr!=v.end();itr++ )		
		{
			
			if(itr->second->color==2)
			DFSVisit(itr->second);
		}
}

void Graph::DFSVisit(Vertex * u)
{
	
	timer=timer+1;
	u->dist=timer;
	u->color=1;
	cout<<"Visiting Vertex: "<<u->name<<" "<<"Time: "<<u->dist<<endl;
	for(unsigned int i=0;i<u->adj.size();i++)
	{		
		if(u->adj[i].second->color==2)
		{
			u->adj[i].second->path=u;
			DFSVisit(u->adj[i].second);
		}	
	}
	
	
	u->color=0;
	timer=timer+1;
	ftime=timer;
	cout<<"Finished Vertex: "<<u->name<<" "<<"Time: "<<ftime<<endl;

	
}
void Graph::minHeapify(int i,int heapsize)
{
    int l;
    int r;
    int smallest;

    l=2*i+1;
    r=2*i+2;

if ((l<heapsize) && (Q[l].first<=Q[i].first))		//comparing parent with left child
	{
			if(Q[l].first==Q[i].first)				
			{
				if(Q[l].second->name<Q[i].second->name)
					smallest=l;
				else
					smallest=i;
			}		
			else smallest=l;
	}
	else 
		smallest=i;
	
	int t=smallest;
    
	if ((r<heapsize) && (Q[r].first<=Q[smallest].first)) 
			if(Q[r].first==Q[smallest].first)      
			{
				if(Q[r].second->name<Q[smallest].second->name)
					smallest=r;
				else
					smallest=t;
			}
			else
				smallest=r;

	if (smallest!=i)							
    {
		swap(Q[smallest],Q[i]);        		
		minHeapify(smallest,heapsize);
    }
}

void Graph::Prims(Vertex* r)
{	
vmap::iterator itr;	
string x;
Vertex *u;
int flag=0;
r->key=0;
for(itr=vertexMap.begin();itr!=vertexMap.end();itr++)
{
	Q.push_back (pair<int,Vertex *> (itr->second->key,itr->second));
}
while(!Q.empty())
{
	u=Q[0].second;	
	cout<<"Vertex: "<<Q[0].second->name<<" "<<"Key: "<<Q[0].first<<endl;
	Q.erase(Q.begin());
	if(Q.empty())
	{
		return;
	}
for(int i=0;i<u->adj.size();i++)
{
	for(int k=0;k<Q.size();k++)
	{
		if((u->adj[i].second==Q[k].second) && (u->adj[i].first < u->adj[i].second->key))
		{
			u->adj[i].second->path=u;
			u->adj[i].second->key=u->adj[i].first;
			for(int j=0;j<Q.size();j++)
			{
				if(Q[j].second==u->adj[i].second)
				{
					Q.erase(Q.begin()+j);
					Q.push_back(pair<int,Vertex *> (u->adj[i].first,u->adj[i].second));	
					break;
				}	
			}
		break;
		}	
	}	
}	
	for(int j=((Q.size()) / 2)-1;j>=0;j--) 
	minHeapify(j,Q.size());
}
}


