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
#define lld long long int
#define MOD 1000000007
#define correct(i,j) ((i)>=0 && (j)>=0 && (i)<r && (j)<c)
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

int main()
{
	lld t,r,c,count,i,j;
	map<char,bool> m;
	m['^']=true;
	m['#']=false;
	inputInt(t);
	while(t--)
	{
		inputInt(r);
		inputInt(c);
		bool arr[r][c];
		char ch;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				cin>>ch, arr[i][j]=m[ch];
		}
		count=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(correct(i-1,j) && correct(i-2,j) && arr[i-1][j] && arr[i-2][j] && arr[i][j])
				{	
				if(correct(i+1,j) && correct(i+2,j) && arr[i+1][j] && arr[i+2][j] && arr[i][j])
				{
				 if(correct(i,j-1) && correct(i,j-2) && arr[i][j-1] && arr[i][j-2] && arr[i][j])
				 {
				if(correct(i,j+1) && correct(i,j+2) && arr[i][j+1] && arr[i][j+2] && arr[i][j])
					count++;
				 }}}
			}
		}
		printf("%lld\n",count);
	}
}
