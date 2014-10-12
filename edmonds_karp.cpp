//checked

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

//runs in O(VE^2) time.
//might consider using a 1-d array of size V*V for large values of V

vector<vector<lld> > flow, capacity;
lld V;
vector<lld> *adj;
vector<vector<bool> > ifEdge;      //if edge is present between u and v. Required since new edges are continually added to the graph. Hence this is required to monitor whether an edge had already been added

void init(lld v)
{
	adj=new vector<lld>[v+1];
	V=v;
	flow.resize(V+1);
	capacity.resize(V+1);
	ifEdge.resize(V+1);
	for(lld i=0;i<=V;i++)
		flow[i].resize(V+1), capacity[i].resize(V+1), ifEdge[i].resize(V+1);
}

void add_edge(lld u, lld v, lld uv, lld vu=0)
{
	capacity[u][v]=uv;
	capacity[v][u]=vu;
	ifEdge[u][v]=true;
	adj[u].push_back(v);
	flow[u][v]=uv;
	flow[v][u]=vu;
	if(vu) 
	{
		adj[v].push_back(u);
		ifEdge[v][u]=true;
	}
}

/*if there is an augmentation path, it returns true and modifies the graph(flow matrix) creating residual graph. Operates only on one edge, need to be called several times. 
  If no augmentation path exists, returns false.*/
bool augmentation(lld source, lld destination)   
{
	bool visited[V+1];
	lld parent[V+1], t;
	memset(visited, false, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	queue<lld> state;
	state.push(source);
	visited[source]=true;
	parent[source]=-2;

	while(!state.empty())
	{
		t=state.front();
		state.pop();
		for(vector<lld>::iterator it=adj[t].begin(); it!=adj[t].end(); it++)
		{
			if(!visited[*it] && flow[t][*it])
			{
				state.push(*it);
				parent[*it]=t;
				visited[*it]=true;
				if(*it==destination)
					goto augmentation_present;
			}
		}
	}
	return false;
augmentation_present:
	//firstly calculate the residual capacity
	lld i=destination;
	lld aug=LLONG_MAX; //residual capacity of the given path
	while(i!=source)
	{
		aug=min(aug,flow[parent[i]][i]);
		i=parent[i];
	}
	i=destination;
	while(i!=source)
	{
		flow[parent[i]][i]-=aug;
		if(!ifEdge[i][parent[i]])                   //introduce new back edge in the adj graph only if it is not already included.
		{
			adj[i].push_back(parent[i]);
			ifEdge[i][parent[i]]=true;
		}
		flow[i][parent[i]]+=aug;		
		i=parent[i];
	}
	return true;
}

lld maximum_flow(lld source, lld destination)
{
	if(source==destination)
		return 0;
	while(augmentation(source, destination));
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
	lld v,e,a,b,c,i;
	cin>>v>>e;
	init(v);
	while(e--)
	{
		cin>>a>>b>>c;
		add_edge(a,b,c);
    }
	cout<<maximum_flow(1,v)<<endl;


}
