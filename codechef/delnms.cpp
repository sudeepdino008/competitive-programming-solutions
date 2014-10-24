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
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;

inline void inputInt(lld &n )
{
	n=0;
 	lld ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

string int_to_string(int n)
{
	stringstream ss;
	ss<<n;
	return ss.str();
}

int main()
{
	lld n,i,j,count=1,ncount=0;
	inputInt(n);
	lld B[n+1];
	for(i=1;i<=n;i++)
		inputInt(B[i]);
	string s="";
	int A[n+1];
	bool flag=true;
	for(i=1;i+2<=n;i+=2)
	{
		if(B[i]!=B[i+2])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		s+="1 2\n";
		j=0;
		for(i=2;i<=n;i+=2)
			A[j++]=B[i];
		n=n/2;
		ncount++;
	}
	if(B[1]==B[n] && (n>=2 && B[1]!=B[2]) && (n>=2 && (B[n]!=B[n-1])))
	{
		for(i=2;i<=n-1;i++)
			A[i-1]=B[i];
		s+="1 "+int_to_string(n-1)+"\n";
		n=n-2;
		ncount++;
	}
	else
	{
		for(i=1;i<=n;i++)
			A[i]=B[i];
	}

	for(i=1,j=1;i<=n && j<=n;)
	{
		
		for(j=i+1;j<=n;j++)
		{
			if(A[j]!=A[i])
			{
				i=j;
				count++;
				break;
			}
		}
	}
	printf("%lld\n",(count+ncount));
	lld frequency[count+1],k=count;
	cout<<s;
	for(i=n,j=n;i>=1 && j>=1;)
	{
		frequency[k]=1;
		for(j=i-1;j>=1;j--)
		{
			if(A[j]==A[i])
				frequency[k]++;
			else
			{
				i=j;
				break;
			}
		}
		k--;
	}
	k=n+1;
	for(i=count;i>=1;i--)
	{
		printf("%lld 1\n",(k-frequency[i]));
		k-=frequency[i];
	}
}
