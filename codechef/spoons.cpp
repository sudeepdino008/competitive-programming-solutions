
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
#define lld unsigned long long int
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


vector<lld> arr{
	-1,1,2,3,6,10,20,35,70,126,252,462,924,1716,3432,6435,12870,24310,48620,92378,184756,352716,705432,1352078,2704156,5200300,10400600,20058300,40116600,77558760,155117520,300540195,601080390,1166803110,2333606220,4537567650,9075135300,17672631900,35345263800,68923264410,137846528820,269128937220,538257874440,1052049481860,2104098963720,4116715363800,8233430727600,16123801841550,32247603683100,63205303218876,126410606437752,247959266474052,495918532948104,973469712824056,1946939425648112,3824345300380220,7648690600760440,15033633249770520,30067266499541040,59132290782430712,118264581564861424,232714176627630544,465428353255261088,916312070471295267};

lld combi(lld n, lld r)
{
	if(r<n-r)
		return combi(n,n-r);
	lld p=1,i,j=1;
	for(i=r+1;i<=n;i++)
	{
		p=p*i;
		while(j<=n-r && p%j==0)
			p=p/j, j++;
	}
	while(j<=n-r)
		p=p/j, j++;
	return p;
	
}

lld required(lld y)
{
	/*lld i;
	for(i=1;i<=63 && arr[i]<y;i++);
	return i;*/
	return lower_bound(arr.begin(), arr.end(), y)-arr.begin();
/*
	lld start=1, end=63, mid=(start+end)/2;
	while(start<end)
	{
		if(arr[mid]>y)
		{
			if(mid>1 && arr[mid-1]<y)
				return mid;
			end=mid-1;
		}
		else if(arr[mid]<y)
		{
			if(mid<63 && arr[mid+1]>y)
				return mid+1;
			start=mid+1;
		}
		else return mid;
		mid=(start+end)/2;
	}
	return mid+1;
*/
}

int main()
{
	lld n,t;
	/*for(n=1;n<=63;n++)
	  cout<<combi(n,n/2)<<",";*/
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		printf("%lld\n",(lld)required(n));
	}
	
}

