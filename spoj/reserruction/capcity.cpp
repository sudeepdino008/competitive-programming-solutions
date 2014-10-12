
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
	vector<lld> *adj,*transpose,*undirected;
public:
	Graph(lld V);
	void addEdge(lld u, lld v);
	void DFS(lld u, vector<lld> gr[], bool *visited,stack<lld> &nodes);
	void kosaraju(vector<lld> &answer);
};

Graph::Graph(lld V){
	this->V = V;
	adj = new vector<lld>[V+1];
	transpose = new vector<lld>[V+1];
	undirected = new vector<lld>[V+1];
}

void Graph::addEdge(lld u, lld v){
	adj[u].pb(v);
	transpose[v].pb(u);
	undirected[u].pb(v);
	undirected[v].pb(u);
}

void Graph::DFS(lld u, vector<lld> gr[],bool *visited, stack<lld> &nodes){
	stack<lld> local_node;
	lld k;
	bool flag;
	local_node.push(u);
	visited[u]=true;
	while(!local_node.empty()){
		k = local_node.top();
		flag = true;
		tr(gr[k],it){
			if(!visited[*it]){
				visited[*it] = true;
				local_node.push(*it);
				flag = false;
				break;
			}
		}
		if(flag){
			nodes.push(local_node.top());
			local_node.pop();
		}
	}
}

void Graph::kosaraju(vector<lld> &answer){
	bool visited[V+1], flag;
	stack<lld> nodes;

	lld i,k;
	memset(visited,false,V+1);

	DFS(1,undirected,visited,nodes);
	if((lld)nodes.size()!=V)return;

	while(!nodes.empty())nodes.pop();
	memset(visited,false,V+1);
	
	for(i=1;i<=V;i++)if(!visited[i])DFS(i,adj,visited,nodes);
	memset(visited,false,V+1);
	
	while(!nodes.empty()){
		stack<lld> SCC;
		set<lld> members;
		vector<lld> component;
		k = nodes.top();
		if(!visited[k]){
			DFS(k,transpose,visited,SCC);
			while(!SCC.empty())component.pb(SCC.top()), members.insert(SCC.top()), SCC.pop();
			flag = true;
			tr(component,it){
				tr(transpose[*it],itt){
					if(!present(members,*itt)){
						flag = false;
						break;
					}
				}
				if(!flag)break;
			}
			if(flag){
				answer = component;
				sort(answer.begin(), answer.end());
				return;
			}
		}
	}
	return;
}

int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	
	lld n,m,a,b;
	vector<lld> answer;
	inputInt(n);
	inputInt(m);
	Graph g(n);
	while(m--){
		inputInt(a);
		inputInt(b);
		g.addEdge(b,a);
	}
	g.kosaraju(answer);
	printf("%lld\n",(lld)answer.size());
	tr(answer,it)printf("%lld ",*it);
	printf("\n");
}
