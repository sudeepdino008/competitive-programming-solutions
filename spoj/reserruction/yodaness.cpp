
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


lld merge(lld arr[], lld start, lld end){
	lld mid = (end+start)/2, inv_count = 0;
	lld right[end-mid], left[mid-start+1], i, lind, rind;
	for(i=start;i<=mid;i++)left[i-start] = arr[i];
	for(i=mid+1;i<=end;i++)right[i-mid-1] = arr[i];
	
	i=0;
	lind = rind = 0;
	for(i=start; i<=end;i++){
		if(rind==end-mid || (lind<=mid-start && left[lind]<=right[rind]))
			arr[i] = left[lind++];
		else arr[i] = right[rind++], inv_count += (mid-(lind+start)+1);
		
	}
	return inv_count;
}


lld merge_sort(lld arr[], lld start, lld end){

	if(start>=end)return 0;

	lld mid = (end+start)/2;
	
	lld s1 = merge_sort(arr,start, mid);
	lld s2 = merge_sort(arr, mid+1, end);
	lld s3 = merge(arr, start, end);
	return s1+s2+s3;
}


lld inversion_count(lld arr[], lld size){
	return merge_sort(arr,0,size-1);
}

inline void inputString(string &s)
{
    char ch=getchar_unlocked();
    s="";
    while(ch!='\n' || ch==' ')
        s+=ch, ch=getchar_unlocked();
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t, n, i;
	 string s;
	 inputInt(t);
	 while(t--){
		 inputInt(n);
		 lld arr[n];
		 map<string, lld> mp;
		 for(i=0;i<n;i++){
			 cin>>s;
			 mp[s] = i+1;
		 }
		 for(i=0;i<n;i++){
			 cin>>s;
			 arr[i] = mp[s];
		 }
		 
		 printf("%lld\n", inversion_count(arr,n));
	 }
}

