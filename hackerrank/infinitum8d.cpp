

#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
//#include GRAPH
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
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

 	T ch=getchar_unlocked();
	/*int sign=1;
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
		 n*=sign;*/
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}
lld arr[18],n;

lld calcLCM(lld a, lld b){
	return (a*b)/gcd(a,b);
}

lld solve(lld levels, lld index, lld lcm, lld w){
	if(index>n)return 0;
	lld val=0,i,c;
	for(i=index;i<=n;i++){
		c = calcLCM(lcm,arr[i]);
		if(c>w)return val;
		val+=w/c;
		val-=solve(levels+1,i+1,c,w);
	}
	return val;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld d,L,R,i,j;
	 inputInt(n);

	 for(i=1;i<=n;i++)inputInt(arr[i]);
	 inputInt(d);
	 sort(arr+1,arr+n+1);
	 lld m=n;
	 for(i=1;i<=n;i++){
		 for(j=i+1;arr[i]<=51 && j<=n;j++){
			 //debug("yeah",arr[j],arr[i],j,i,m);
			 if(arr[j]<=51 && arr[j]%arr[i]==0)arr[j]=100, m--;
		 }
	 }
	 sort(arr+1,arr+n+1);
	 n=m;
	 

	 //for(i=1;i<=n;i++)cout<<" "<<arr[i];
	 while(d--){
		 inputInt(L);
		 inputInt(R);
		 printf("%lld\n",solve(0,1,1,R)-solve(0,1,1,L-1));
	 }
	 
}

