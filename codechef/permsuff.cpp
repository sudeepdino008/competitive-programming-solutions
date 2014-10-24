
//#include GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
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
	int sign=1;
 	T ch=getchar_unlocked();
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	n*=sign;
}


class Graph          //by default directed graph
{
private:
	lld V;    //number of nodes
	vector<lld> *adj;    //pointer to array of vectors for storing in adjacency list format
	vector<set<lld> > components;
	set<lld> presentComponent;
public:
	Graph(lld V);
	void addEdge(lld u, lld v); //join u to v
	void printDFS(); //prints connected components by calling DFS
	void DFS(lld u, bool *visited);   //assisting function for printDFS
	bool isEmpty();
	bool check(lld u, lld v);
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

void Graph::addEdge(lld u, lld v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);     //for undirected graph
}

void Graph::DFS(lld u, bool *visited)
{
	presentComponent.clear();
	visited[u]=true;
	stack<lld> nodes;
	presentComponent.insert(u);
	nodes.push(u);
	bool present = true;     //if the last node has produced another node or not. 
	while(!nodes.empty())        
	{
		present=false;
		lld k=nodes.top();
		visited[k]=true;
		for(vector<lld>::iterator it=adj[k].begin(); it!=adj[k].end();it++)
		{
			if(!visited[*it])
			{
				nodes.push(*it);
				presentComponent.insert(*it);
				present=true;
				break;
			}
		}
		if(!present)
			nodes.pop();


	}
}
	

void Graph::printDFS()
{
	bool visited[V+1];
	lld i;
	memset(visited, false, sizeof visited);
	
	for(i=1;i<=V;i++)
	{
		if(!visited[i])
		{
			debug("hey!");
			visited[i]=true;
			DFS(i, visited);
			components.pb(presentComponent);
		}
	}
	
	// for(i=0;i<components.size();i++){
	// 	debug("printing set:");
	// 	tr(components[i], it2)cout<<(*it2)<<" ";
	// }
}	

bool Graph::check(lld u, lld v){
	tr(components, it){
		bool a1=present(*it,u), a2=present(*it,v);
		if(a1 && a2)
			return true;
		else if(!a1 && !a2)continue;
		break;
	}
	return false;
}

typedef struct{
	lld x; lld y;
}range;


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t,n,m,i,u,v,j;
	 lld arr[100001];
	 inputInt(t);
	 while(t--){
		 inputInt(n);
		 inputInt(m);
		 for(i=1;i<=n;i++)inputInt(arr[i]);
		 Graph g(n);
		 map<lld, lld> ma;
		 for(i=1;i<=m;i++){
			 
			 inputInt(u);
			 inputInt(v);
			 bool pr = ma.find(u)!=ma.end();

			 if(!pr || (pr && ma[u]<v))ma[u]=v;
		 }
		
		 lld s=1;
		 while(ma.find(s)==ma.end() && s<=n)s++;
		 for(i=s+1;i<=ma[s];i++)g.addEdge(s,i);
		 for(i=s+1;i<=n && s<=n;i++){
			 if(ma.find(i)!=ma.end()){
				 if(i<=ma[s] && ma[i]>ma[s]){
					 for(j=ma[s]+1;j<=ma[i];j++)g.addEdge(s,j);
					 ma[s] = ma[i];
				 }
				 else if(i>ma[s]){
					 s=i;
					 for(j=s+1;j<=ma[s];j++)
						 g.addEdge(s,j);
				 }
			 }
		 }
		 
		 
		 g.printDFS();
		 for(i=1;i<=n;i++){
			 if(!g.check(i,arr[i]))break;
		 }
		 if(i==n+1)printf("Possible\n");
		 else printf("Impossible\n");
		 
	 }
}

