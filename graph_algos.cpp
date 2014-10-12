#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL
#define NDEBUG    //comment when all assert statements have to be disabled.
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <ctime>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define INDEX(arr,elem)        (lower_bound(all(arr),elem)-arr.begin())
#define lld long long int
#define MOD 1000000007
#define gcd __gcd
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
using namespace std;


#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }

}dbg;


class Graph          //by default directed graph
{
private:
	int V;    //number of nodes
	vector<int> *adj;    //pointer to array of vectors for storing in adjacency list format
public:
	Graph(int V);
	void addEdge(int u, int v,bool directed=true); //join u to v
	void printDFS(); //prints connected components by calling DFS
	void DFS(int u, bool *visited);   //assisting function for printDFS
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

void Graph::DFS(int u, bool *visited)
{
	visited[u]=true;
	stack<int> nodes;
	nodes.push(u);
	bool present = true;     //if the last node has produced another node or not. 
	while(!nodes.empty())        
	{
		present=false;
		int k=nodes.top();


		visited[k]=true;
		for(vector<int>::iterator it=adj[k].begin(); it!=adj[k].end();it++)
		{
			if(!visited[*it])
			{
				nodes.push(*it);
				present=true;
				break;
			}
		}
		if(!present)
		{
			cout<<nodes.top()<<" ";
			nodes.pop();
		}


	}
}
	

void Graph::printDFS()
{
	bool visited[V+1];
	int i;
	memset(visited, false, sizeof visited);
	
	for(i=1;i<=V;i++)
	{
		if(!visited[i])
		{
			debug("hey!");
			visited[i]=true;
			DFS(i, visited);
		}
	}
	cout<<endl;
	
	
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
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld v,e,a,b,i;
	inputInt(v);
	while(v!=0)
	{
		Graph g(v);
		inputInt(e);
		for(i=1;i<=e;i++)
		{
			inputInt(a);
			inputInt(b);
			g.addEdge(a,b,false);
		}

		g.printDFS();
		inputInt(v);
	}

}


