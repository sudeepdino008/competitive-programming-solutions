
#define GRAPH
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

struct Graph{
	lld numV;
	vector<lld> *adj, *neighbour;                  //neighbour contains (u,v) => either (u,v) or (v,u) or both in graph(residual graph)
	bool **ifEdge; 
	lld **flow, **cap, **cf, *height, *excess;
	Graph(lld _numV)
		{
			numV=_numV;
			lld i;
			/* allocating memory....*/
			flow = new lld*[numV+1];
			for(i=0;i<=numV;i++)
				flow[i] = new lld[numV+1];
			cap = new lld*[numV+1];
			for(i=0;i<=numV;i++)
				cap[i] = new lld[numV+1];
			cf = new lld*[numV+1];
			for(i=0;i<=numV;i++)
				cf[i] = new lld[numV+1];
			ifEdge = new bool*[numV+1];
			for(i=0;i<=numV;i++)
			{
				ifEdge[i] = new bool[numV+1];
				for(lld j=0;j<=numV;j++)
					ifEdge[i][j]=false;
			}
			
			height = new lld[numV+1];
			excess = new lld[numV+1];
			adj = new vector<lld>[numV+1];
			neighbour = new vector<lld>[numV+1];
		
		}
	void addEdge(lld u, lld v, lld uv)
		{
			ifEdge[u][v] = true;
			adj[u].push_back(v);
			neighbour[u].push_back(v);
			neighbour[v].push_back(u);
			cap[u][v] = uv;
			cf[u][v] = uv;
		}
	inline void SET0(lld *array)
		{
			for(lld i=0;i<=numV;i++)
				array[i] = 0;
		}
	void initialize_preflow(lld source)
		{
			lld i, v;
			for(i=0;i<=numV;i++)
				SET0(flow[i]);
			SET0(height);
			SET0(excess);
			height[source] = numV;

			tr(adj[source],it)
			{
				v = *it;
				flow[source][v] = cap[source][v];
				flow[v][source] = -flow[source][v];
				excess[v] = cap[source][v];
				excess[source] -=cap[source][v];
				cf[source][v] = cap[source][v]-flow[source][v];
				cf[v][source] = cap[v][source]-flow[v][source];
			}
		}
	void relabel(lld u)
		{
			lld m=-1;
			tr(neighbour[u],it)
			{
				if(cf[u][*it]>0)
				{
					if(m==-1) m = height[*it];
					else m = min(m,height[*it]);
				}
			}
			height[u] = 1+m;
		}
	void push(lld u, lld v, bool Edge)         //Edge indicates whether (u->v) is  present in the orginal or it is its reverse.
		{
			lld push_val = min(cf[u][v], excess[u]);
			if(Edge)
			{
				flow[u][v] += push_val;
				flow[v][u] = -flow[u][v];
			}
			else
			{
				flow[v][u] -= push_val;      //basically pushing back some flow from where it came.
				flow[u][v] = -flow[v][u];
			}

			excess[u] -= push_val;
			excess[v] += push_val;		
			cf[u][v] = cap[u][v]-flow[u][v];
			cf[v][u] = cap[v][u]-flow[v][u];
		}
	void discharge(lld u)
		{
			lld i = 0, lim=neighbour[u].size(), v;
			while(excess[u]>0)
			{
				v=neighbour[u][i];
				if(i==lim)
				{
					relabel(u);
					i=0;
				}
				else if(cf[u][v]>0 && height[u]==height[v]+1) push(u, v, ifEdge[u][v]);
				else i++;
			}
		}

	lld relabel_to_front(lld source, lld sink)
		{
			initialize_preflow(source);
			lld i, old_h, t;
			deque<lld> d;
			for(i=1;i<=numV;i++)
			{
				if(i!=source && i!=sink)
					d.push_back(i);
			}
			i=0;
			while(i<numV-2)
			{
				t = d[i];
				old_h = height[t];
				discharge(t);
				if(height[t]>old_h)
				{
					d.erase(d.begin()+i);
					d.push_front(t);
					i = 0;
				}
				i++;
			}
			return excess[sink];
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
	
	lld v,e,a,b,c,i,t;
	inputInt(t);
	while(t--)
	{
		map<lld,lld> x,y;
		lld count=1;
		inputInt(v);
		Graph g(2*v+2);
		for(i=1;i<=v;i++)
		{
			inputInt(a);
			inputInt(b);
			a++;b++;
			if(!present(x,a))
				x[a]=count++;
			if(!present(y,b))
				y[b]=count++;
			g.addEdge(x[a],y[b],1);
		}
		tr(x,it)
			g.addEdge(count,it->second,1);
		count++;
		tr(y,it)
			g.addEdge(it->second,count,1);
		
	
		
		cout<<g.relabel_to_front(count-1,count)<<endl;
	}
}
