
//#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
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


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	lld t,x_sum,x_odd,y_sum, y_odd,i,x[51],y[51],n,turns,sum_diff,ans;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		x_sum=0;
		for(i=1;i<=n;i++)
		{
			inputInt(x[i]);
			x_sum+=x[i];
		}
		
		y_sum=0;
		for(i=1;i<=n;i++)
		{
			inputInt(y[i]);
			y_sum+=y[i];
		}
		sum_diff=y_sum-x_sum;
		ans=-1;
		if(n==1 && sum_diff<=0)
			ans=abs(sum_diff);
		else if(sum_diff>=0 && ((n==2 && sum_diff==0) || (n>2 && sum_diff%(n-2)==0)))
		{
			turns=(n!=2)?(sum_diff/(n-2)):((x[1]+x[2]==y[1]+y[2])?abs(x[1]-y[1]):-1);
			lld sum=0;
			if(turns!=-1)
			{
				for(i=1;i<=n;i++)
				{
					if(turns+x[i]-y[i]>=0 && (turns+x[i]-y[i])%2==0)
						sum+=(turns+x[i]-y[i])/2;
					else {turns=-1;break;}
				}
				//ans=(turns==sum)?turns:-1;
				ans=turns;
			}
			ans=turns;
		}
		
		
		
		
		printf("%lld\n",ans);
	}
}

