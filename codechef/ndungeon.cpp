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
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
#define correct(i,j) (((i)<=m && (j)<=n && (i)>=1 && (j)>=1)?1:0)
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
	lld m,n,i,j;
	inputInt(m);
	inputInt(n);
	lld times[m+1][n+1], distance[m+1][n+1], a,b,T;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			inputInt(times[i][j]), distance[i][j]=UINT_MAX;
	}
	distance[1][1]=times[1][1];
	inputInt(a);
	inputInt(b);
	inputInt(T);
	queue< pair<lld, lld> > element;
	element.push(make_pair(1,1));
	while(!element.empty())
	{
	    pair<lld, lld> p=element.front();
		element.pop();
		lld i=p.first, j=p.second;
		if(correct(i,j+1) && times[i][j+1]+distance[i][j]<distance[i][j+1] && times[i][j+1]+distance[i][j]<T)
		{
			element.push(make_pair(i,j+1));
			distance[i][j+1]=distance[i][j]+times[i][j+1];
		}
		if(correct(i,j-1) && times[i][j-1]+distance[i][j]<distance[i][j-1] && times[i][j-1]+distance[i][j]<T)
		{
			element.push(make_pair(i,j-1));
			distance[i][j-1]=distance[i][j]+times[i][j-1];
		}
		if(correct(i+1,j) && times[i+1][j]+distance[i][j]<distance[i+1][j]  && times[i+1][j]+distance[i][j]<T)
		{
			element.push(make_pair(i+1,j));
			distance[i+1][j]=distance[i][j]+times[i+1][j];
		}
		if(correct(i-1,j) && times[i-1][j]+distance[i][j]<distance[i-1][j]  && times[i-1][j]+distance[i][j]<T)
		{
			element.push(make_pair(i-1,j));
			distance[i-1][j]=distance[i][j]+times[i-1][j];
		}
	}

	lld s=T-distance[a][b];
	if(s<0)
		printf("NO\n");
	else
		printf("YES\n%lld\n",s);
}
