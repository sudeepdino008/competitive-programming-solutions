#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <sys/time.h>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define sd(n) scanf("%d",&n);
#define sf(n) scanf("%lf",&n);
#define lld long long int
#define MOD 1000000007
using namespace std;

int main()
{
	int t,n,i,j,m,c;
	double d,u,min_cost,r,present_cost;
	sd(t);
	while(t--)
	{
		sf(d);
		sf(u);
		sd(n);
		min_cost=d*u;
		j=0;
		for(i=1;i<=n;i++)
		{
			sd(m);sf(r);sd(c);
			present_cost=c/(1.0*m)+r*u;
			if(present_cost<min_cost)
			{
				min_cost=present_cost;
				j=i;
			}
		}
		printf("%d\n",j);
	}
}
