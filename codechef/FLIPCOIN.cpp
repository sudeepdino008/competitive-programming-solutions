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
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define pb push_back
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;

int T[300005];
	int flag[300005];


void inputInt(int &n )
{
	n=0;
	int ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

inline int query(int i, int x1,int x2, int a, int b)
{
	//cout<<"s "<<i<<" "<<x1<<" "<<x2<<" "<<a<<" "<<b<<" "<<T[i].flag<<endl;
	if(x1==a && x2==b)
		return T[i];
	
	int mid=(x1+x2)>>1,ans,L=i<<1, R=L+1;
	if(b<=mid)
		ans=query(L,x1,mid,a,b);
	else if(a>mid)
		ans=query(R,mid+1,x2,a,b);
	else
		ans=query(L,x1,mid,a,mid)+query(R,mid+1,x2,mid+1,b);
	if(flag[i])
		return b-a+1-ans;
	return ans;
}

inline void update_segment_tree(int i, int x1, int x2, int a, int b)
{
	if(x1==a && x2==b)
	{
		flag[i]^=1;
		T[i]=x2-x1+1-T[i];
		return;
	}
	int mid=(x1+x2)>>1, L=i<<1,R=L+1;
	if(b<=mid)
		update_segment_tree(L,x1,mid,a,b);
	else if(a>mid)
		update_segment_tree(R,mid+1,x2,a,b);
	else
	{
		update_segment_tree(L,x1,mid,a,mid);
		update_segment_tree(R,mid+1,x2,mid+1,b);
	}
	T[i]=T[L]+T[R];
	if(flag[i])
		T[i]=x2-x1+1-T[i];
	
}

int main()
{
	int n,q,op,a,b;
	inputInt(n);
	inputInt(q);
	while(q--)
	{
		inputInt(op);
		inputInt(a);
		inputInt(b);
		if(op)printf("%d\n",query(1,0,n-1,a,b));
		else update_segment_tree(1,0,n-1,a,b); //print(n);
				  
	}


}
