
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
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

 	T ch=getchar_unlocked();
	/*int sign=1;
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
		 n*=sign;*/
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 srand(time(NULL));
	 lld n,m,k,i,a,b;
	 inputInt(n);
	 inputInt(m);
	 inputInt(k);
	 lld arr[n+1][m+1],steps,j,r,count;
	 vector<pair<pair<lld,lld>,lld> > vec;
	 vector<pair<lld,pair<lld,lld> > > ser;
	 memset(arr,0,sizeof arr);
	 for(i=1;i<=k;i++){
		 inputInt(a);
		 inputInt(b);
		 arr[a][b] = 2;
	 }
	 for(i=1;i<=n;i++){
		 for(j=1;j<=m;j++){
			 if(arr[i][j]==0){
				 count=0;
				 for(k=j;k<=m && arr[i][k]==0;k++)count++;
				 //			 debug("hey",i,j,count);
				 ser.pb(mp(count, mp(i,j)));
				 j = k;
			 }
		 }
	 }
	 sort(ser.begin(), ser.end());
	 
	 lld siz=ser.size(),x,y;
	 // debug("www",siz);
	 steps=0;
	 for(i=siz-1;i>=siz/2;i--){
		 x = ser[i].second.first;
		 y = ser[i].second.second;
		 if(arr[x][y]==0){

			 //debug(x,y,ser[i].first);
			 vec.pb(mp(mp(x,y),0));
			 for(j=y;j<=m && arr[x][j]==0;j++){
				 arr[x][j]=1;
				 //debug("this is",x,j,1);
			 }
			 steps++;
		 }
	 }
//	 debug("steps",steps);
	 for(i=1;i<=n;i++){
		 for(j=1;j<=m;j++){
			 if(arr[i][j]==0){
				 steps++;
				 vec.pb(mp(mp(i,j),1));
				 for(k=i;k<=n && arr[k][j]==0;k++)arr[k][j]=1;
			 }

		 }
	 }
	 printf("%lld\n",steps);
	 tr(vec,it)
		 printf("%lld %lld %lld\n",it->first.first, it->first.second, it->second);
	 
	 
}

