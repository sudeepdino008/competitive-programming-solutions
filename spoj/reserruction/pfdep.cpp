
//#include GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
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


#ifdef GRAPH
#include "drawGraph.cpp"
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
	int sign=1;
 	T ch=getchar_unlocked();
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	n*=sign;
}

lld nextZero(lld *indegree, lld N){
	lld i;
	for(i=1;i<=N;i++){
		if(indegree[i]==0){
			indegree[i]=-1;
			return i;
		}
	}
	return 0;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld N, M,v,c,k,i;
	 inputInt(N);
	 vector<lld> *adj = new vector<lld>[N+1];
	 lld indegree[N+1];
	 for(i=1;i<=N;i++)indegree[i]=0;
	 inputInt(M);
	 while(M--){
		 inputInt(v);
		 inputInt(k);
		 indegree[v] += k;
		 while(k--){
			 inputInt(c);
			 adj[c].pb(v);
		 }
	 }

	 // for(i=1;i<=N;i++){
	 // 	 debug("node ",i, indegree[i]);
	 // 	 tr(adj[i],it)cout<<(*it)<<" ";
	 // 	 cout<<endl;
	 // }
	 
	 lld j;
	 for(i=1;i<=N;i++){
		 k = nextZero(indegree, N);
		 printf("%lld ",k);
		 // cout<<"sdsdsd";
		 // for(j=1;j<=N;j++)cout<<indegree[j]<<" ";
		 // cout<<"sss"<<endl;
		 tr(adj[k],it)indegree[*it]--;
		 
	 }
}

