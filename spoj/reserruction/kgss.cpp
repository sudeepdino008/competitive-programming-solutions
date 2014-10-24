

#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
//#include GRAPH
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
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

 	T ch=getchar_unlocked();
	/*int sign=1;
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
		 n*=sign;*/
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

typedef struct n{
	lld max, sec_max;
	n(){
		max = sec_max = 0;
	}
	n(lld _max, lld _sec_max){
		max = _max;
		sec_max = _sec_max;
	}
}node;

node tree[1<<20];
lld arr[100001];

void update(lld index, lld ileft, lld iright, lld uindex, lld x){
	if(uindex<ileft || uindex>iright || ileft>iright)return;
	if(iright==ileft){
		tree[index].max = x;
		return;
	}
	lld mid = (ileft+iright)/2;
	update(2*index, ileft, mid, uindex,x);
	update(2*index+1, mid+1, iright, uindex, x);
	vector<lld> easy;
	easy.pb(tree[2*index].max);
	easy.pb(tree[2*index+1].max);
	easy.pb(tree[2*index].sec_max);
	easy.pb(tree[2*index+1].sec_max);
	sort(easy.begin(), easy.end());
	tree[index].max = easy[3];
	tree[index].sec_max = easy[2];
}

node query(lld index, lld ileft, lld iright, lld rleft, lld rright){
	node n;
	if(iright<rleft || ileft>rright || rleft>rright)return n;
	
	if(ileft==rleft && iright==rright){
		return tree[index];
	}
	lld mid=(ileft+iright)/2;
	vector<lld> maxVal;
	node nl = query(2*index, ileft, mid, rleft, min(mid, rright));
	node nr = query(2*index+1, mid+1, iright, max(mid+1, rleft), rright);
	maxVal.pb(nl.max);
	maxVal.pb(nl.sec_max);
	maxVal.pb(nr.max);
	maxVal.pb(nr.sec_max);
	sort(maxVal.begin(), maxVal.end());
	return node(maxVal[3], maxVal[2]);
}

void build_tree(lld index, lld left, lld right){
	if(left>right){
		tree[index].max = tree[index].sec_max = 0;
		return;
	}
	if(left==right){
		tree[index].max = arr[left];
		tree[index].sec_max = 0;
		return;
	}
	lld mid = (left+right)/2;
	build_tree(2*index, left, mid);
	build_tree(2*index+1, mid+1, right);
	vector<lld> easy;
	easy.pb(tree[2*index].max);
	easy.pb(tree[2*index+1].max);
	easy.pb(tree[2*index].sec_max);
	easy.pb(tree[2*index+1].sec_max);
	sort(easy.begin(), easy.end());
	tree[index].max = easy[3];
	tree[index].sec_max = easy[2];
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,i,q,left,right;
	 inputInt(n);
	 for(i=1;i<=n;i++)inputInt(arr[i]);
	 build_tree(1,1,n);
	 inputInt(q);
	 while(q--){
		 char option = getchar_unlocked();
		 inputInt(left); inputInt(right);
		 if(option=='Q')
		 {
			 node nod = query(1,1,n,left,right);
			 printf("%lld\n",nod.max+nod.sec_max);
		 }
		 else update(1,1,n,left,right);
	 }
}

