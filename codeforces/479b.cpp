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

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }

}dbg;

typedef struct b{
    lld height;
    lld index;
}block;

string intToString(lld a){
    ostringstream os;
    os << a;
    return os.str();
}

bool compare(b lhs, b rhs){
    return lhs.height < rhs.height;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
     lld n, k,i,j,minCost;
     block arr[101];
     bool flag[101]={false};
     cin>>n>>k;
     for(i=1;i<=n;i++)cin>>arr[i].height, arr[i].index=i;
     sort(arr+1,arr+n+1, compare);
     minCost = arr[n].height-arr[1].height;
     //for(i=1;i<=n;i++)debug("qqq",arr[i].index, arr[i].height);
     string operations="";
     //if(arr[n].height!=arr[1].height)i=0;
     for(i=1;i<=k && arr[n].height-arr[1].height>1;i++){
         flag[arr[n].index] = true;
         if(flag[arr[1].index])break;
         arr[1].height++;
         arr[n].height--;
         operations+=intToString(arr[n].index)+" "+intToString(arr[1].index)+"\n";
         for(j=2;j<=n;j++){
             if(arr[j].height>=arr[1].height)break;
         }
         swap(arr[1], arr[j-1]);
         for(j=n-1;j>=1;j--){
             if(arr[j].height<=arr[n].height)break;
         }
         swap(arr[n], arr[j+1]);
         minCost = min(minCost, arr[n].height-arr[1].height);
     }
     printf("%lld %lld\n",arr[n].height-arr[1].height, i-1);
     cout<<operations;
}
