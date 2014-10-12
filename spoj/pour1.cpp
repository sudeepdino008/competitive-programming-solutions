
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
#define hash(x,y) ((x)*b+y+1)
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


lld a, b, c;



struct Graph{
	lld V; vector<lld> *adj;
	Graph(lld _V)
		{
			V = _V;
			adj = new vector<lld>[V+1];
		}
	void init(lld _V)
		{
			lld i;
			V = _V;
			for(i=0;i<=V;i++)
				adj[i].clear();
		}
	void addEdge(lld u,lld v)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	lld BFS(lld start)
		{
			queue<lld> state;
			bool visited[V+1];
			lld level[V+1], front;
			memset(visited, false, sizeof(visited));
			memset(level, -1, sizeof(level));
			level[start] = 0;
			visited[start] = true;
			state.push(start);
			while(!state.empty())
			{
				front = state.front();
				state.pop();
				tr(adj[front], it)
				{
					if(!visited[*it])
					{
						debug((*it)/b, (*it)%b-1);
						state.push(*it);
						visited[*it] = true;
						level[*it] = level[front]+1;
						if((*it)/b==c || (*it)%b==c+1)
							return level[*it];
					}
				}
			}
			return -1;
		}
};

Graph g(17000);

void fill(lld x, lld y)
{
	//debug(hash(x,y), hash(a,y), hash(x, b));
	if(y!=b)
	{
		g.addEdge(hash(x,y), hash(x,b));
		fill(x,b);
	}
	if(x!=a && y!=0)
	{
		lld x1 = min(a, x+y);
		lld y1 = y-(x1-x);
		g.addEdge(hash(x,y), hash(x1, y1));
		fill(x1, y1);
		g.addEdge(hash(x,y), hash(a, y));
		fill(a, y);
	}
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t;
	 inputInt(t);
	 while(t--)
	 {
		 inputInt(a);
		 inputInt(b);
		 inputInt(c);
		 g.init((a+1)*(b+1));
		 if(a>b)
			 swap(a,b);
		 fill(0,0);
		 if(b==0 || a==c)
			 printf("1\n");
		 else if(b==0)
			 printf("-1\n");
		 else
			 printf("%lld\n", g.BFS(1));
	 }
}


