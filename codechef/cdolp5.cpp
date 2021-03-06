
//#define DEBUG       //comment when you have to disable all debug macros.
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


/*the flows in flow 2-d vector stores the residual capacity of an edge rather than the flow i.e. it
 deals in terms of  the  residual graph*/
vector<vector<lld> > flow, capacity, copy_flow;
lld V;
vector<lld> *adj;


void init(lld v)
{
	/*aug_path.resize(v+1);
	for(lld i=1;i<=v;i++)
	{
		aug_path[i].resize(v+1);
		for(lld j=1;j<=v;j++)
			aug_path[i][j]=false;
			}*/
	adj=new vector<lld>[v+1];
	V=v;
	flow.resize(V+1);
	capacity.resize(V+1);
	copy_flow.resize(V+1);
	for(lld i=0;i<=V;i++)
		flow[i].resize(V+1), capacity[i].resize(V+1), copy_flow[i].resize(V+1);
}

void add_edge(lld u, lld v, lld uv, lld vu=0)
{
	capacity[u][v]=uv;
	capacity[v][u]=vu;
	adj[u].push_back(v);
	flow[u][v]=uv;
	flow[v][u]=vu;
	if(vu) adj[v].push_back(u);
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
	while(parent[i]!=-2)
	{
		//aug_path[parent[i]][i]=true;
		aug=min(aug,flow[parent[i]][i]);
		i=parent[i];
	}
	i=destination;
	while(parent[i]!=-2)
	{
		flow[parent[i]][i]-=aug;
		flow[i][parent[i]]=capacity[parent[i]][i]-flow[parent[i]][i];
		debug("1:",flow[parent[i]][i],"2:",flow[i][parent[i]], aug);
		i=parent[i];
	}
	
	return true;
}

lld maximum_flow(lld source, lld destination)
{
	while(augmentation(source, destination));
	lld max_flow=0;
	for(vector<lld>::iterator it=adj[source].begin(); it!=adj[source].end(); it++)
	{		max_flow+=flow[*it][source]; debug("yeah!", flow[*it][source]);}
	debug(max_flow);
	return max_flow;
}


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
	lld n,e,u,v,c,i,j,E;
	
	inputInt(n);
	inputInt(e);
	
	init(n);
	E=e;
	while(e--)
	{
		inputInt(u);
		inputInt(v);
		inputInt(c);
		add_edge(u,v,c);
	}
	lld flow_val=maximum_flow(1,n), count=0;
	copy_flow=flow;
	for(i=1;i<=n;i++)
	{
		for(vector<lld>::iterator it=adj[i].begin(); it!=adj[i].end();it++)
		{
			capacity[i][*it]+=1000;
			flow[i][*it]+=1000;
			if(flow_val!=maximum_flow(1,n))
				count++;
			flow=copy_flow;
			capacity[i][*it]-=1000;
			//flow[i][*it]-=1000;
		}
	}
	
	printf("%lld\n", E-count);
	
}
