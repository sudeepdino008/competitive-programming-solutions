//#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
//#define GRAPH
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

lld dp1[200001], dp2[200001];

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
     lld r,g,h,i,j;
     scanf("%lld %lld",&r,&g);
     if(r>g)swap(r,g);
     h=(sqrt(1+8*r+8*g)-1.0)/2;
     if(r==0 || g==0){
         printf("1\n");
         return 0;
     }

     //for(i=1;i<=r;i++)dp1[i] = 2;
     dp1[0]=1;
     dp1[1]=1;
     lld sum=2,k;
     for(i=2;i<=h;i++){
         sum=0;
         k=(i*(i+1))/2;
         for(j=max(k-g,(lld)0);j<=r;j++)
             dp2[j] = (dp1[j]+((j>=i)?dp1[j-i]:0))%MOD;
         for(j=max(k-g,(lld)0);j<=r;j++)dp1[j]=dp2[j];
     }
     for(i=max(k-g,(lld)0);i<=r;i++)sum=(sum+dp2[i])%MOD;
     //cout<<endl;
     cout<<sum<<"\n";
     //debug("count:",coun, h);
}
