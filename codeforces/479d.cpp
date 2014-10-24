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
#define sc(n) scanf("%lld ",&n);
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

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
     lld n,x,l,y,arr[100001],i;
     bool foundx=false, foundy=false;
     sc(n);sc(l);sc(x);sc(y);
     set<lld> forx, fory,tem1, tem2,tem3;
     for(i=1;i<=n;i++){sc(arr[i]); forx.insert(arr[i]); fory.insert(arr[i]);}
     //calculate for x

     for(i=1;i<=n;i++){
         if(present(forx, arr[i]-x)){
             debug("sss",arr[i]-x,arr[i],x);
             foundx=true;
             break;
         }
         else if(arr[i]-x>=0)tem1.insert(arr[i]-x);
         if(present(forx, arr[i]+x)){
             debug("sssq",arr[i]+x,arr[i],x);
             foundx=true;
             break;
         }else if(arr[i]+x<=l)tem1.insert(arr[i]+x);
     }
     if(foundx){
         for(i=1;i<=n;i++){
             if(present(fory, arr[i]-y)){
                 foundy=true;
                 break;
             }
             else if(arr[i]-y>=0)tem2.insert(arr[i]-y);
             if(present(fory, arr[i]+y)){
                 foundy=true;
                 break;
             }else if(arr[i]+y<=l)tem2.insert(arr[i]+y);
         }
         if(foundy){
             printf("0\n");
             return 0;
         }
         else{
             printf("1\n%lld\n",*tem2.begin());
         }
     }
     else{
         
         for(i=1;i<=n;i++){
             if(present(fory, arr[i]-y)){
                 foundy=true;
                 break;
             }
             else if(arr[i]-y>=0){
                 tem2.insert(arr[i]-y);
                 if(present(tem1, arr[i]-y))tem3.insert(arr[i]-y);
             }
             if(present(fory, arr[i]+y)){
                 foundy=true;
                 break;
             }else if(arr[i]+y<=l)
             {
                 tem2.insert(arr[i]+y);
                 if(present(tem1,arr[i]+y))tem3.insert(arr[i]+y);
             }
         }
         if(foundy){
             printf("1\n%lld\n",*tem1.begin());
             return 0;
         }
         else if(!tem3.empty()){
             printf("1\n%lld\n",*tem3.begin());
             return 0;
         }
         else {
             printf("2\n%lld %lld\n",*tem1.begin(), *tem2.begin());
             
         }
     }
}
