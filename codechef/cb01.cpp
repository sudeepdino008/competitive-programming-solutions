
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
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
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

lld inverse_modulo(lld a, lld m)
{
	return expo(a,m-2,m);
}

lld combi(lld n, lld k,lld m)
{
	if(n<k)
		return 0;
	if(n-k<k)
		return combi(n,n-k,m);
	lld i,p=1,t=1;
	for(i=n-k+1;i<=n;i++)
		p=(p*i)%m;
	for(i=1;i<=k;i++)
		t=(t*i)%m;
	return (p*inverse_modulo(t,m))%m;
}

lld lucas(lld n, lld k, lld m)
{
	if(n<k)
		return 0;
	if(k==0 || n==k)
		return 1;
	return (lucas(n/m,k/m,m)*combi(n%m,k%m,m))%m;
}

int main()
{
	lld t,n,k;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		inputInt(k);
		printf("%lld\n",lucas(n,k,1009));
	}
}
