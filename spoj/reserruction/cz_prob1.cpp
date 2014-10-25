

#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
//#include GRAPH
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cstdio>
#include <cmath>
#include <vector>
#define present(c,x) ((c).find(x) != (c).end()) 
#define pb push_back
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define lld long long int
using namespace std;

template<class T>
inline void inputInt(T &n )
{
	n=0;

 	T ch=getchar_unlocked();
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}



#define SIZE 8000
set<lld> primes;
void init()
{
	lld count=0,i,j;
	vector<lld> cop;
	cop.pb(-1);
	cop.pb(-1);
	for(i=2;i<=SIZE;i++)
		cop.pb(i);
	for(i=2;i<=SIZE;i++)
	{
		if(cop[i]!=-1)
		{
			primes.insert(i);
			for(j=2*i;j<=SIZE;j+=i)
				cop[j]=-1;
		}
	}

}

lld arr[8000][3];

lld recursion(lld n, lld k){
	if(n<0 || k<=0)return 0;
	if(arr[n][k]!=-1)return arr[n][k];
	if(k==1 || n==0)return arr[n][k]=1;
	return arr[n][k]=recursion(n,k-1)+recursion(n-k,k);
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,k,t,x1,x2;
	 inputInt(t);
	 init();
	 

	 vector<lld> vec;
	 set<lld> temp;
	 memset(arr,-1,sizeof arr);

	 //for(n=0;n<=10;n++)for(k=0;k<=3;k++)debug(n,k,recursion(n,k));
	 
	 for(x1=0;x1*x1<=8000;x1++){
		 for(x2=0;x2*x2<=8000;x2++){
			 if(present(primes,x1*x1+x2*x2) && x1*x1+x2*x2<8000)
				 temp.insert(x1*x1+x2*x2);
		 }
	 }
	 tr(temp,it){vec.pb(*it);}
	 
	 while(t--){
	 	 inputInt(n);
	 	 inputInt(k);
	 	 //debug("sssssssss",vec[n-1]);
	 	 printf("%lld\n",recursion(vec[n-1],k));
	 }
	 	 
	 
}

