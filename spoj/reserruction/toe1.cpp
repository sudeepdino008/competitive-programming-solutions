
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

inline void inputString(string &s)
{
    char ch=getchar_unlocked();
    s="";
    while(ch!='\n')
        s+=ch, ch=getchar_unlocked();
}
string s[3];

lld count(char ch){
	lld count=0,i,j;
	fa(i,0,2)fa(j,0,2){
		//debug(i,j,s[i][j],ch);
		if(s[i][j]==ch)count++;
	}
	return count;
}

bool win(char ch){
	bool fr,fc;
	lld i,j;
	//row and column
	
	fa(i,0,2){
		fr = fc = true;
		fa(j,0,2){
			//	debug(i,j,s[i][j],ch,fr,fc);
			if(s[i][j]!=ch)fr=false;
			if(s[j][i]!=ch)fc=false;
		}
		if(fr || fc)return true;
	}
	
	if(s[0][0]==s[1][1] && s[1][1]==s[2][2] && s[2][2]==ch)return true;
	if(s[0][2]==s[1][1] && s[1][1]==s[2][0] && s[2][0]==ch)return true;
	return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld t,n0,n1;
	 bool w0,w1;
	 string str;
	 inputInt(t);
	 
	 while(t--){
//		 inputString(s[0]);
//		 inputString(s[1]);
//		 inputString(s[2]);
		 cin>>s[0];
		 cin>>s[1];
		 cin>>s[2];
		 n0 = count('O');
		 n1 = count('X');
		 w0 = win('O');w1 = win('X');
		 //check 1
		 debug("string print",s[0],s[1],s[2]);
		 if(!(n1==n0 || n1==n0+1))printf("no\n");
		 else if(w0 && w1)printf("no\n");
		 else if(w1 && n1==n0)printf("no\n");
		 else	if(w0 && n1==n0+1)printf("no\n");
		 else printf("yes\n");
		 
		 if(t==0)break;
		 string sp;
		 inputString(sp);
	 }
}

