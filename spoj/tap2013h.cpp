
//#include GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL     //uncomment for testing from local file
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
#define SIZE 1000000
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




vector<lld> primes;
vector<lld> maps;

void init()
{
	maps.pb(-1);
	maps.pb(-1);
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
			primes.pb(i);
			for(j=2*i;j<=SIZE;j+=i)
				cop[j]=-1;
		}
	}

}

void calculate(lld n)
{
	lld k, sum=0,p=n;
	tr(primes, it)
	{
		k=*it;
		if(n%k==0)
		{
			sum+=k;
			while(n%k==0)
				n/=k;
			if(n==1)
			{
				/*if(sum==p)
				  debug(sum,k,p);*/
				if(sum==p)
					maps.pb(1);
				else maps.pb(maps[sum]+1);
				break;
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	init();
	lld i;
	for(i=2;i<=1000000;i++)
		calculate(i);
	lld t,a,b,k;
	inputInt(t);
	while(t--)
	{
		inputInt(a);
		inputInt(b);
		inputInt(k);
		printf("1\n");
	}
/*	tr(maps,it)
	debug(*it);*/
}

