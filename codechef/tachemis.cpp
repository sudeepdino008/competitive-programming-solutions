
//#define DEBUG       //comment when you have to disable all debug macros.
//#define NDEBUG    //comment when all assert statements have to be disabled.
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

pair<char,int> input[100000];

inline string preCompute(const string &s)
{
	string result="^";
	int len=s.length();
	if(len==0)
		return "^$";
	for(int i=0;i<len;i++)
		result=result+" "+s.substr(i,1);
	result=result+" $";
	return result;
}

void manacher(const string &s)      //return number of palindrome excluding those of length 1.
{
	string result=preCompute(s);
	int len=result.length();
	int R=0,C=0,i;
	int temp[len],i_mirror;
	for(i=1;i<len-1;i++)
	{
		i_mirror=2*C-i;
		temp[i]=(R>i)?min(R-i,temp[i_mirror]):0;
		
		while(result[i+temp[i]+1]==result[i-temp[i]-1])
			temp[i]++;
		if(i+temp[i]>R)
		{
			C=i;
			R=i+temp[i];
		}
	}
	lld sum=0;
	for(i=2;i<len-1;i+=2)
	{
		int y=input[i/2-1].second;
		sum+=temp[i]+2*min(input[i-temp[i]].second,input[i+temp[i]].second)+y*(y+1)/2-1;
	}
	printf("%lld\n",sum);
}


int main()
{
	lld t,k,i;
	inputInt(t);
	while(t--)
	{
		inputInt(k);
		string s="";
		for(i=0;i<k;i++)
		{
			cin>>input[i].first;
			inputInt(input[i].second);
			s=s+input[i].first;
		}
		manacher(s);
	}
}


