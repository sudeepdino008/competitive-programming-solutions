#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <sys/time.h>
#include <iomanip>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
using namespace std;

inline void inputInt(lld &n )
{
	n=0;
 	int ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
		ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

lld expo(int n, lld p, lld mod)
{
	if(p==0)
		return 1;
	lld res=expo(n,p/2,mod);
	if(p%2==0)
		return (res*res)%mod;
	return (((res*res)%mod)*n)%mod;
}

int main()
{
	lld prime_array[]={ 2
						,3
						,5
						,	7
						,	11
						,	13
						,	17
						,	19
						,	23
						,	29
						,	31
						,	37
						,	41
						,	43
						,	47
						,	53
						,	59
						,	61
						,	67
						,	71
						,	73
						,	79
						,	83
						,	89
						,	97};
	
	lld n,m;
	inputInt(n);
	lld k,i,j,t;
	lld a[n],count;
	map<lld,lld> array[n];
	
	for(i=0;i<n;i++)
		inputInt(a[i]);
	
	inputInt(t);
	for(i=0;i<n;i++)
	{
		m=a[i];
		
		for(map<lld,lld>::iterator it=array[i].begin();it!=array[i].end() && m!=1;it++)
		{
			for(j=0;j<25;j++)
			{
				count=0;
				while(m!=1)
				{
					m/=prime_array[j];
					count++;
				}
				   
				if(i==0)
					array[i][prime_array[j]]=count;
				else
					array[i][prime_array[j]]=array[i-1][prime_array[j]]+count;
				cout<<array[i][prime_array[j]]<<endl;
					
			}
		}
		
		
	}
	/*for(i=0;i<n;i++)
	  {
	  for(map<lld,lld>::iterator it=array[i].begin();it!=array[i].end();it++)
	  cout<<a[i]<<" "<<it->first<<" "<<it->second<<endl;
	  cout<<endl;
	  }*/
 
	lld right, left, mod;

	while(t--)
	{
		map<lld,lld> ans;
		inputInt(left);
		inputInt(right);
		inputInt(mod);
		right--;
		left--;
		lld result=1;
		
		for(map<lld,lld>::iterator it=array[right].begin();it!=array[right].end();it++)
		{
			if(left!=0 && array[left-1].find(it->first)!=array[left-1].end())
				ans[it->first]=array[right][it->first]-array[left-1][it->first];
			else
				ans[it->first]=array[right][it->first];
		}

		for(map<lld,lld>::iterator it=ans.begin();it!=ans.end();it++)
		{

			result=(result*expo(it->first,ans[it->first],mod))%mod;
		}
			
		printf("%lld\n",result);
		
	}
}
