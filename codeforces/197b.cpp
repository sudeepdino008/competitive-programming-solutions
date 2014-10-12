
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


long long int hcf(long long int a, long long int b)
{
	if(b==0)
		return a;
	if(a<b)
		swap(a,b);
	return hcf(b,a%b);
}

int main()
{
	long long int n,m,a0,b0,a,i;
	cin>>n>>m;
	cin>>a0;
	for(i=1;i<=n;i++)
		cin>>a;
	
	cin>>b0;
	for(i=1;i<=m;i++)
		cin>>a;
	if(n==m)
	{
		// if(b0==0)
		// {
		// 	if(a0<0)
		// 		cout<<"-Infinity\n";
		// 	else cout<<"Infinity\n";
		// }
		// else
		// {
			a=hcf(abs(a0),abs(b0));
			if((a0<0 && b0>0) || (a0>0 && b0<0))
				cout<<"-";
			cout<<abs(a0)/a<<"/"<<abs(b0)/a<<endl;
//		}
	}
	else if(n>m)
	{
		if((a0>0 && b0<0) || (a0<0 && b0>0))
			cout<<"-";
		cout<<"Infinity\n";
	}
	else
		cout<<"0/1\n";
   
}
