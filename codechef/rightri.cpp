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
#include <sys/time.h>
#include <iomanip>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;

inline void inputInt(int &n )
{
	n=0;
 	int ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int distance(int x1, int y1, int x2, int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int n,x1,x2,x3,y1,y2,y3,d1,d2,d3,count=0;
	inputInt(n);
	while(n--)
	{
		inputInt(x1);
		inputInt(y1);
		inputInt(x2);
		inputInt(y2);
		inputInt(x3);
		inputInt(y3);
		d1=distance(x1,y1,x2,y2);
		d2=distance(x1,y1,x3,y3);
		d3=distance(x2,y2,x3,y3);
		//want d1>=d2>=d3
		if(d1<d2)
			swap(d1,d2);
		if(d1<d3)
			swap(d1,d3);
		if(d2<d3)
			swap(d2,d3);

		if(d1==(d2+d3))
			count++;

	}
	printf("%d\n",count);
}
