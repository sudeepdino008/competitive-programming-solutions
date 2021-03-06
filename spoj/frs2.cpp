
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
#define lld unsigned long long int
#define gcd __gcd
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
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



/*
[x1 x2|x3 x4]
 */

lld MOD=1000000007;

struct Matrix{
	
	lld x1,x2,x3,x4;
	Matrix()
	{
		x1=x2=x3=x4=0;
	}
	Matrix(lld _x1,lld _x2, lld _x3, lld _x4)
	{
		x1=_x1;
		x2=_x2;
		x3=_x3;
		x4=_x4;
	}
	
	Matrix operator*(const Matrix &m1)
	{
		return Matrix(((x1*m1.x1)%MOD + (x2*m1.x3)%MOD)%MOD, ((x1*m1.x2)%MOD + (x2*m1.x4)%MOD)%MOD, ((x3*m1.x1)%MOD + (x4 * m1.x3)%MOD)%MOD, (((x3*m1.x2)%MOD) + (x4*m1.x4)%MOD)%MOD);
	}
	
	Matrix operator%(const lld &m)
	{
		return Matrix(x1%m, x2%m, x3%m, x4%m);
	}
	

};

ostream &operator<<(ostream &out, const Matrix &m)
{
		out<<m.x1<<" "<<m.x2<<" "<<m.x3<<" "<<m.x4;
		return out;
}




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


lld nth_fibo(lld n)
{
	if(n==0 || n==1) 
		return n;
	n--;
	lld v=n, i=0;
	string rev="";

	for(;v!=1;v=v>>1)
		rev=((v&1)?"1":"0")+rev;

	Matrix alpha(1,1,1,0), M=alpha;
	while(n!=1)
	{
		M=M*M;
		if(rev[i++]=='1')
			M=M*alpha;
		n=n>>1;
	}
	M=M*Matrix(1,1,0,1);
	return M.x1;
}

int main()
{
	lld t, k,n,ans;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		ans=nth_fibo(nth_fibo(n));
		cout<<ans<<"\n";
	}
}
