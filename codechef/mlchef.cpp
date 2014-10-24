
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
//#define _MSC_VER
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


template<class T>
inline void inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
	/*#ifdef _MSC_VER
	freopen("input.in","r",stdin);
	#endif*/
	vector<vector<int> > real,v;
	int n,q,a,x,i,i_boss,c,j;
	inputInt(n);

	int health[n+1], parent[n+1];
	for(i=0;i<=n;i++)
		real.pb(vector<int>()), v.pb(vector<int>());
	for(i=1;i<=n;i++)
	{
		inputInt(health[i]);
		inputInt(i_boss);
		parent[i]=i_boss;
		v[i_boss].pb(i);
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<i<<"--> ";
		//for(auto it=v[i].begin(); it!=v[i].end();it++)
		tr(v[i],it)
			cout<<*it<<" ";
		cout<<endl;
	}
	cout<<endl<<endl;
	parent[0]=0;
	for(i=1;i<=n;i++)
		real[0].pb(i);
	for(i=1;i<=n;i++)
	{
		lld size=v[i].size();
		for(j=0;j<size;j++)
		{
			tr(v[j],it)
				real[i].pb(*it), cout<<i<<" "<<j<<" "<<*it<<endl ;
		}
	}

	for(i=0;i<=n;i++)
	{
		cout<<i<<"--> ";
		//for(auto it=v[i].begin(); it!=v[i].end();it++)
		tr(real[i],it)
			cout<<*it<<" ";
		cout<<endl;
	}

/*

	priority_queue<int,vector<int>,greater<int>> weight[n+1];
	int to_del[n+1],count[n+1];
	

	for(i=0;i<=n;i++)
	{
		cout<<i<<"--> ";
		//for(auto it=v[i].begin(); it!=v[i].end();it++)
		tr(real[i],it)
			cout<<*it<<" ";
		cout<<endl;
	}

	for(i=0;i<=n;i++)
	{
		to_del[i]=count[i]=0;
		tr(real[i],it)
			weight[i].push(health[*it]), count[i]++;
	}
	int k;
	inputInt(q);
	int t_count=n;
	while(q--)
	{
		inputInt(c);
	
	}
	
*/

}



