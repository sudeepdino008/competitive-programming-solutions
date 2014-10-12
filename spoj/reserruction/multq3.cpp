
//#include GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
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

typedef struct{
	lld mod0, mod1, mod2;
}node;

node tree[1<<18];
lld lazy[1<<18];

void build_tree(lld n, lld i, lld j){
	lazy[n] = 0;
	if(i==j){
		tree[n].mod0 = 1;
		tree[n].mod1 = tree[n].mod2 = 0;
		return;
	}
	build_tree(2*n, i, (i+j+1)/2-1);
	build_tree(2*n+1, (i+j+1)/2, j);
	tree[n].mod0 = tree[2*n].mod0+tree[2*n+1].mod0;
	tree[n].mod1 = tree[n].mod2 = 0;
}

inline void update_node(lld pos, lld val){
	if(val==0)return;
	lld a, b, c;
	a = tree[pos].mod0;
	b = tree[pos].mod1;
	c = tree[pos].mod2;
	tree[pos].mod0 = (val==1)?c:b;
	tree[pos].mod1 = (val==1)?a:c;
	tree[pos].mod2 = (val==1)?b:a;
	lazy[pos] = (lazy[pos]+val)%3;
}

void print_tree(lld n, lld i, lld j){
	debug("printing node:", n, i, j);
	debug("mod0=",tree[n].mod0);
	debug("mod1=",tree[n].mod1);
	debug("mod2=",tree[n].mod2);
	debug("lazy=",lazy[n]);
	cout<<endl;
	if(i>=j)return;
	print_tree(2*n,i, (i+j+1)/2-1);
	print_tree(2*n+1, (i+j+1)/2, j);
}

void update_tree(lld n, lld i, lld j, lld x, lld y){
	if(j<x || y<i || i>j || x>y){
		return;
	}
	if(i==x && y==j){
		update_node(n, 1);
		return;
	}
	lld m = (i+j+1)/2-1;
	update_node(2*n, lazy[n]);
	update_node(2*n+1, lazy[n]);
 
	update_tree(2*n, i, m, x, min(y,m));
	update_tree(2*n+1, m+1, j, max(x, m+1), y);
	
	lazy[n] = 0;
	tree[n].mod0 = tree[2*n].mod0 + tree[2*n+1].mod0;
	tree[n].mod1 = tree[2*n].mod1 + tree[2*n+1].mod1;
	tree[n].mod2 = tree[2*n].mod2 + tree[2*n+1].mod2;
}

lld query(lld n, lld i, lld j, lld x , lld y, lld p){
	if(j<x || y<i || i>j || x>y){
		return 0;
	}
	if(i==x && y==j){
		if(p==0)
			return tree[n].mod0;
		if(p==1)return tree[n].mod2;
		return tree[n].mod1;
	}
	lld m=(i+j+1)/2-1, p1, p2;
	p1 = query(2*n,i,m,x,min(y,m), (p+lazy[n])%3);
	p2 = query(2*n+1,m+1,j,max(x,m+1),y, (p+lazy[n])%3);
	return p1+p2;
}



int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,q,op,u,v;
	 inputInt(n);
	 inputInt(q);
	 build_tree(1,1,n);
//	 print_tree(1,1,n);
	 while(q--){
		 inputInt(op);
		 inputInt(u);
		 inputInt(v);
		 u++;
		 v++;
		 if(op)printf("%lld\n",query(1,1,n,u,v,0));
		 else {
			 update_tree(1,1,n,u,v);
//			  debug("update......................")print_tree(1,1,n);
		 }
	 }
}


