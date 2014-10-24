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
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;

vector<lld> prime;
lld size=sqrt(1000000000)+1;

inline void inputInt(lld &n )
{
	n=0;
 	lld ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
		ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
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

bool possible_sum(lld n)
{
	if(n%4!=1)
		return false;
	lld i;
	for(i=0;prime[i]*prime[i]<=n;i++)
	{
		if(n%prime[i]==0)
			return false;
	}
	return true;
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
	if(i==1 || i==0)
		return false;
	if(i==2)
		return true;
	if(miller_rabin(i,2) && miller_rabin(i,3) && miller_rabin(i,5) && miller_rabin(i,7) && miller_rabin(i,11) && miller_rabin(i,13) && miller_rabin(i,17))
		return true;
	return false;
}

int main()
{
	lld t, a, b,count=0,k=0,i;
	inputInt(t);
/*	for(i=0;i<=10000000;i++)
	{
		if(prime_check(i))
			count++;
	}
	cout<<count<<endl;*/
	while(t--)
	{
		inputInt(a);
		inputInt(b);
		count=0;
		i=a;
		for(;i<=b;i++)
		{
			if(i==2)
				count++;
			if(prime_check(i) && i%4==1)
				count++;
		}
		
		printf("%lld\n",count);
	}
}
