
//#define GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
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

inline void inputString(string &s)
{
    char ch=getchar_unlocked();
	 while(ch=='\n')
		 ch=getchar_unlocked();
    s=""+ch;
    while(ch!='\n')
        s+=ch, ch=getchar_unlocked();
	 
}


int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld t, array[51][51],H,W,i,j,maxi,k,c=0;
	char ch[51][51];
	string str;
	inputInt(H);
	inputInt(W);
	while(H!=0 && W!=0)
	{
		for(i=1;i<=H;i++)
		{
			cin>>str;
			for(j=1;j<=W;j++)
			{
				ch[i][j] = str[j-1];
				array[i][j] = (ch[i][j]=='A')?1:0;
			}

		}
		for(k='A';k<'Z';k++)
		{
			for(i=1;i<=H;i++)
			{
				for(j=1;j<=W;j++)
				{
					//check b1
					if(i!=1 && j!=1 && array[i][j]!=0 && ch[i][j]==k && ch[i][j]+1==ch[i-1][j-1])
						array[i-1][j-1] = array[i][j]+1;
					//check b2
					if(i!=1 && ch[i][j]==k && array[i][j]!=0 && ch[i-1][j]==ch[i][j]+1)
						array[i-1][j] = array[i][j]+1;
					//check b3
					if(i!=1 && j!=W && ch[i][j]==k && array[i][j]!=0 && ch[i-1][j+1]==ch[i][j]+1)
						array[i-1][j+1] = array[i][j]+1;
					//check b4
					if(j!=1 && ch[i][j]==k && array[i][j]!=0 && ch[i][j-1]==ch[i][j]+1)
						array[i][j-1] = array[i][j]+1;
					//check b6
					if(j!=W && ch[i][j]==k && array[i][j]!=0 && ch[i][j+1]==ch[i][j]+1)
						array[i][j+1] = array[i][j]+1;
					//b7
					if(i!=H && j!=1 && ch[i][j]==k && array[i][j]!=0 && ch[i+1][j-1]==ch[i][j]+1)
						array[i+1][j-1] = array[i][j]+1;
					//b8
					if(i!=H && ch[i][j]==k && array[i][j]!=0 && ch[i+1][j]==ch[i][j]+1)
						array[i+1][j]=array[i][j]+1;
					//b9
					if(i!=H && j!=W && ch[i][j]==k && array[i][j]!=0 && ch[i+1][j+1]==ch[i][j]+1)
						array[i+1][j+1]=array[i][j]+1;
				}
			}
		}
		maxi = -1;
		for(i=1;i<=H;i++)
		{
			for(j=1;j<=W;j++)
				maxi = max(maxi, array[i][j]);
			//cout<<endl;
		}
		c++;
		printf("Case %lld: %lld\n",c,maxi);
		
		inputInt(H);
		inputInt(W);
	}
	 
}

