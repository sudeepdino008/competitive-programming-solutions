#include <iostream>
#include <sstream>
#include <cstring>
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
#include <iomanip>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
#define pb push_back
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
	lld t,k,i,n,total_sum,j;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		lld a[n+1];
		long double p[n+1];
		total_sum=0;
		for(i=0;i<n;i++)
		{
			inputInt(a[i]);
			total_sum+=a[i];
		}
		for(i=0;i<n;i++)
		{
			inputInt(k);
			p[i]=k/100.0;
		}
		long double next[total_sum+1],prev[total_sum+1];         //next[k,i]=(1-p)prev[k,i-1]+p*prev[k-ai,i-1]
		prev[0]=1.0;
		for(i=1;i<=total_sum;i++)
			prev[i]=0.0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=total_sum;j++)
				next[j]=(1.0-p[i])*prev[j]+p[i]*(((j-a[i])<0)?0:prev[j-a[i]]);
			for(j=0;j<=total_sum;j++)
				prev[j]=next[j];
			
		}
		double sum=0;
		for(j=(total_sum+1)/2;j<=total_sum;j++)
			sum+=next[j];
		printf("%lf\n",sum);
	}
}
