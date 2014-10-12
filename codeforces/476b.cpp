
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

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 string s1,s2;
	 cin>>s1>>s2;
	 lld nump, numn, len = s1.length(),i;
	 nump=numn=0;
	 for(i=0;i<len;i++){
		 if(s1[i]=='+')nump++;
		 else if(s1[i]=='-')numn++;
		 if(s2[i]=='+')nump--;
		 else if(s2[i]=='-')numn--;
	 }
	 lld f[len+1];
	 f[0]=1;
	 for(i=1;i<=len;i++)f[i]=f[i-1]*i;
	 double val = f[nump+numn]/(f[nump]*f[numn]);
	 val = val/(1.0*(1<<(nump+numn)));
	 cout<<fixed<<setprecision(11)<<val<<"\n";
}

