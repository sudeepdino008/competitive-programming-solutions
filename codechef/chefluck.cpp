
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
#include <unordered_map>
#include <unordered_set>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define pb push_back
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
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

int main()
{
	lld t,n,k;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		k=(((n%7)<<1)%7)<<2;
		printf("%lld\n",(n-k<0)?(-1):(n-k));
	}
}
