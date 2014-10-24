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
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <sys/time.h>
#include <iomanip>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld unsigned long long int
#define MOD 1000000007
using namespace std;

inline void inputInt(lld &n )
{
	n=0;
 	lld ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

inline lld count_digs(lld &n)
{
	lld count=0, k=n;
	while(k!=0)
		k/=10, count++;
	return count;
}

lld maximum_luck(lld start, lld end, lld dig)
{
	if(start>end)
		return 0;
	lld count4=0, count7=0, gen=0, j=0;
	for(i=1;i<=dig;i++)
		gen=gen*10+4;
	
}


int main()
{
	lld t, a, b,c1,c2,end,start,max_l,k;
	inputInt(t);
	while(t--)
	{
		inputInt(a);
		inputInt(b);
		c1=count_digs(a);
		c2=count_digs(b);
		end=0;
		for(i=1;i<=c1;i++)
			end=end*10+9;
		start=a;
		max_l=0;
		for(i=1;i<(c2-c1);i++)
		{
			k=maximum_luck(start,end,c1);
			max_l=(max_l<k)?(k:max_l);
			start=end+1;
			end=end*10+9;
			c1++;
		}
		k=maximum_luck(start,b,c1);
		max_l=(max_l<k)?(k:max_l);
		printf("%ulld\n", max_l);
	}
}
