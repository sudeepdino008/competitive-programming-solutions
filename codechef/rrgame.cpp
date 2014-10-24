
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
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
	lld n,m,k,i;
	inputInt(n);
	inputInt(m);
	inputInt(k);
	lld A[n+1], B[n+1], sum=0;
	A[0]=-1;
	for(i=1;i<=n;i++)
		inputInt(A[i]);
	sort(A,A+n+1);
	for(i=1;i<=n;i++)
		B[i]=(m-A[i])/k+1, sum+=B[i];
	//debug(sum);
	lld count=!(n%2);
	for(i=1;i<=n;i++)
	{
		count=(count+min(sum-B[i], B[i])/2)%MOD;
		debug(count);
		while(i<=n-1 && A[i]==A[i+1])
			i++;
	}	
	printf("\n\n%lld\n",count);
	
}
