
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

vector<int> prime={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};



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

lld count_prime(lld y)
{
	lld i;
	for(i=0;i<95;i++)
	{
		if(prime[i]>y)
			break;
	}
	return i;

}

int main()
{
	lld T,t,r,c,i,j,k,ans=0;
	char ch;
	map<char,bool> m;
	m['^']=true;
	m['#']=false;
	inputInt(T);
	while(T--)
	{
		inputInt(r);
		inputInt(c);
		bool arr[r][c];
		lld count_l[r][c],count_r[r][c],count_u[r][c],count_d[r][c];

		for(i=0;i<r;i++)   //input
		{
			for(j=0;j<c;j++)
				cin>>ch, arr[i][j]=m[ch], count_l[i][j]=count_r[i][j]=count_u[i][j]=count_d[i][j]=0;
		}
	
	
		//right array
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{

				if(!arr[i][j] || count_r[i][j]!=0)
					continue;
				for(k=j+1;k<c && arr[i][k];k++)
					count_r[i][j]++;
   
				for(t=j+1;t<k;t++)
					count_r[i][t]=count_r[i][j]-(t-j);
			}
		}
		//left array
		for(i=0;i<r;i++)
		{
			for(j=c-1;j>=0;j--)
			{
				if(!arr[i][j] || count_l[i][j]!=0)
					continue;
				for(k=j-1; k>=0 && arr[i][k];k--)
					count_l[i][j]++;
				
				for(t=j-1;t>k;t--)
					count_l[i][t]=count_l[i][j]-(j-t);
			}
		}
		//down array
		for(j=0;j<c;j++)
		{
			for(i=0;i<r;i++)
			{
				if(!arr[i][j] || count_d[i][j]!=0)
					continue;
				for(k=i+1;k<r && arr[k][j];k++)
					count_d[i][j]++;
				for(t=i+1;t<k;t++)
					count_d[t][j]=count_d[i][j]-(t-i);
			}
		}
		//up array
		for(j=0;j<c;j++)
		{
			for(i=r-1;i>=0;i--)
			{
				if(!arr[i][j] || count_u[i][j]!=0)
					continue;
				for(k=i-1;k>=0 && arr[k][j];k--)
					count_u[i][j]++;
				for(t=i-1;t>k;t--)
					count_u[t][j]=count_u[i][j]-(i-t);
			}
		}
		ans=0;
		lld val;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				val=min(count_l[i][j],count_d[i][j]);
				val=min(val,count_r[i][j]);
				val=min(val,count_u[i][j]);
				ans+=count_prime(val);
			}
		}
		printf("%lld\n",ans);

	}
	
}
