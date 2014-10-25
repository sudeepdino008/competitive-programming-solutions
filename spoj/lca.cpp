//LCA of 2 nodes in a tree

//#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
//#include GRAPH
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
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

template<class T>
inline void inputInt(T &n )
{
	n=0;

 	T ch=getchar_unlocked();
	/*int sign=1;
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
		 n*=sign;*/
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}
typedef struct G{           //assume that root is node=1
	vector<lld> *adj, *p;
	lld *parent, *height;
	lld V,logV;
	
	G(lld _V){
		V = _V;
		adj = new vector<lld>[V+1];
		p = new vector<lld>[V+1];
		logV = 0;
		for(;1<<logV<=_V;logV++);logV--;
		for(lld i=1;i<=V;i++)p[i].resize(logV+1);
		parent = new lld[V+1];
		height = new lld[V+1];
	}
	
	void addEdge(lld u, lld v){
		adj[u].pb(v);
//		adj[v].pb(u);
	}
	
	void processLCA(lld root){  //compute parent and height function.
		queue<lld> nodes;
		bool visited[V+1];
		lld i,j;
		clr(visited, false);
		nodes.push(root);
		visited[root] = true;
		height[root] = 1;
		parent[root] = -1;
		for(i=1;i<=V;i++)for(j=0;j<=logV;j++)p[i][j] = -1;
		while(!nodes.empty()){
			lld k = nodes.front();
			tr(adj[k], it){
				if(!visited[*it]){
					visited[*it] = true;
					nodes.push(*it);
					parent[*it] = k;
					height[*it] = height[k]+1;
					p[*it][0] = k;
					for(i=1;1<<i<height[*it];i++)p[*it][i] = p[p[*it][i-1]][i-1];
				}
			}
			nodes.pop();
		}
	}
	
	lld query(lld x, lld y){
		if(height[x]>height[y])swap(x,y);
		lld i;
		for(i=logV;i>=0;i--)if(height[y]-height[x]>=1<<i)y=p[y][i];
		if(x==y)return x;
		for(i=logV;i>=0;i--)
			if(p[x][i]!=-1 && p[x][i]!=p[y][i])x=p[x][i], y=p[y][i];
		return parent[x];
	}
	
}Graph;


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld m,n,i,u,v,t,root,j=1,q;  //number of nodes in tree
	 inputInt(t);
	 while(t--){
		 inputInt(n);
		 Graph g(n);
		 root = 0;
		 for(i=1;i<=n;i++){
			 inputInt(m);
			 while(m--)
			 {
				 inputInt(u);
				 root+=u;
				 g.addEdge(i,u);
			 }
		 }
		 root=(n*(n+1))/2-root;
		 g.processLCA(root);
		 inputInt(q);
		 printf("Case %lld:\n",j++);
		 while(q--){
			 inputInt(u);
			 inputInt(v);
			 printf("%lld\n",g.query(u,v));
		 }
	 }
}

