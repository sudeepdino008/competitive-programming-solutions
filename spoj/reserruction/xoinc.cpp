
//#include GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
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

template<class T>
inline void inputInt(T &n )
{
	n=0;
	int sign=1;
 	T ch=getchar_unlocked();
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	n*=sign;
}

lld c[2001],s[2001], m[2001][2001],n;
void init(){
	lld i,j;
	for(i=1;i<=n;i++)inputInt(c[i]);
	s[n]=c[n];
	for(i=n-1;i>=1;i--)s[i]=s[i+1]+c[i];
	
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)m[i][j]=-1;
//	for(i=1;i<=n;i++)debug(i,s[i]);
}

// lld recursion(lld i, lld p){
// 	if(i>2000)return 0;
// 	if(m[i][p]!=-1)return m[i][p];
// 	if(p==1)return m[i][p]=s[i]-recursion(i+1,2);
// 	if(n-i+1<=p)return m[i][p]=recursion(i,i);
// 	return m[i][p]=max(recursion(i,p-1), s[i]-recursion(i+p,2*p));
// }


lld recursion(lld i, lld p){
	lld k;
	if(i>2000)k=0;
	else if(m[i][p]!=-1)k= m[i][p];
	else if(p==1)k= m[i][p]=s[i]-recursion(i+1,2);
	else if(n-i+1<=p)k= m[i][p]=s[i];
	else  k=m[i][p]=max(recursion(i,p-1), s[i]-recursion(i+p,2*p));
	debug(i,p,k);
	return k;
}


int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 inputInt(n);
	 init();
	 printf("%lld\n",recursion(1,2));
}

