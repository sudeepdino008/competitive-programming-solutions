
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
	lld t,n,i,j,count,count_2,count_3;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		lld x[n+1], y[n+1];
		for(i=1;i<=n;i++)
			inputInt(x[i]);
		for(i=1;i<=n;i++)
			inputInt(y[i]);
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);

		count=0;
		j=1;
		for(i=1;i<=n && x[i]==1;i++);     //skip the ones, no use
		for(j=1;j<=n && y[j]==1;j++);    //count no. of ones of sasha
		count+=(j-1)*(n-i+1);               //add wins of type (x,1) where x not equal to 1
		debug(count);
		lld count_2_x=0;
		for(;i<=n && x[i]==2;i++)count_2_x++;   //skip the 2 in x
		count_3=0;
		count_2=0;
		for(;i<=n && x[i]==3;i++)count_3++;
		for(;j<=n && y[j]==2;j++)count_2++;
		count+=count_2*count_3;
		debug(count,count_2,count_3);
		i=i-count_3;

		

		for(;j<=n && y[j]==3;j++);
		lld k;
		for(k=j;k<=n && y[k]==4;k++);
		count+=(n-k+1)*count_2_x;
		debug("were ",i,j,count,(n-k+1)*count_2_x,k);
		for(;i<=n;i++)
		{
			for(;j<=n;j++)
			{
				if(x[i]<y[j])
					break;
			}
			count+=(n-j+1);
			debug("woopie",count,n-j+1);
		}
		debug(count);
		


		printf("%f\n",count/(n*1.0));
		
	}
}

