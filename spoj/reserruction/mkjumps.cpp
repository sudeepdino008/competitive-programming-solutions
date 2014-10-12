
//#define GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
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
#define LIMIT 10
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

inline int mapVal(int i, int j){
	return (i-1)*LIMIT+j;
}

class Graph{
private:
	int V;
	int s;
	vector<int> *adj;
	bool *visited;
	int maxDistance;
	int dfs(int v);
public:
	Graph(int V);
	void addEdge(int u, int v);
	int answer();
};

Graph::Graph(int V){
	maxDistance = 0;
	this->V = V;
	adj = new vector<int>[V+1];
	visited = new bool[V+1];
	for(int i=0;i<=V;i++)visited[i]=false;
	s = V+1;
}

void Graph::addEdge(int u, int v){
	adj[u].pb(v);
	s = min(u,s);
}

int Graph::dfs(int u){
	int count=0;
	visited[u] = true;
	tr(adj[u],it)if(!visited[*it])count=max(count,dfs(*it));
	visited[u] = false;
	maxDistance = max(maxDistance,1+count);  
	return count+1;
}

int Graph::answer(){
	dfs(s);
	return this->maxDistance;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 int n,a,b,i,j,u,m[9],count,p=1;
	 
	 inputInt(n);
	 while(n){
		 Graph g(LIMIT*LIMIT);
		 bool arr[LIMIT*LIMIT+2*LIMIT+2];
		 for(i=0;i<=LIMIT*LIMIT+2*LIMIT+2;i++)arr[i]=false;
		 count=0;
		 for(i=1;i<=n;i++){
			 inputInt(a);
			 inputInt(b);
			 for(j=a+1;j<=a+b;j++){
				 u = mapVal(i,j);    //u is a node, do what you want to
				 arr[u] = true;
				 count++;
			 }
		 }
		 for(i=1;i<=LIMIT*LIMIT;i++){
			 if(arr[i]){
				 m[1] = max(i-2*LIMIT-1,0);
				 m[2] = max(i-2*LIMIT+1,0);
				 m[3] = max(i-LIMIT-2,0);
				 m[4] = max(i-LIMIT+2,0);
				 m[5] = max(i+LIMIT-2,0);
				 m[6] = max(i+LIMIT+2,0);
				 m[7] = max(i+2*LIMIT-1,0);
				 m[8] = max(i+2*LIMIT+1,0);
				 for(j=1;j<=8;j++)if(arr[m[j]])g.addEdge(i,m[j]);
			 }
		 }
		 int f = g.answer();
		 debug(count,f,count-f);
		 if(count-f!=1)
			 printf("Case %d, %d squares can not be reached.\n",p++,count-f);
		 else printf("Case %d, 1 square can not be reached.\n",p++);
		 inputInt(n);
	 }
	 
}

