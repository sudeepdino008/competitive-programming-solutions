
//#define GRAPH
#define DEBUG       //comment wvn you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment wvn all assert statements have to be enabled.
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
    template<typename T> debugger& operator , (const T& vv)
    {    
        cerr<<vv<<" ";    
        return *this;    
    }

}dbg;

class Graph{
private:
	lld V;
	vector<lld> *adj;
public:
	Graph(lld V);
	void addEdge(lld u, lld vv, bool directed=true);
	void BFS(lld start);
	void arbit(lld n);
};

void Graph::arbit(lld n){
	return ;
}

Graph::Graph(lld V){
	this->V = V;
	adj = new vector<lld>[V+1];
}

void Graph::addEdge(lld u, lld vv, bool directed){
	adj[u].pb(vv);
	if(!directed)
		adj[vv].pb(u);
}

void Graph::BFS(lld start){
	queue<lld> q;
	bool visited[V+1];
	memset(visited, false, sizeof visited);
 
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		lld front = q.front();
		printf("%lld ", front);
		for(vector<lld>::iterator it=adj[front].begin(); it!=adj[front].end();it++){
			if(!visited[*it]){
				q.push(*it);
				visited[*it] = true;
			}
		}
		q.pop();
	}
	
}

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

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld v,e,a,b;
	 inputInt(v);
	 inputInt(e);
	 Graph g(v);
	 while(e--){
		 inputInt(a);
		 inputInt(b);
		 g.addEdge(a,b);
	 }
	 g.BFS(1);
	 vector<int> vec;
	 vec.
	 std::out <<"hello" <<endl;
	 std::ll <<"ss";
}

