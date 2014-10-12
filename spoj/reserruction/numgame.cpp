//#include GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL     //uncomment for testing from local file
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

lld a1,a2,b1,b2;
double goldenRatio = (1.0+sqrt(5.0))/2.0;

inline lld count_intersections_g(lld p,lld x, lld y){   //returns |{p,p+1,p+2,....}U{x,x+1,x+2,....y}|
	if(y<p)return 0;
	return y-max(x,p)+1;
}


inline lld solve(){
	lld i,count=0,pb=min(b2,(lld)((1.0*a2)/goldenRatio)), pa=min(a2,(lld)((1.0*b2)/goldenRatio));
	double val;
	for(i=b1;i<=pb;i++){
		val = i*goldenRatio;
		count+=count_intersections_g((lld)val+1,a1,a2);
	}
	for(i=a1;i<=pa;i++){
		val = i*goldenRatio;
		count+=count_intersections_g((lld)val+1,b1,b2);
	}
	return count;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t,p=1;
	 scanf("%lld",&t);
	 while(t--){
		 scanf("%lld %lld %lld %lld\n",&a1,&a2,&b1,&b2);
		 printf("Case #%lld: %lld\n",p++,solve());
	 }
}


