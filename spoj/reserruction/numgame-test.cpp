
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


bool recursion(lld i, lld j){
	if(i<j)return recursion(j,i);
	if(i==j)return 0;
	lld k = i/j;
	if(k>=2)return true;
	return !recursion(j,i%j);
}

inline void validate(){
	if(a1<b1)return;
	swap(a1,b1);
	swap(a2,b2);
}

lld binary_search(lld goal, lld start, lld end){
	if(goal==1)return 2;
	if(goal==2)return 4;
	
	lld mid,val;
	while(start<=end){
		mid=(start+end)/2;
		if(recursion(goal,mid)){
			val = mid;
			end = mid-1;
		}
		else start=mid+1;
	}
	return val;
}

inline lld count_intersections(lld p,lld x, lld y){   //returns |{p,p+1,p+2,....}U{x,x+1,x+2,....y}|
	if(x>y || y<p)return 0;
	return y-max(x,p)+1;
}

inline lld solve(){

	lld p = binary_search(a1, a1+1,2*a1-1);  //(a1,a1+p+j)   where j=0,1,2,3,.... is winning position
	lld i,countd=count_intersections(p,b1,b2),mod=p%a1+(a1==1);
	lld flag = false;
	for(i=a1+1;i<=a2;i++){
		if(flag || !recursion(i,i+mod))mod++, flag=false;    //if a(i-1)+mod is nomore acceptable with a(i), then increment mod
		else if(!flag)flag=true;
		countd+=count_intersections(i+mod,b1,b2);
	}
	p = binary_search(b1,b1+1,2*b1-1);
	flag = false;
	countd+=count_intersections(p,a1,a2);
	mod = p%b1+(a1==1);
	for(i=b1+1;i<=b2;i++){
		if(flag || !recursion(i,i+mod))mod++, flag = false;
		else if(!flag)flag=true;
		countd+=count_intersections(i+mod,a1,a2);
	}
	return countd;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t,p=1;
	 inputInt(t);
	 while(t--){
		 inputInt(a1);
		 inputInt(a2);
		 inputInt(b1);
		 inputInt(b2);
		 validate();  // 'a' range should be forward
		 printf("Case #%lld: %lld\n",p++,solve());
	 }
}

