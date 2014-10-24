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
#define size 2000
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

double coeff[2001][2001];

void precompute()
{
		lld i, j;
		/*for(i=0;i<=2000;i++)
	{
		for(j=0;j<=2000;j++)
			coeff[i][j]=0;
	}*/
	coeff[1][1]=1;

	for(i=2;i<=size;i++)
	{
		for(j=1;j<=(i+1)/2;j++)
			coeff[i][j]=1-(coeff[i-1][j]+coeff[i-1][j-1])/2;
		for(j=1;j<=(i+1)/2;j++)
			coeff[i][i-j+1]=coeff[i][j];
	}

}

int main()
{
	int t,n,i,j,p,m,a;
	double s;
	inputInt(t);
	precompute();
	while(t--)
	{
		s=0;
		inputInt(n);
		m=n;
		while(n--)
		{
			inputInt(a);
			s+=a*coeff[m][n+1];
		}
		printf("%f\n",s);
	}
}
