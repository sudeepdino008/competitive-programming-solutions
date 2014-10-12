
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



int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld q, i, count=0,u=1;
	 cin>>q;
	 lld c=q;
	 for(i=2;i*i<=c;i++){
		 
		 if(q%i==0){
			 debug("qqq",i);
			 while(q%i==0 && count!=2)count++, q=q/i,u*=i;
		 }
		 if(q==1 && count==2)return cout<<"2\n", 0;
		 if(count==2){
			 debug("qqqq",i);
			 cout<<"1\n"<<u<<endl;
			 return 0;
		 }
	 }
	 if(count==1 || (q==1 && c!=1))cout<<"2\n"; else cout<<"1\n0\n";
	 
}

