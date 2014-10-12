
//#include GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL     //uncomment for testing from local file
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

inline void inputString(string &s)
{
    char ch=getchar_unlocked();
    s="";
    while(ch!='\n')
        s+=ch, ch=getchar_unlocked();
}

bool arr[1000000];
lld len;
string str;

inline lld val(lld start, lld end){
	lld sum=0,p=1,i;
	for(i=end;i>=start;i--){
		sum=sum+p*(str[i]-'a'+1);
		p*=27;
	}
	return sum;
}

bool check(lld n){
	while(n){
		if(n%27==0)return false;
		n/=27;
	}
	return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 inputString(str);
	 len = str.length();
	 lld i;

	 for(i=0;i<1000000;i++)arr[i]=true;
	 for(i=0;i<len;i++){
		 lld k = val(i,i);
		 debug(i,i,val(i,i),val(i,i));
		 arr[k] = false;
		 if(i<len-1){
			 arr[val(i,i+1)] = false;
			 debug(i,i+1,val(i,i+1));
		 }
			 if(i<len-2)
			 {
				 arr[val(i,i+2)] = false;
				 debug(i,i+2,val(i,i+2));
			 }
			 if(i<len-3){
				 arr[val(i,i+3)] = false;
				 debug(i,i+3,val(i,i+3));
			 }
	 }
	 for(i=1;i<1000000;i++)if(arr[i] && check(i))break;
	 debug("this is i",i);
	 string rr="";
	 while(i){
		 lld k = (i%27)+'a'-1;
//		 debug(k);
		 rr=(char)k+rr;
		 i/=27;
	 }
	 cout<<rr<<endl;
}

