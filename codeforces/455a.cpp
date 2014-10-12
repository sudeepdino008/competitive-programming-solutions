
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

lld m[100001], a[100001][2];

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,i,maa;
	 cin>>n;
	 for(i=1;i<=n;i++)
		 m[i]=0;
	 for(i=1;i<=n;i++){
		 cin>>maa;
		 m[maa] += maa;
	 }
	 a[1][0] = m[1];
	 a[1][1] = 0;
	 
	 for(i=2;i<=n;i++){
	 	 a[i][0] = a[i-1][1]+m[i];
	 	 a[i][1] = max(a[i-1][0], a[i-1][1]);
	 }
	 cout<<max(a[n][0], a[n][1])<<endl;
}

