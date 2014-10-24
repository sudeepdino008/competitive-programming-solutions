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

lld multiplicative_inverse(int p1, int p2)
{
	return expo(p1, p2-2, p2);
}

inline void inputInt(lld &n )
{
	n=0;
 	lld ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
	lld t, t1, t2, p1, p2;
	inputInt(t);
	while(t--)
	{
		lld s=0;
		inputInt(p1);
		inputInt(p2);
		t1=multiplicative_inverse(p1,p2);
		t2=-(p1*t1-1)/p2;
		t2=-(t2+1);
		s+=t2*p2;
		t2=multiplicative_inverse(p2,p1);
		t1=-(p2*t2-1)/p1;
		t1=-(t1+1);
		s+=t1*p1;
		printf("%lld\n",s+1);
	}
}
