
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL
#define NDEBUG    //comment when all assert statements have to be disabled.
#include <iostream>
#include <cstring>
#include <sstream>
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

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
	{    
		cerr<<v<<" ";    
		return *this;    
	}

}dbg;

struct Graph{
	lld V;
	vector<lld> *adj;
	vector<lld> *auxiliary;
	typedef struct s{
		lld t;
		lld index;
		bool operator<(const s &a) const
		{
			return (a.t)<t;
		}
	}time;
	vector<time> finish, discover;
	vector<vector<lld> > components;
	

	Graph(lld V_)
	{
		V=V_;
		adj=new vector<lld>[V+1];
		auxiliary=new vector<lld>[V+1];
		//finish=new time[V+1];
		//discover=new time[V+1];
		finish.resize(V+1);
		discover.resize(V+1);
		for(lld i=1;i<=V;i++)                  //pointer problem with memset
		{
			finish[i].index=discover[i].index=i;
			finish[i].t=discover[i].t=-1;
		}
	}
	void addEdge(lld u, lld v)
	{
		adj[u].push_back(v);
		auxiliary[v].push_back(u);
	}
	lld DFS(lld u, bool *visited,lld &count)
	{
		visited[u]=true;
		lld t;
		stack<lld> state;
		bool present;
		state.push(u);
		while(!state.empty())
		{
			t=state.top();
			if(discover[t].t==-1)            //discover the present node
				discover[t].t=count++;
			visited[t]=true;
			present=false;
			for(vector<lld>::iterator it=adj[t].begin();it!=adj[t].end();it++)
			{
				if(!visited[*it])
				{
					visited[*it]=true;
					state.push(*it);
					present=true;
				}
			}
			if(!present)
			{
				finish[state.top()].t=count++;         //if it produces no children, it is finished.
				state.pop();
			}
			
		}
	}
	void computeTime()       //run DFS and compute discovery and finish time
	{
		bool visited[V+1];
		lld count=1,i;
		memset(visited,false,sizeof(visited));
		for(i=1;i<=V;i++)
		{
			if(!visited[i])
				DFS(i,visited,count);
		}
	}
	void DFS_traversal(lld u, bool *visited,vector<lld> &members)
	{
		visited[u]=true;
		stack<lld> state;
		bool present;
		lld t;
		state.push(u);
		while(!state.empty())
		{
			t=state.top();
			present=false;
			for(vector<lld>::iterator it=auxiliary[t].begin();it!=auxiliary[t].end();it++)
			{
				if(!visited[*it])
				{
					state.push(*it);
					visited[*it]=true;
					present=true;
				}
			}
			if(!present)
			{
				members.push_back(state.top());
				state.pop();
			}
		}
	}
	void tarjan()
	{
		computeTime();
		sort(finish.begin()+1, finish.end());
		lld i,id;
		bool visited[V+1];
		memset(visited,false,sizeof(visited));
		vector<vector<lld> > components;
		vector<lld> members;              //will store the members of each individual components
		
		for(i=1;i<=V;i++)
		{
			id=finish[i].index;
			//id=i;
			if(!visited[id])
			{
				members.clear();
				DFS_traversal(id,visited,members);
				components.push_back(members);

				for(vector<lld>::iterator it=members.begin();it!=members.end();it++)
					cout<<(*it)<<" ";
				cout<<endl;
			}
		}
		
	}
};


int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld v,e,a,b;
	cin>>v>>e;
	Graph g(v);
	while(e--)
	{
		cin>>a>>b;
		g.addEdge(a,b);
	}
	g.tarjan();
}

