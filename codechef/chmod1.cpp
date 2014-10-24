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

inline void inputInt(int &n )
{
	n=0;
 	int ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
		ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int expo(int n, int p, int mod)
{
	if(p==0)
		return 1;
	int res=expo(n,p/2,mod);
	if(p%2==0)
		return (res*res)%mod;
	return (((res*res)%mod)*n)%mod;
}

int main()
{
	srand((unsigned int)time(NULL));
	int prime_array[]={ 2
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
	
	int n=1000,m;   //test
	//inputInt(n);
	int k=ceil(log2(n)),i,j;
	int a[n];
	/*for(i=0;i<n;i++)
	  inputInt(a[i]);*/
	//test
	cout<<"printing elements\n";
	for(i=0;i<n;i++)
		a[i]=rand()%100+1, cout<<a[i]<<" ";
	cout<<endl<<endl;
	


	int M[n][k][25];
	for(i=0;i<n;i++)
	{	

		//M[i][0]=a[i];
		m=a[i];
		for(j=0;j<25;j++)
		{
			int count=0;
			while(m%prime_array[j]==0)
				m/=prime_array[j],count++;
			M[i][0][j]=count;
		}
	}
	

	int p,s;
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;i+(1<<j)-1<n;i++)
		{
			s=0;
			for(p=0;p<25;p++)
			{
				M[i][j][p]=M[i][j-1][p]+M[i+(1<<(j-1))][j-1][p];
				s+=M[i][j][p];
			}
		}
	}
	int t=100;
	//inputInt(t);
	while(t--)
	{
	
		//inputInt(i);
		//inputInt(j);
		//inputInt(m);
		int i1=rand()%n+1;
		int j1=rand()%(n-i1+1)+i1;
		if(i1>j1)
			swap(i1,j1);
		m=rand()%100+1;
		int check=1;
		i=i1-1;
		j=j1-1;
		for(p=i1;p<=j1;p++)
			check=(check*a[p-1])%m;
		int sum[25];
		memset(sum,0,sizeof sum);
		k=floor(log2(j-i+1));
		while(i<n)
		{
			for(p=0;p<25;p++)
				sum[p]+=M[i][k][p];
			if((1<<k)==(j-i+1))
				break;
			else
				i+=(1<<k);
			k=floor(log2(j-i+1));
			
			
		}
				int answer;
	
		answer=1;
		for(i=0;i<25 && answer;i++)
			answer=(answer*expo(prime_array[i],sum[i],m))%m;
		cout<<i1<<" "<<j1<<" "<<m<<" "<<check<<" "<<answer<<endl;
		if(check!=answer)
		{
			cout<<"wrong answer!";
			break;
		}
		printf("%d\n\n\n\n\n\n\n",answer);
	}
	
}
