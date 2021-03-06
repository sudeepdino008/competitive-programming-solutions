
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

lld m , n , array[101], brray[101];


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

lld solve()
{
	lld edit[m+1][n+1], i, j;
	for(i=0;i<=n;i++)
		edit[0][i] = i;
	for(i=0;i<=m;i++)
		edit[i][0] = i;
	//edit[0][0] = 0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			edit[i][j] = min(edit[i-1][j]+1, min(edit[i][j-1]+1, edit[i-1][j-1]+(array[i]!=brray[j])));
	}
	//cout<<endl;
	return edit[m][n];
	
}


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t, i;
	 inputInt(t);
	 while(t--)
	 {
		 inputInt(m);
		 for(i=1;i<=m;i++)
			 inputInt(array[i]);
		 inputInt(n);
		 for(i=1;i<=n;i++)
			 inputInt(brray[i]);
		 printf("%lld\n",solve());
	 }
}

