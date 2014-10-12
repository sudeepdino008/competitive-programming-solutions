
//#define GRAPH
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
#define sc(n) scanf("%lld",&n)
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

bool compFunc(queue<lld> q1, queue<lld> q2)
{
	return q1.front()< q2.front();
}

struct Graph{
	
	vector<lld> *reverse_adj;
	lld V;
	
	Graph(lld _V){
		V = _V;
		reverse_adj = new vector<lld>[V+1];
	}
	
	void addEdge(lld u, lld v){
		reverse_adj[v].push_back(u);
	}
	
	void topologicalSortUtil(lld start, bool *visited, queue<lld> &sortedOrder)
		{
			stack<lld> node;
			lld t;
			bool flag;
			node.push(start);
			visited[start] = true;
			while(!node.empty())
			{
				t = node.top();
				flag = false;
				tr(reverse_adj[t],it)
				{
				
					if(!visited[*it])
					{
						visited[*it] = true;
						node.push(*it);
						flag = true;
						break;
					}
				}
				if(!flag)
				{
					sortedOrder.push(t);
					node.pop();
				}
			}
		}
	
	void topologicalSort()
		{
			lld i;
			for(i=1;i<=V;i++)
				sort(reverse_adj[i].begin(), reverse_adj[i].end());
			for(i=1;i<=V;i++)
			{
				cout<<i<<":";
				tr(reverse_adj[i],it)
					cout<<(*it)<<" ";
				cout<<endl;
			}
			bool visited[V+1];
			queue<lld> sortedOrder;
			vector<queue<lld> > vqueue;
			memset(visited,false,sizeof(visited));

			for(i=1;i<=V;i++)
			{
				if(!visited[i])
				{
					topologicalSortUtil(i, visited, sortedOrder);
					vqueue.pb(sortedOrder);
					sortedOrder = queue<lld>();
				}
			}
			
			//sort(vqueue.begin(), vqueue.end(), compFunc);
			tr(vqueue,it)
			{
				while(!it->empty())
				{
					printf("%lld ", it->front());
					it->pop();
				}
				cout<<endl;
			}
		}
};


int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld n,m,k,t0,t1;
	sc(n);
	sc(m);
	Graph g(n);
	while(m--)
	{
	sc(t0);
	sc(k);
	while(k--)
		sc(t1), g.addEdge(t1, t0);
}
	g.topologicalSort();
}

