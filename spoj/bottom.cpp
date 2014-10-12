
#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL
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


	Graph(lld _V){
		V=_V;
		adj=new vector<lld>[V+1];
		auxiliary=new vector<lld>[V+1];
	}

	void addEdge(lld u, lld v){
		adj[u].push_back(v);
		auxiliary[v].push_back(u);
	}

	void DFS(lld u, bool *visited,deque<lld> &nodes){
		visited[u]=true;
		lld t;
		stack<lld> state;
		bool present;
		state.push(u);

		while(!state.empty())
		{
			t=state.top();
			present=false;
			visited[t]=true;
			for(vector<lld>::iterator it=adj[t].begin();it!=adj[t].end();it++)
			{
				if(!visited[*it])
				{
					state.push(*it);
					present=true;
					break;
				}
			}
				
			if(!present)
			{
				nodes.push_front(t);
				state.pop();
			}
		}
	}

	void DFSutil(lld u,bool *visited,set<lld> &members)
	{
		visited[u]=true;
		stack<lld> state;
		lld t;

		state.push(u);
		while(!state.empty())
		{
			t=state.top();
			members.insert(t);
			state.pop();
			visited[t]=true;
			for(vector<lld>::iterator it=auxiliary[t].begin();it!=auxiliary[t].end();it++)
			{
				if(!visited[*it])
					state.push(*it);
			}
		}
	}
	void kosaraju()
	{
		bool visited[V+1];
		memset(visited,false,sizeof(visited));
		deque<lld> component_node;
		stack<lld> nodes;
		lld i,t,count=0;
		for(i=1;i<=V;i++)
		{
		
			if(!visited[i])
			{
				DFS(i,visited,component_node);
				while(!component_node.empty())
				{
					nodes.push(component_node.back());
					component_node.pop_back();
				}
			}
			
		}
		// while(!nodes.empty())
		// {
		// 	debug("l",nodes.top());nodes.pop();
		// 	}
		//debug("phew");
		//run DFS on the auxiliary(transposed) graph
		set<lld> members;
		vector<lld> answers;
		lld root[V+1];

		memset(visited,false,sizeof(visited));
		while(!nodes.empty())
		{
			t=nodes.top();
			nodes.pop();
			//debug(":)",t);
			members.clear();
			if(!visited[t])
			{
				DFSutil(t,visited,members);
				set<lld>::iterator it;
				for(it=members.begin();it!=members.end();it++)
				{
					//debug(":(",*it, t);
					vector<lld>::iterator itt;
					for(itt=adj[*it].begin();itt!=adj[*it].end();itt++)
					{
						if(!present(members,*itt))
							break;
					}
					if(itt!=adj[*it].end())
						break;
				}
				if(it==members.end())
				{
					tr(members,it)
						answers.pb(*it);
				}
			}

		}
		

		sort(answers.begin(),answers.end());
		tr(answers,it)
			printf("%lld ",*it);
		printf("\n");
	}

};


template<class T>
inline void inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld v,e,a,b,i;
	inputInt(v);
	while(v!=0)
	{
		Graph g(v);
		inputInt(e);
		for(i=1;i<=e;i++)
		{
			inputInt(a);
			inputInt(b);
			g.addEdge(a,b);
		}
		g.kosaraju();
		inputInt(v);
	}
	
}

