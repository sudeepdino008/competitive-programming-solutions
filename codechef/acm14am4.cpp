
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
	int sign=1;
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
	// while( ch < '0' || ch > '9')
   //    ch=getchar_unlocked();
	// while(  ch >= '0' && ch <= '9' )
	// 	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

lld f1[101][101][101], f2[101][101][101];

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t,n,m,w[101][101],i,j,maxSum,sum,k;
	 inputInt(t);
	 while(t--){
		 inputInt(n);
		 inputInt(m);
		 maxSum = -1000000000000;
		 sum = 0;
		 for(i=1;i<=n;i++)for(j=1;j<=m;j++)inputInt(w[i][j]);
		 
		 for(i=1;i<=n;i++){
			 for(j=1;j<=m;j++){
				 f1[i][j][0] = f2[i][j][0] = w[i][j];
				 for(k=1;k<=max(n,m);k++){
					 if(i+k<=n && j+k<=m)
					 {
						 f1[i][j][k] = f1[i][j][k-1] + w[i+k][j+k];
//						 debug("1",i,j,k,f1[i][j][k]);
					 }
					 if(i+k<=n && j-k>=1)
					 {
						 f2[i][j][k] = f2[i][j][k-1] + w[i+k][j-k];
						 //					 					 debug("2",i,j,k,f2[i][j][k]);
					 }
					 //			 debug(i,j,k,f1[i][j][k],f2[i][j][k]);
				 }
			 }
		 }
		 
		 
		 // debug("ssss");
		 for(i=1;i<=n;i++)
		 {
			 for(j=1;j<=m;j++){
				 for(k=1;k<=max(m,n) && j+k<=m && i+k<=n;k++){
					 sum = f1[i][j][k]+f2[i][j+k][k]-((k&1)?0:w[i+k/2][j+k/2]);
//					 debug(sum,i,j,k,f1[i][j][k],f2[i][j+k][k]);
					 maxSum = (maxSum<sum)?sum:maxSum;
				 }
			 }
		 }
		 printf("%lld\n",maxSum);
		 
	 }
}

