
//#define DEBUG       //comment when you have to disable all debug macros.
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

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }

}dbg;

template<class T>
inline bool inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return true;
}

//lld array[100000];

int main()
{
	lld c,n,i,j;
	while(inputInt(c) && inputInt(n) && !(n==0 && c==0))
	{
		lld array[n];
		vector<lld> *adj=new vector<lld>[c];
		lld sum=0;
		for(i=0;i<n;i++)
		{
			inputInt(array[i]);
			sum+=array[i];
			adj[sum%c].pb(i);

		}
		/*	if(!adj[0].empty())
		{
			printf("%lld\n",array[adj[0][0]]);
			continue;
			}*/
		debug(yeah,n,c);
		for(i=0;i<c;i++)
		{
			debug(i,adj[i].size(),array[i]);
			if(adj[i].size()>1)
			{
				for(j=adj[i][0]+1;j<=adj[i][1];j++)
					printf("%lld ",j+1);
				printf("\n");
				break;
			}
		}
		if(i==c)
		{
			for(j=0;j<=adj[0][0];j++)
					printf("%lld ",j+1);
				printf("\n");
		}
	 
			
		
	}
}
