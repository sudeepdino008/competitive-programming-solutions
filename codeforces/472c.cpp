
//#define GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
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
	 lld n,i;
	 cin>>n;
	 string *str1 = new string[n+1];
	 string *str2 = new string[n+1];
	 
	 
	 lld arr[n+1],pres,prev;
	 string previous,present,best;
	 for(i=1;i<=n;i++)cin>>str1[i]>>str2[i];
	 for(i=1;i<=n;i++)cin>>arr[i];
	 previous = (str1[arr[1]].compare(str2[arr[1]])<0)?str1[arr[1]]:str2[arr[1]];
	 debug("prev",previous);
	 for(i=2;i<=n;i++){
		 pres = arr[i];
		 prev = arr[i-1];
		 best = (str1[pres].compare(str2[pres])<0)?str1[pres]:str2[pres];
		 debug("best",best,previous,pres,prev);
		 if(best.compare(previous)>0){
			 previous = best;
		 }
		 else {
			 best = (str1[pres].compare(str2[pres])<0)?str2[pres]:str1[pres];
			 if(best.compare(previous)>0)previous = best;
			 else break;
		 }
	 }
	 if(i!=n+1)cout<<"NO\n";
	 else cout<<"YES\n";
	 
}

