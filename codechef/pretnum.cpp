
//#include GRAPH
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
#define lld  long long int
#define MOD 1000000007
#define gcd __gcd
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
#define SIZE 1e6
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
void init()
{
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


lld expo(lld a, lld n, lld p)
{
	if(n==0)
		return 1;
	lld ex=expo(a,n/2,p);
	if(n%2==1)
		return (((ex*ex)%p)*a)%p;
	else
		return (ex*ex)%p;
}

bool miller_rabin(lld n, lld a)
{
	if(n==2)
		return true;
	/*let n be the test value and 2<=a<=n-1. I find n-1=2^s*d. (a^d)%n=+1 or -1, return true; else check for (a^(2^i*d))%n=-1 for atleast one 2<=i<=s-1. If yes return true.*/
	  
	lld s,d,test;
	if(a>n-1)
		return true;
	d=n-1;
	s=0;
	while(d%2==0)
		s++, d=d/2;
	test=expo(a,d,n);
	if(test==1 || test==n-1)
		return true;
	while(s--)
	{
		test=expo(a,(1<<s)*d,n);
		if(test==n-1)
			return true;
	}
	return false;
}

bool prime_check(int i)
{
	if(i==1)
		return false;
	if(i==2)
		return true;
	if(miller_rabin(i,2) && miller_rabin(i,3) && miller_rabin(i,5) && miller_rabin(i,7) && miller_rabin(i,11) && miller_rabin(i,13) && miller_rabin(i,17))
		return true;
	return false;
}


int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	init();
	lld t, L, R, upper, lower, count, i, ans, k;
	inputInt(t);
	while(t--)
	{
		inputInt(L);
		inputInt(R);
		ans =0;
		for(i=max(L,(lld)2);i<=R;i++)
		{
			lld j = i;
			if(binary_search(all(primes), j))  //if j<1e6 && prime
			{
				ans++;
				continue;
			}
			if(j>1e6 && prime_check(j))   //if j>1e6 && prime
			{
				ans++;
				continue;
			}
			//power of a prime
			for(k=1;k<15;k++)
			{
				
			}

		printf("%lld\n", ans);
	}
	
}

