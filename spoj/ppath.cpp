//BFS and DFA


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
#define SIZE 10000
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



set<lld> primes;
vector<lld> arr;
vector<lld> *adj;
void init()
{
	arr.pb(-1);
	lld count=0,i,j;
	vector<lld> cop;
	cop.pb(-1);
	cop.pb(-1);
	for(i=2;i<=SIZE;i++)
		cop.pb(i);
	for(i=2;i<=SIZE;i++)
	{
		if(cop[i]!=-1)
		{
			if(i>=1000)
			{
				primes.insert(i);
				arr.pb(i);
			}
			for(j=2*i;j<=SIZE;j+=i)
				cop[j]=-1;
		}
	}
	adj=new vector<lld>[arr.size()];
}



void form_graph()
{
	lld size=arr.size()-1,i,power,k,idx,index,pos,val;
	for(i=1;i<=size;i++)
	{
		power=1;
		set<lld> there;
		for(pos=1;pos<=4;pos++)
		{
			for(val=0;val<10;val++)
			{
				k=arr[i]-power*((arr[i]/power)%10)+power*val;
				if(present(primes, k) && k!=arr[i])
				{
					idx=lower_bound(arr.begin(), arr.end(),k)-arr.begin();
					if(!present(there,arr[idx]))
						adj[i].pb(idx);
					there.insert(arr[idx]);
				}
			}
			power=power*10;
		}
	}

}

#define index(v) (lower_bound(arr.begin(), arr.end(), v)-arr.begin())
lld BFS(lld source, lld destination)
{
	lld len=arr.size();
	queue<lld> state;
	lld parent[len], level[len],t;
	memset(parent,-1,sizeof(parent));
	memset(level,-1,sizeof(level));
	source=index(source);
	destination=index(destination);
	parent[source]=-2;
	level[source]=0;
	state.push(source);
	
	while(!state.empty())
	{
		t=state.front();
		state.pop();
		tr(adj[t],it)
		{
			if(level[*it]==-1)
			{
				level[*it]=level[t]+1;
				parent[*it]=t;
				state.push(*it);
				if(*it==destination)
				{
					t=destination;
					return level[*it];
				}
			}
		}
	}
	return 0;
}

int main()
{
	init();
	form_graph();
	lld t,a,b;
	inputInt(t);
	while(t--)
	{
		inputInt(a);
		inputInt(b);
		printf("%lld\n",BFS(a,b));
	}
}
