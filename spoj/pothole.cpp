//solved


//#define GRAPH
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

struct Edge {
	lld from, to, cap, flow, index;
	Edge(lld from, lld to, lld cap, lld flow, lld index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Graph {
	lld N;
	vector<vector<Edge> > G;
	vector<lld> excess;
	vector<lld> dist, active, count;
	queue<lld> Q;

	Graph(lld N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

	void addEdge(lld from, lld to, lld cap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to) G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	void Enqueue(lld v) { 
		if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
	}

	void Push(Edge &e) {
		lld amt = min(excess[e.from], e.cap - e.flow);
		if (dist[e.from] <= dist[e.to] || amt == 0) return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;    
		excess[e.from] -= amt;
		Enqueue(e.to);
	}
  
	void Gap(lld k) {
		for (lld v = 0; v < N; v++) {
			if (dist[v] < k) continue;
			count[dist[v]]--;
			dist[v] = max(dist[v], N+1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}

	void Relabel(lld v) {
		count[dist[v]]--;
		dist[v] = 2*N;
		for (lld i = 0; i < G[v].size(); i++) 
			if (G[v][i].cap - G[v][i].flow > 0)
				dist[v] = min(dist[v], dist[G[v][i].to] + 1);
		count[dist[v]]++;
		Enqueue(v);
	}

	void Discharge(lld v) {
		for (lld i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
		if (excess[v] > 0) {
			if (count[dist[v]] == 1) 
				Gap(dist[v]); 
			else
				Relabel(v);
		}
	}

	lld max_flow(lld s, lld t) {
		count[0] = N-1;
		count[N] = 1;
		dist[s] = N;
		active[s] = active[t] = true;
		for (lld i = 0; i < G[s].size(); i++) {
			excess[s] += G[s][i].cap;
			Push(G[s][i]);
		}
    
		while (!Q.empty()) {
			lld v = Q.front();
			Q.pop();
			active[v] = false;
			Discharge(v);
		}
		return excess[t];
	}
};



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
	lld t, n, m , a, i;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		Graph g(n);
		for(i=1;i<n;i++)
		{
			inputInt(m);
			while(m--)
			{
				inputInt(a);

				g.addEdge(i-1,a-1, (i==1 || a==n)?1:LLONG_MAX);
				
			}
		}
		cout<<g.max_flow(0,n-1)<<"\n";
	}
}

