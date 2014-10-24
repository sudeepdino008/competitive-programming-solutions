

#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
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
	int sign=1;
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
	// while( ch < '0' || ch > '9')
   //    ch=getchar_unlocked();
	// while(  ch >= '0' && ch <= '9' )
	// 	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}



#define SIZE 1000000
vector<lld> primes;
void init()
{
	lld i,j;
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



lld expo(lld a, lld n, lld m)
{
	if(n==0)
		return 1;
	lld p=expo(a,n/2,m);
	if(n%2==0)
		return (p*p)%m;
	else
		return (((p*p)%m)*a)%m;
}

lld phi(lld a){
	lld  val=a,i;
	for(i=2;i*i<=a;i++)
	{
		if(a%i==0)
			val-=val/i;
		while(a%i==0)a/=i;
	}
	if(a>1)val-=val/a;
	return val;
}

lld inverse_modulo(lld a, lld m)
{
	return expo(a,phi(m)-1,m);
}



int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t,a,b,x;
	 inputInt(t);
	 //debug("aaa",numOfFactors(101));
	 //init();
	 while(t--){
		 inputInt(a);inputInt(b);inputInt(x);
		 if(b>=0)printf("%lld\n",expo(a,b,x));
		 else printf("%lld\n",expo(inverse_modulo(a,x),-b,x));
	 }
}

