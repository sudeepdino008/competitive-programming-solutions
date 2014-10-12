//prim's algorithm for finding the minimum spanning tree. The algo works for weighted undirected connected graph


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
inline void inputString(string &s)
{
    char ch=getchar_unlocked();
    s="";
    while(ch!='\n')
        s+=ch, ch=getchar_unlocked();
    s+='\0';
}

typedef struct{
		lld u, v, weight;
	}edge;

class edgePriority{
public:
	bool operator()(const edge &e1, const edge &e2)
		{
			return e1.weight>e2.weight;
			
		}
};

struct Graph{

	vector<pair<lld,lld> > *adj;            //maps a node(u) to a pair(node(v), weight)
	priority_queue<edge, vector<edge>, edgePriority> weight_queue; 
	lld V;
	
	Graph(lld _V)
		{
			V = _V;
			adj = new vector<pair<lld,lld> >[V+1];
		}
	
	void addEdge(lld u, lld v, lld weight)
		{
			adj[u].push_back(make_pair(v,weight));
			adj[v].push_back(make_pair(u,weight));
		}
	
	lld Prim(lld root)
		{
			//spanned and unspanned vertices/edges
			set<lld> v_sp;
			set<pair<lld,lld> > e_sp;
			
			v_sp.insert(root);
			tr(adj[root],it)
			{
				edge e={ root, it->first, it->second};
				weight_queue.push(e);
			}
			edge temp_edge;
			lld cost=0;
			while(v_sp.size()!=V)      //note that this means that for unconnected graphs, this loop will never end. 
			{
				temp_edge = weight_queue.top();
				weight_queue.pop();
				
				if(!present(v_sp, temp_edge.v))
				{
					cost+=temp_edge.weight;
					tr(adj[temp_edge.v],it)
					{
						if(!present(v_sp,it->first))
						{
							edge e={temp_edge.v, it->first, it->second};
							weight_queue.push(e);
						}
					}
				}
				v_sp.insert(temp_edge.v);
			}
			return cost;
		}
	
};

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif

		lld e,u,v,w,t,i,n,neigh;
		inputInt(t);
		string s;
		while(t--)
		{
			inputInt(n);
			Graph g(n);
			for(i=1;i<=n;i++)
			{
				inputString(s);
				inputInt(neigh);
				while(neigh--)
				{
					inputInt(v);
					inputInt(w);
					g.addEdge(i,v,w);
				}
			}
			cout<<g.Prim(1)<<"\n";
		}
}

