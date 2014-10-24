
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

lld n, k;
lld diff[100005];

lld compare(lld arr1[], lld arr2[])   //true if arr1<arr2
{
	lld i, sum=0;
	for(i=1;i<=k;i++)
	{
		// if(arr1[i]>arr2[i])
		// 	return -1;
		sum+=arr2[i]-arr1[i];
	}
	return sum;
}



int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t, i, j, *ans[100000], min_s, s, k;
	 inputInt(t);
	 while(t--)
	 {
		 inputInt(n);
		 inputInt(k);
		 lld arr[n+1][k+1], aim[k+1];
		 for(i=1;i<=n;i++)
		 {
			 for(j=1;j<=k;j++)
				 inputInt(arr[i][j]);
		 }
		 for(i=1;i<=k;i++)
			 inputInt(aim[i]);
		 min_s = LLONG_MIN;
		 //ans = NULL;
		 for(i=1;i<=n;i++)
			 diff[i] = compare(arr[i], aim);
		 for(i=1;i<=n;i++)
		 {
			 for(j=1;j<=k;j++)
				 cout<<arr[i][j]<<" ";
			 cout<<endl;
		 }
		 cout<<endl<<endl;
		 sort(arr[1], arr[n]);
		 for(i=1;i<=n;i++)
		 {
			 for(j=1;j<=k;j++)
				 cout<<arr[i][j]<<" ";
			 cout<<endl;
		 }
		 cout<<endl<<endl;
	 }
}

