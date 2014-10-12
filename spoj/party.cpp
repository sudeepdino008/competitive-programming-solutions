
#define DEBUG       //comment when you have to disable all debug macros.
#define NDEBUG    //comment when all assert statements have to be disabled.
//#define LOCAL_TEST
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
inline bool inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
		ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return true;
}

int main()
{
#ifdef LOCAL_TEST
	freopen("input.in","r",stdin);
#endif
	lld W,n,i,j;
	while(inputInt(W) && inputInt(n) && (W|n))
	{
		lld w[n+1],v[n+1],dp[n+1][W+1];
		for(i=1;i<=n;i++)
			inputInt(w[i]),inputInt(v[i]);
		for(i=0;i<=W;i++)
			dp[0][i]=0;
		/*for(i=0;i<=W;i++)
		  dp[1][i]=(i<w[1])?0:v[1], dp[0][i]=0;*/
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=W;j++)
			{
				if(j>=w[i])
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
				else
					dp[i][j]=dp[i-1][j];
				//cout<<dp[i][j]<<" ";
			}
		}
		for(i=W;dp[n][i]==dp[n][W];i--);
		
		
			
		
		printf("%lld %lld\n",i+1,dp[n][W]);
	}
}
