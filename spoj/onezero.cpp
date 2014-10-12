
#define DEBUG       //comment when you have to disable all debug macros.
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
#define SIZE 20000
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
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

vector<lld> *adj;
lld parent[SIZE];

void init()
{
	adj=new vector<lld>[SIZE];
	memset(parent,-1,sizeof(parent));
}

void clear()
{
	for(lld i=0;i<SIZE;i++)
		adj[i].clear();
	//memset(parent,-1,sizeof(parent));
}

void create_graph(lld n)
{
	lld k,i;
	for(i=0;i<n;i++)
	{
		k=(10*i)%n;
		if(k!=i)
			adj[i].pb(k);
		k=(10*i+1)%n;
		if(k!=i)
			adj[i].pb(k);
	}
	/*cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i<<" ";
		tr(adj[i],it)
			cout<<(*it)<<" ";
		cout<<endl;
		}*/
	
}

void BFS(lld n)
{
	queue<lld> state;
	bool visited[n];
	lld t;
	memset(visited,false,sizeof(visited));
	visited[1]=true;   //dfa simulated with starting state=1
	state.push(1);
	parent[1]=-2;
	while(!state.empty())
	{
		t=state.front();
		state.pop();
		tr(adj[t],it)
		{
			
			if(!visited[*it])
			{
				parent[*it]=t;
				state.push(*it);
				visited[*it]=true;
				if(*it==0)
					goto break_loop;
			}
		}
	}
break_loop:
	t=0;
	/*for(lld i=0;i<n;i++)
	  cout<<parent[i];*/
	string s="";
	lld len=0;
	while(parent[t]!=-2)
	{
		s+=char(((n+t-(parent[t]*10)%n)%n)+'0'); t=parent[t];
		len++;
	}
	//cout<<len<<endl;
	s+="1";
	len++;
	while(len--)
		putchar_unlocked(s[len]);
	printf("\n");	
	//cout<<s<<"\n";
}

int main()
{
	init();
	lld t,n;
	inputInt(t);
	while(t--)
	{
		clear();
		inputInt(n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		create_graph(n);
		BFS(n);
	}
}

