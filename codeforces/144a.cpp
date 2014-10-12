
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


int main()
{
	int n;
	cin>>n;
	int arr[n+1],max,min,max_p, min_p;
	cin>>arr[1];
	max=min=arr[1];
	max_p=min_p=1;
	for(int i=2;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
		{
			max=arr[i];
			max_p=i;
		}
		if(arr[i]<=min)
		{
			min=arr[i];
			min_p=i;
		}
	}
	int ans=0;
	ans=n-min_p+max_p-1;
	if(min_p<max_p)
		ans--;
	cout<<ans<<endl;
}
