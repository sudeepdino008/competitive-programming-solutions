
//#define GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
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

#ifdef GRAPH
#include "drawGraph.cpp"
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }

}dbg;



class Graph          //by default undirected graph
{
private:
	lld V;    //number of nodes
	vector<lld> *adj;    //pointer to array of vectors for storing in adjacency list format
public:
	Graph(lld V);
	void addEdge(lld u, lld v,bool directed=false); //join u to v
	lld getDanger(); //prints connected components by calling DFS
	lld  BFS(lld u, bool *visited);   //assisting function for getDanger
	bool isEmpty();
};

Graph::Graph(lld V)
{
	this->V=V;
	adj = new vector<lld>[V+1];
}

bool Graph::isEmpty()
{
	return (V==0);
}

void Graph::addEdge(lld u, lld v,bool directed)
{
	adj[u].push_back(v);
	adj[v].push_back(u);     //for undirected graph
}

lld Graph::BFS(lld u, bool *visited)
{
	queue<lld> nodes;
	nodes.push(u);
	visited[u] = true;
	lld count=1, k, m;

	while(!nodes.empty()){
		k = nodes.front();
		for(vector<lld>::iterator it=adj[k].begin(); it!=adj[k].end();it++){
			m = *it;
			if(!visited[m]){
				visited[m] = true;
				count++;
				nodes.push(m);
			}
		}
		nodes.pop();
	}
	return count;
}
	

lld Graph::getDanger()
{
	bool visited[V+1];
	lld i,x=0,p=1;
	memset(visited, false, sizeof visited);
	
	for(i=1;i<=V;i++)
	{
		if(!visited[i])
			x+= (BFS(i,visited)-1);
	}
	for(i=1;i<=x;i++)
		p*=2;
	return p;
}


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,m,i,u,v;
	 cin>>n>>m;
	 Graph g(n);
	 for(i=1;i<=m;i++){
		 cin>>u>>v;
		 g.addEdge(u,v);
	 }
	 cout<<g.getDanger()<<endl;
}

