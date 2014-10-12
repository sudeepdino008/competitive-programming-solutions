
//#define GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
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

lld arra[1001],arrb[1001],arrc[1001],arrd[1001];

inline lld max(lld a, lld b)
{
	return (a>b)?a:b;
}

inline lld intersection(lld a, lld b, lld c, lld d, lld l, lld r)
{
	
	c=c+l;
	d=d+l;
	r=r-l;
	l=0;

	if(b<c)return 0;
	lld k=a-d;
	c=c+max(0,k);
	d=d+max(0,k);
	r=r-max(0,k);
//	debug("hey",b-c+1,r-l+1,a-d,c,d,r);
	return min(b-c+1,r-l+1);
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld p,q,r,l,i,j,count=0,k;
	 cin>>p>>q>>l>>r;
	 for(i=1;i<=p;i++)cin>>arra[i]>>arrb[i];
	 for(i=1;i<=q;i++)cin>>arrc[i]>>arrd[i];
	 
	 for(i=1;i<=p;i++)for(j=1;j<=q;j++){
			 k=intersection(arra[i],arrb[i],arrc[j],arrd[j],l,r);
			 debug(k,arra[i],arrb[i],arrc[j],arrd[j],l,r);
			 count += k;
		 }
	 cout<<count<<"\n";
}

