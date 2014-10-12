
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
#define equals(a,b) (a.compare(b)==0)    //for strings only
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

inline void inputString(string &s)
{
    char ch=getchar_unlocked();
    s="";
    while(ch!='\n')
        s+=ch, ch=getchar_unlocked();
    //s+='\0';
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 cin.tie(NULL);
	 lld n;
	 inputInt(n);
	 string s;
	 lld n1=0, n2=0, n3=0, count=1;
	 while(n--)
	 {
		 cin>>s;
		 debug(s);
		 if(s=="1/2")
			 n2++;
		 else if(s=="1/4")
			 n1++;
		 else n3++;
	 }
	 debug("1/4=",n1," 1/2=",n2," 3/4=",n3);
	 count+=n3;
	 if(n1>n3)
	 {
		 n1=n1-n3;
		 n2+=n1/2;
		 count+=(n2+1)/2;
		 if(n2%2==0 && n1&1)
			 count++;
	 }
	 else count+=(n2+1)/2;
	 printf("%lld\n",count);
}

