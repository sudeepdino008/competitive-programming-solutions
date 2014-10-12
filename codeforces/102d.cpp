
#define DEBUG       //comment when you have to disable all debug macros.
//#define NDEBUG    //comment when all assert statements have to be disabled.
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

/*
typedef struct{
    long long int start;
	long long int end;
}inter;


bool func(inter const &s1, inter const &s2)
{
	if(s1.end<s2.end)
		return true;
	if(s1.end>s2.end)
		return false;
	if(s1.start<s2.start)
		return true;
	return false;
}

*/

int main()
{
	long long int n,m,i,j,s,e;
	cin>>n>>m;
	vector<pair<long long int, long long int> > interval;
	vector<long long int> end;
	long long int sum[m+1];
	
 	for(i=1;i<=m;i++)
	{
		cin>>s>>e;
		interval.push_back(make_pair(e,s));
		end.push_back(e);
		sum[i]=0;
	}
	
	map<long long int,long long int> dp,sum;
	dp[0]=1;
	sum[0]=1;
	sort(interval.begin(), interval.end());
	sort(end.begin(), end.end());

	for(i=1;i<=m;i++)
	{
				
		//for(j=interval[i].start; j<interval[i].end;j++) 
		/*for(j=j_start; j<j_end;j++)
			dp[interval[i].end]=(dp[interval[i].end]+dp[interval[j].end])%MOD;
			debug(interval[i].start,interval[i].end,dp[interval[i].end]);*/
		dp[interval.end]=sum[interval.end]-sum[interval.start];
		sum[i]=sum[i-1]+dp[interval.end];
	}
	cout<<dp[n]<<endl;
}
