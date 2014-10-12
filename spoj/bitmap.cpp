
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
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
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

#define INDEX(i,j) (((i)-1)*m+(j))

vector<lld> *adj;
vector<lld> doori;
bool *color;
lld V, n, m;

void init()
{
	adj=new vector<lld>[200*200+1];
	color = new bool[200*200+1];
	doori.resize(200*200+1);
}

void clear()
{
	for(lld i=1;i<=n*m;i++)
	{
		adj[i].clear();
		doori[i]=INT_MAX;
	}

	//memset(parent,-1,sizeof(parent));
	memset(color,false,sizeof(color));
}

void insertEdge(lld u, lld v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

void BFS(lld start)
{
	queue<lld> state;
	bool visited[n*m+1];
	lld t;
	memset(visited,false,sizeof(visited));
	visited[start]=true;   //dfa simulated with starting state=1
	doori[start]=0;
	state.push(start);

	while(!state.empty())
	{
		t=state.front();
		state.pop();
		tr(adj[t],it)
		{
							debug(t,*it, doori[t]+1, doori[*it]);
			if(!visited[*it])
			{

				if(doori[t]+1<doori[*it])
				{

					doori[*it]=doori[t]+1;
					state.push(*it);
				}
				visited[*it]=true;
			}
		}
	}
 

}


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
		lld t; lld mat[200][200],i,j;
		inputInt(t);
		init();
		while(t--)
		{
			inputInt(n);
			inputInt(m);
			clear();


			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
					color[INDEX(i,j)]=(getchar_unlocked()=='0')?0:1;
				getchar_unlocked();
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if(i!=n)
						insertEdge(INDEX(i,j), INDEX(i+1,j));
					if(j!=m)
						insertEdge(INDEX(i,j), INDEX(i,j+1));
				}
			}


			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if(color[INDEX(i,j)])
					{
						doori[INDEX(i,j)]=0;
						BFS(INDEX(i,j));
					}
				}
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
					printf("%lld ",doori[INDEX(i,j)]);
				printf("\n");
			}

		}
}

