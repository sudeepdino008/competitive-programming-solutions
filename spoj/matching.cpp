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

struct Graph{

	lld **flow, **capacity;
	lld V;
	vector<lld> *adj;
	set<pair<lld, lld> > ifEdge;      //if edge is present between u and v. Required since new edges are continually added to the graph. Hence this is required to monitor whether an edge had already been added

	Graph(lld v)
		{
			adj=new vector<lld>[v+1];
			V=v;
			//flow.resize(V+1);
			//capacity.resize(V+1);
			flow = new lld*[V+1];
			capacity = new lld*[V+1];
			for(lld i=0;i<=V;i++)
				flow[i] = new lld[V+1], capacity[i] = new lld[V+1];
		}
	void addEdge(lld u, lld v, lld uv, lld vu=0)
		{
			capacity[u][v]=uv;
			capacity[v][u]=vu;
			ifEdge.insert(make_pair(u,v));
			adj[u].push_back(v);
			flow[u][v]=uv;
			flow[v][u]=vu;
			if(vu) 
			{
				adj[v].push_back(u);
				ifEdge.insert(make_pair(v,u));
			}
		}

/*if there is an augmentation path, it returns true and modifies the graph(flow matrix) creating residual graph. Operates only on one edge, need to be called several times. 
  If no augmentation path exists, returns false.*/
	bool augmentation(lld source, lld destination)   
		{
			bool visited[V+1], present;
			lld parent[V+1], t;
			memset(visited, false, sizeof(visited));
			memset(parent, -1, sizeof(parent));
			stack<lld> state;
			state.push(source);
			parent[source]=-2;

			while(!state.empty())
			{
				t=state.top();
				visited[t]=true;
				present=false;
				for(vector<lld>::iterator it=adj[t].begin(); it!=adj[t].end(); it++)
				{
					if(!visited[*it] && flow[t][*it])
					{
						state.push(*it);
						parent[*it]=t;
						present=true;
						if(*it==destination)
							goto augmentation_present;
						break;
					}
				}
				if(!present)
					state.pop();
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
				if(!present(ifEdge, make_pair(i,parent[i])))                   //introduce new back edge in the adj graph only if it is not already included.
				{
					adj[i].push_back(parent[i]);
					ifEdge.insert(make_pair(i, parent[i]));
				}
				flow[i][parent[i]]+=aug;		
				i=parent[i];
			}
			return true;
		}

	lld max_flow(lld source, lld destination)
		{
			if(source==destination)
				return 0;
			while(augmentation(source, destination));
			lld max_flow=0;
			for(vector<lld>::iterator it=adj[source].begin(); it!=adj[source].end(); it++)
				max_flow+=flow[*it][source];
			return max_flow;
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
	lld n,m,p,u,v,i;
	inputInt(n);
	inputInt(m);
	inputInt(p);
	bool theren[n+1], therem[m+1];
	for(i=1;i<=n;i++)
		theren[i]=false;
	for(i=1;i<=m;i++)
		therem[i]=false;
	Graph g(n+m+2);
	while(p--)
	{
		inputInt(u);
		inputInt(v);
		theren[u]=true;
		therem[v]=true;
		g.addEdge(u,n+v,1);
	}
	for(i=1;i<=n;i++)
	{
		if(theren[i])
			g.addEdge(n+m+1, i, 1);
	}
	for(i=1;i<=m;i++)
	{
		if(therem[i])
			g.addEdge(n+i, n+m+2, 1);
	}
	cout<<g.max_flow(n+m+1, n+m+2)<<"\n";
}

