//Algorithms for undirected graphs( change addEdge(int,int) function for directed graphs)

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <sys/time.h>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;


class Graph          //undirected graphs, change addEdge function for directed graphs
{
private:
	int V;    //number of nodes
	vector<int> *adj;    //pointer to array of vectors for storing in adjacency list format
public:
	Graph(int V);
	void addEdge(int u, int v,bool directed); //join u to v
	bool printDFS(); //prints tree with origin u using the DFS algorithm
	bool DFS(int u, lld *visited);   //assisting function for printDFS
	int shortestDistance(int u, int v); //returns shortest distance(number of edges) between nodes u and v.
	void topological_sort_DFS();
	void topological_sortUTIL(int i,bool visited[],stack<int> &s);
	void deleteEdge(int u, int v);
	void bridgeDetection();
	bool isEmpty();
	void kruskal();
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new vector<int>[V+1];
}

bool Graph::isEmpty()
{
	return (V==0);
}

void Graph::topological_sortUTIL(int start,bool visited[], stack<int> &s)
{
	visited[start]=true;
	for(vector<int>::iterator it=this->adj[start].begin(); it!=this->adj[start].end();it++)
	{
		if(!visited[*it])
			topological_sortUTIL(*it,visited,s);
	}
	s.push(start);
}

void Graph::topological_sort_DFS()
{
	bool visited[V+1];
	memset(visited,false,sizeof visited);
	int i;
	stack<int> s;
	for(i=1;i<=V;i++)
	{
		if(!visited[i])
			topological_sortUTIL(i,visited,s);
	}
	cout<<"\n\nTopological sort:\n";
	while(!s.empty())
	{	
	cout<<s.top()<<" ";
		s.pop();
	}
}
	
void Graph::deleteEdge(int u, int v)       //generic function for both directed and undirected
{
	vector<int>::iterator it=find(this->adj[u].begin(),this->adj[u].end(),v);
	int uv=0;           //0->not present, 1-> uv present, 2-> uv and vu present
	if(it!=adj[v].end())
	{
		this->adj[u].erase(it);
		uv=1;
	}
		
	it=find(this->adj[v].begin(),this->adj[v].end(),u);
	if(it!=adj[v].end())
	{
		this->adj[v].erase(it);
		uv=2;
	}
	if(uv==0)
		cout<<"no such edge\n";

}

void Graph::addEdge(int u, int v,bool directed)
{
	adj[u].push_back(v);
	if(!directed)
		adj[v].push_back(u);     //for undirected graph
}

int Graph::shortestDistance(int u, int v)         //uses BFS algorithm...
{
	if(u==v)
		return 0;
	queue<int> nodes;
	bool visited[V+1];
	int level[V+1];
	memset(level, -1, sizeof level);
	level[u]=0;
	memset(visited, false , sizeof visited);
	visited[u]=true;
	nodes.push(u);
	while(!nodes.empty())
	{
		for(vector<int>::iterator it=adj[nodes.front()].begin();it!=adj[nodes.front()].end();it++)
		{
			if(!visited[*it])
			{
				if(level[*it]==-1)
					level[*it]=level[nodes.front()]+1;
				if(*it==v)
					return level[v];
				nodes.push(*it);
				visited[*it]=true;
			}
		}
		nodes.pop();
	}
	return level[v];
}

bool Graph::DFS(int u, lld *visited)
{
	stack<int> nodes;
	nodes.push(u);
	bool present = true;     //if the last node has produced another node or not. 
	while(!nodes.empty())        
	{
		present=false;
		int k=nodes.top();
		for(vector<int>::iterator it=adj[k].begin(); it!=adj[k].end();it++)
		{
			if(visited[*it]==-1)
			{
				present=true;
				nodes.push(*it);
				visited[*it]=1-visited[k];
			}
			if(visited[*it]==visited[k])
				return false;
		}
		if(!present)
			nodes.pop();
	}
	return true;
}

bool Graph::printDFS()
{
	lld visited[V+1];
	int i;
	memset(visited, -1, sizeof visited);
	
	for(i=1;i<=V;i++)
	{
		if(visited[i]==-1)
		{
			visited[i]=1;
			if(!DFS(i, visited))return false;
		}
	}
	return true;
	
	
}

void Graph::bridgeDetection()     //assuming connected graph
{
	int nature[V+1];  //=0 if not in stack and not visited; 1 if only visited and not in stack; 2 if both
	memset(nature, 0, sizeof nature);
	int u,v,count;
	bool flag;
	stack<int> nodes;
	nodes.push(1);
	nature[1]=2;
	while(!nodes.empty())
	{
		u=nodes.top();
		count=0;
		flag=true;
		for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)
		{
			if(nature[*it]==0)
			{
				flag=false;
				nodes.push(*it);
				nature[*it]=2;
			}
			else if(nature[*it]==2)
			{
				count++;
				v=*it;
			}
		}
		if(count==1)
			cout<<"bridge between: "<<u<<"-"<<v<<"\n";
		if(flag)
		{
			nodes.pop();
			nature[u]=1;
		}
		
	}
}

template<class T>
inline void inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}


int main()
{
	/*Graph g(8);
	g.addEdge(4,1,false);
	g.addEdge(4,2,false);
	g.addEdge(5,2,false);
	g.addEdge(4,3,false);
	g.addEdge(6,4,false);
	g.addEdge(6,5,false);
	g.addEdge(7,4,false);
	g.addEdge(8,5,false);
	g.addEdge(8,3,false);
	Graph g1(g);
	g1.printDFS(1);
	cout<<"\n\n";
	g.bridgeDetection();
	cout<<endl<<endl;
	cout<<"shortest distance:"<<g.shortestDistance(6,1)<<endl;
	g1.topological_sort_DFS();*/
	lld t,n,p,a,b,i=1;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		inputInt(p);
		Graph g(n);
		while(p--)
		{
			inputInt(a);
			inputInt(b);
			g.addEdge(a,b,false);
		}
		printf("Scenario #%lld:\n", i++);
		if(g.printDFS())
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
}


