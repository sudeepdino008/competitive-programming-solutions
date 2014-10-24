
#define DEBUG       //comment when you have to disable all debug macros.
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

inline lld area2(lld x1,lld x2,lld x3,lld y1,lld y2,lld y3)
{
	return abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	lld n,x1,x2,x3,y1,y2,y3,min_i,max_i,i=0;
	lld min_a, max_a;
	inputInt(n);
	min_a=LLONG_MAX;
	max_a=LLONG_MIN;

	while(n--)
	{
		i++;
		inputInt(x1);
		inputInt(y1);
		inputInt(x2);
		inputInt(y2);
		inputInt(x3);
		inputInt(y3);
		lld a=area2(x1,x2,x3,y1,y2,y3);
		debug(a);
		if(min_a>=a)
		{
			min_a=a;
			min_i=i;
		}
		if(max_a<=a)
		{
			max_a=a;
			max_i=i;
		}
	}
	printf("%lld %lld\n",min_i,max_i);
}


