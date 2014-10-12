
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
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define INDEX(arr,elem)        (lower_bound(all(arr),elem)-arr.begin())
#define lld long long int
#define MOD 1000000007
#define gcd __gcd
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
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



lld men_preference[501][501], women_preference[501][501], inv_women_preference[501][501];  
/*inv_women_prefernce keeps record of the the position of jth man in the women preference list. Will be used the decide the relative ordering of 2 men in a women's preference list*/

void stable_marriage(lld n)
{
	lld men[n+1], women[n+1], men_proposed_index[n+1], i,w,m;
	stack<lld> men_todo;
	for(i=1;i<=n;i++)
		men_todo.push(i), men[i]=women[i]=-1, men_proposed_index[i]=1;

	while(!men_todo.empty())
	{
		m=men_todo.top();
		w=men_preference[m][men_proposed_index[m]];   //highest ranked women to whom m has not proposed
		men_proposed_index[m]++;
		if(women[w]==-1)
		{
			men_todo.pop();
			men[m]=w;
			women[w]=m;
		}
		else if(inv_women_preference[w][women[w]]>inv_women_preference[w][m])
		{
			men_todo.pop();
			men_todo.push(women[w]);
			men[m]=w;
			women[w]=m;
		}	
	}
	for(i=1;i<=n;i++)
		cout<<i<<" "<<men[i]<<endl;
}

int main()
{
	lld n,i,j,t;
	inputInt(t);
	while(t--)
	{
		inputInt(n);	
		//enter women preference
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				inputInt(women_preference[i][j]),inv_women_preference[i][women_preference[i][j]]=j;
		}
		//enter men preference
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				inputInt(men_preference[i][j]);
		}
		
		stable_marriage(n);
	}	
	
}
