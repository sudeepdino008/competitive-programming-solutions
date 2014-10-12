
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

typedef struct {
	int b,c,d,count;          //b:stuffing per for each cake, c:amount of dough, d:cost of cake
}item;

//item::item(int b,int c, int d, int count):b(b), c(c), d(d), count(count){}

int main()
{
	int n,m,c0,d0,i,j,k,p;
	cin>>n>>m>>c0>>d0;
	item i0={0,c0,d0,n/c0};
	item info[m+1];
	for(i=1;i<=m;i++)
	{
		cin>>info[i].count>>info[i].b>>info[i].c>>info[i].d;
		info[i].count/=info[i].b;
	}
	int dp[11][1001]={0};

	for(i=0;i<i0.count;i++)
	{
		for(j=i*i0.c;j<(i+1)*i0.c;j++)
			dp[0][j]=i*i0.d;
	}
	for(i=i0.count*i0.c;i<=n;i++)
		dp[0][i]=i0.count*i0.d;

	
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{			
			for(p=0;p<=info[i].count && j-p*info[i].c>=0;p++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-p*info[i].c]+info[i].d*p);
		}
	}
	int ans=-1;
	for(i=0;i<=n;i++)
		ans=max(ans,dp[m][i]);
	cout<<ans<<endl;
	
	

}
