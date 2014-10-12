
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
#define tr(c,i) for(vector<lld>::iterator i = (c).begin(); i != (c).end(); i++) 
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
	set<lld> done;
public:
	vector<lld> *adj;
	Graph(lld V);
	void addEdge(lld u, lld v);
	pair<lld,lld> distance(lld u);  
	void computeDistance();
	lld answer();
};

Graph::Graph(lld V){
	this->V = V;
	adj = new vector<lld>[V+1];
}

void Graph::addEdge(lld u, lld v){
	adj[u].pb(v);
	adj[v].pb(u);
}

pair<lld,lld> Graph::distance(lld u){ 
	queue<lld> nodes;
	nodes.push(u);
	bool visited[V+1];
	lld distance[V+1],k;
	distance[u] = 0;
	memset(visited,false,sizeof visited);
	visited[u] = true;
	lld maxDiameter=0,freq=1;
	while(!nodes.empty()){
		k = nodes.front();
		tr(adj[k],it){
			if(!visited[*it]){
				visited[*it] = true;
				nodes.push(*it);
				distance[*it] = distance[k]+1;
				if(maxDiameter<distance[*it]){
					maxDiameter = distance[*it];
					freq=1;
				}
				else if(maxDiameter==distance[*it])freq++;
			}
		}
		nodes.pop();
	}
	return pair<lld,lld>(maxDiameter,freq);
}

typedef struct n{
	lld node;
	pair<lld,lld> p;
}ain;

bool compareByLength(const ain &a, const ain &b)
{
	return a.p.first > b.p.first || (a.p.first==b.p.first && a.p.second > b.p.second);
}

void Graph::computeDistance(){
	vector<ain> vec;
	for(lld i=1;i<=V;i++){
		if(!present(done,i) && adj[i].size()==1)
		{
			ain a;
			a.node = i;
			a.p = distance(i);
			vec.pb(a);
			debug(a.node,a.p.first,a.p.second);
		}
	}
	sort(vec.begin(),vec.end(),compareByLength);
	ain p = vec[0];
	debug(p.node,p.p.first,p.p.second);
	debug("yeah");
	done.insert(p.node);
	tr(adj[p.node],it){
		adj[*it].erase(find(adj[*it].begin(),adj[*it].end(),p.node));
	}
}

lld Graph::answer(){
	pair<lld,lld> p;
	lld maxD = -1,i;
	for(i=1;i<=V;i++){
		if(!present(done,i) && adj[i].size()==1){
			p = distance(i);
			if(p.first>maxD)maxD=p.first;
		}
	}
	return maxD;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n, k,u,v,i;
	 inputInt(n);
	 inputInt(k);
	 Graph g(n);
	 for(i=1;i<=n-1;i++){
		 inputInt(u);
		 inputInt(v);
		 g.addEdge(u,v);
	 }
	 for(i=1;i<=k;i++){
		 g.computeDistance();	 
	 }
	 printf("%lld\n",g.answer());
}

