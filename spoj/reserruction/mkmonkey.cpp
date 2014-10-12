
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
#define EPSILON 0.00001
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

inline bool ifEqual(double a, double b){
	if(abs(a-b)<=EPSILON)return true;
	else return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 double p, in,cost,e_interest;
	 lld c,i,j=1;
	 while(1){
		 scanf("%lf %lf %lld",&p,&in,&c);
		 if(ifEqual(p,0.00) && ifEqual(in,0.00) && c==0)break;
		 if(c==0)cost = p;
		 else {
			 e_interest = in/c;
			 cost = p;
			 for(i=1;i<=c;i++){
				 cost = cost+cost*e_interest/100.0;
				 cost = ((lld)(cost*100))/100.0;
				 //		 debug(i,cost);
			 }
		 }
		 printf("Case %lld. $%.2lf at %.2lf%% APR compounded %lld times yields $%.2lf\n",j++,p,in,c,cost);
	 }
}

