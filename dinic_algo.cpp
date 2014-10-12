
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
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


/**********************************MAIN CODE***************************************************/

//runs in O(V^2E) time.
//might consider using a 1-d array of size V*V for large values of V

vector<vector<lld> > flow, capacity, level_graph, copy_flow;
lld V;
vector<lld> *adj, *level_adj;

void init(lld v)
{
	adj=new vector<lld>[v+1];
	level_adj=new vector<lld>[v+1];   
	V=v;
	flow.resize(V+1);
	copy_flow.resize(V+1);
	capacity.resize(V+1);
	level_graph.resize(V+1);
	for(lld i=0;i<=V;i++)
		copy_flow[i].resize(V+1), flow[i].resize(V+1), capacity[i].resize(V+1), level_graph[i].resize(V+1);
}

void add_edge(lld u, lld v, lld uv, lld vu=0)
{
	capacity[u][v]=uv;
	capacity[v][u]=vu;
	adj[u].push_back(v);
	flow[u][v]=uv;             //will store the present capacity. facility for the residual graph
	flow[v][u]=vu;
	if(vu) adj[v].push_back(u);
}

void update_residual_graph(lld source, lld destination, lld *parent)        //push augment flow in the residual graph and modify the latter.
{
	//debug("hello");
	lld i=destination, aug=LLONG_MAX;
	while(parent[i]!=-2)
	{
		aug=min(aug,flow[parent[i]][i]);
		i=parent[i];
	}
	i=destination;
	while(parent[i]!=-2)
	{
		flow[parent[i]][i]-=aug;
		flow[i][parent[i]]=capacity[parent[i]][i]-flow[parent[i]][i];
		level_graph[i][parent[i]]-=aug;
		i=parent[i];
	}
}

bool DFS(lld source, lld destination)
{
	stack<lld> state;
	bool visited[V+1], present;
	lld parent[V+1],t;
	memset(visited, false, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	parent[source]=-2;
	state.push(source);
	visited[source]=true;
	while(!state.empty())
	{
		t=state.top();
		present=false;
		for(vector<lld>::iterator it=level_adj[t].begin(); it!=level_adj[t].end();it++)
		{			
			if(level_graph[t][*it])
				parent[*it]=t;
			if(!visited[*it] && level_graph[t][*it])
			{
				present=true;
				state.push(*it);
				visited[*it]=true;
				if(*it==destination)
					update_residual_graph(source,destination,parent);   //update residual graph
					//goto ret;
			}

		}
		if(!present)
			state.pop();
	}

	return parent[destination]!=-1;
}


bool BFS(lld source, lld destination)
{
	//create level graph usign BFS
	fill(level_graph.begin(), level_graph.end(), vector<lld>(V+1,-1));
	lld i,j;
	for(i=1;i<=V;i++)
		level_adj[i].clear();
		
	
	queue<lld> state;
	lld level[V+1],t;      //record of minimum distance from source
	memset(level,-1, sizeof(level));
	state.push(source);
	level[source]=0;

	while(!state.empty())
	{
		t=state.front();
		state.pop();
		for(vector<lld>::iterator it=adj[t].begin();it!=adj[t].end();it++)
		{
			if((level[*it]==-1  || level[*it]==level[t]+1) && flow[t][*it])
			{
				level_graph[t][*it]=flow[t][*it];
				level_adj[t].push_back(*it);
				level[*it]=level[t]+1;
				state.push(*it);
			}
		}
	}
	
	if(level[destination]==-1)
		return false;

	//call DFS and update the residual graph
	return DFS(source,destination);
	
}


lld maximum_flow(lld source, lld destination)
{
	while(BFS(source,destination));
	lld max_flow=0;
	for(vector<lld>::iterator it=adj[source].begin(); it!=adj[source].end(); it++)
		max_flow+=flow[*it][source];
	return max_flow;
}



int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	lld e,u,v,n,c;
	//cout<<"V:"<<endl;
	cin>>n>>e;
	init(n);
	
	while(e--)cin>>u>>v>>c, add_edge(u,v,c);
	cout<<maximum_flow(1,n)<<endl;
}
