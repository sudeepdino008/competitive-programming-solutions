
//#include GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
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

template<class T>
inline void inputInt(T &n )
{
	n=0;

 	T ch=getchar_unlocked();
	/*int sign=1;
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
		 n*=sign;*/
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

class Graph{
private:
	lld V;
	vector<lld> *adj, *transpose;
public:
	Graph(lld V);
	void addEdge(lld u, lld v);
	void DFS(vector<lld> gr[],lld u, bool *visited,stack<lld> &roder);
	void kosaraju();
};

Graph::Graph(lld V){
	this->V = V;
	adj = new vector<lld>[V+1];
	transpose = new vector<lld>[V+1];
}

void Graph::addEdge(lld u, lld v){
	adj[u].pb(v);
	transpose[v].pb(u);
}

void Graph::DFS(vector<lld> gr[], lld u, bool *visited, stack<lld> &order){
	stack<lld> nodes;
	bool flag;
	lld k;

	visited[u] = true;
	nodes.push(u);
	while(!nodes.empty()){
		k = nodes.top();
		flag = true;
		tr(gr[k],it){
			if(!visited[*it]){
				nodes.push(*it);
				visited[*it] = true;
				flag = false;
				break;
			}
		}
		if(flag){
			order.push(nodes.top());
			nodes.pop();
		}		
	}
}

void Graph::kosaraju(){
	bool visited[V+1];
	stack<lld> order,answer;
	lld i;
	for(i=1;i<=V;i++)visited[i] = false;
	for(i=1;i<=V;i++){
		if(!visited[i])
			DFS(adj,i,visited,order);
	}
	for(i=1;i<=V;i++)visited[i] = false;
	while(!order.empty()){
		i = order.top();
		order.pop();
		if(!visited[i])
			DFS(transpose,i,visited,answer);

		//answer contains one SCC
		if(!answer.empty())
			debug("Compopnent:");
		while(!answer.empty())
		{
			debug(answer.top());
			answer.pop();
		}
	  
	}
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,m,a,b;
	 inputInt(n);
	 inputInt(m);
	 Graph g(n);
	 while(m--){
		 inputInt(a);
		 inputInt(b);
		 g.addEdge(a,b);
	 }
	 g.kosaraju();
}

