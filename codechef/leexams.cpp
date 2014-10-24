
#define DEBUG       //comment when you have to disable all debug macros.
#define NDEBUG    //comment when all assert statements have to be disabled.
#include <iostream>
#include <cstring>
#include <sstream>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;


#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
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
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

typedef struct{
	long double p;
    lld s1,s2;
}re;

re arr[50];
lld n;
unordered_set<lld> us;

double func(lld i)
{
	long double val=0;
	if(i==n)
		return 1;
	if(!present(us,arr[i].s1))
	{
		us.insert(arr[i].s1);
		val=func(i+1)*arr[i].p;
		us.erase(arr[i].s1);
	}
	if(!present(us,arr[i].s2))
	{
		us.insert(arr[i].s2);
		val+=(1.0-arr[i].p)*func(i+1);
		us.erase(arr[i].s2);
	}
	return val;
}

int main()
{
	lld T,i,k;
	inputInt(T);
	while(T--)
	{
		inputInt(n);
		for(i=0;i<n;i++)
			inputInt(k), inputInt(arr[i].s1), inputInt(arr[i].s2), arr[i].p=k/100.0;
		printf("%f\n",func(0));
	}
}


