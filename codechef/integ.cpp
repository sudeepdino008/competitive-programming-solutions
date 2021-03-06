
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
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

bool myfunc(lld i, lld j)
{
	return i<j;
}

int main()
{
	lld n,i,k,X,sum=0;
	inputInt(n);
	vector<lld> arr;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k<0)
			arr.pb(k), sum+=k;
	}
	scanf("%lld",&X);
	sort(arr.begin(), arr.end(), greater<lld>());
	   
	lld size=arr.size();
	if(size<=X)
	{
		printf("%lld\n",abs(sum));
		return 0;
	}


	lld val=abs(arr[size-X-1]);
	sum=0;
	for(i=size-X;i<size;i++)
		sum=sum+arr[i];
	sum=abs(sum);
	printf("%lld\n",(X*val+sum-val*X));
}
