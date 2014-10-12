
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
	lld n,m,a,i,b;
	cin>>n>>m;
	lld array[1001]={0};
	//fill_n(array,0,sizeof(array));
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		array[a]=-1;
		array[b]=-1;
	}
	for(i=1;i<=n;i++)
	{
		//	cout<<"ss "<<array[i]<<endl;
		if(array[i]==0)
		{
			a=i;
			break;
		}
	}
	cout<<(n-1)<<endl;
	for(i=1;i<=n;i++)
	{
		if(i!=a)
			cout<<a<<" "<<i<<endl;
	}
	
}

