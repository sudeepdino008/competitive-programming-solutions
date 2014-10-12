
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

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,i,j,pres,up,left,down,right;
	 inputInt(n);
	 char arr[n][n];
	 for(i=0;i<n;i++){
		 for(j=0;j<n;j++)arr[i][j]=getchar_unlocked();
		 getchar_unlocked();
		 
	 }
	 for(i=1;i<n-1;i++){
		 for(j=1;j<n-1;j++)
		 {
			 pres = arr[i][j];
			 up = arr[i-1][j];
			 down = arr[i+1][j];
			 right = arr[i][j+1];
			 left = arr[i][j-1];
			 if(up!='X' && down!='X' && right!='X' && left!='X' && pres>up && pres>down && pres>left && pres>right)
				 arr[i][j] = 'X';
		 }
	 }
	 for(i=0;i<n;i++){
		 for(j=0;j<n;j++)
			 printf("%c",arr[i][j]);
		 printf("\n");
	 }
}

