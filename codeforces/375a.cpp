

//#define DEBUG       //comment when you have to disable all debug macros.
//#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
//#define GRAPH
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

bool check(char ch, char x, bool &b){
	if(ch==x){
		if(b)return false;
		else return b=true;
	}
	return false;
}
int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 bool p1, p6, p8, p9,flag=true;
	 lld zeroCount=0;
	 string val[]={"1869", "1896", "9168", "1698", "6198", "8619", "1968"};
	 p1=p6=p8=p9=false;
	 string str,answer="";
	 cin>>str;
	 lld i, len=str.length(), modulo=0;
	 for(i=0;i<len;i++){
		 if(check(str[i], '1', p1))continue;
		 if(check(str[i], '6', p6))continue;
		 if(check(str[i], '8', p8))continue;
		 if(check(str[i], '9', p9))continue;
		 if(flag && str[i]=='0'){
			 zeroCount++;
			 continue;
		 }
		 else flag=false;
		 modulo=(10*modulo+str[i]-'0')%7;
		 answer+=str[i];
	 }
	 modulo=(modulo*4)%7;
	 debug(zeroCount, modulo, answer);
	 if(answer=="")
	 {
		 answer+=val[modulo];
		 for(;zeroCount;zeroCount--)modulo=(10*modulo)%7, answer+="0";
	 }
	 else {
		 for(;zeroCount;zeroCount--)modulo=(10*modulo)%7, answer+="0";
		 answer+=val[modulo];
	 }

	 

	 cout<<answer<<"\n";
}

