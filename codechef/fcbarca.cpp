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
	lld t,n,k,i;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		inputInt(k);
		lld dp[n+1];
		dp[0]=1;
		dp[1]=0;
		for(i=2;i<=n;i++)
			dp[i]=((k*dp[i-2])%MOD+((k-1)*dp[i-1])%MOD)%MOD;
		printf("%lld\n",dp[n]);
	}
}
