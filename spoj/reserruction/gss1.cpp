//#include GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
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

struct nod{
	lld leftS, rightS, best, sum;
	bool neg; //if node contains negative element
};
typedef struct nod node;

node tree[1<<18];
lld arr[50001];

void build_tree(lld n, lld i, lld j){
	if(i==j){
		tree[n] = (nod){arr[i],arr[i],arr[i],arr[i], (arr[i])};
		return;
	}
	lld m = (i+j+1)/2-1;
	build_tree(2*n, i, m);
	build_tree(2*n+1, m+1, j);
	
	tree[n].leftS = max(tree[2*n].leftS, (tree[2*n].leftS==tree[2*n].sum && tree[2*n].leftS==tree[2*n].rightS && tree[2*n].leftS>0)?(tree[2*n].leftS+tree[2*n+1].leftS):INT_MIN);
	tree[n].rightS = max(tree[2*n+1].rightS, (tree[2*n+1].rightS==tree[2*n+1].sum && tree[2*n+1].rightS>0 && tree[2*n+1].rightS==tree[2*n+1].leftS)?(tree[2*n].rightS+tree[2*n+1].rightS):INT_MIN);
	tree[n].best = max(tree[n].leftS, 
							 max(tree[n].rightS, 
							 max(tree[2*n].best, 
								  max(tree[2*n+1].best,tree[2*n].rightS+tree[2*n+1].leftS))));
	tree[n].sum = tree[2*n].sum+tree[2*n+1].sum;
}

node query(lld n, lld x, lld y, lld i, lld j){
	debug(n,x,y,i,j);
	if(j<x || i>y || x>y || i>j)return (nod){INT_MIN, INT_MIN, INT_MIN, INT_MIN};
	if(x==i && y==j)return tree[n];
	lld m = (i+j+1)/2-1;
	node nl = query(2*n, x, min(y,m), i, m);
	node nr = query(2*n+1, max(x,m+1) ,y , m+1, j);
	node p;
	p.leftS = max(nl.leftS, (nl.leftS==nl.sum && nl.leftS>0 && nl.leftS==nl.rightS)?(nl.leftS+nr.leftS):INT_MIN);
	p.rightS = max(nr.rightS, (nr.rightS==nr.sum && nr.rightS>0 && nr.leftS==nr.rightS)?(nl.rightS+nr.rightS):INT_MIN);
	p.best = max(p.leftS, 
							 max(p.rightS, 
							 max(nl.best, 
								  max(nr.best,nl.rightS+nr.leftS))));
	p.sum = nl.sum+nr.sum;
	return p;
}

void print_tree(lld n, lld i, lld j){
	if(i>j)return;
	if(i==j){
		debug(n, i, j, tree[n].leftS, tree[n].rightS, tree[n].sum, tree[n].best);
		return;
	}
	debug(n, i, j, tree[n].leftS, tree[n].rightS, tree[n].sum, tree[n].best);
	lld m = (i+j+1)/2-1;
	print_tree(2*n, i, m);
	print_tree(2*n+1, m+1, j);
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,m,i,a,b;
  
	 inputInt(n);
	 for(i=1;i<=n;i++)inputInt(arr[i]);
	 build_tree(1,1,n); 
//	  print_tree(1,1,n);
	 inputInt(m);
	 while(m--){
	 	 inputInt(a);
	 	 inputInt(b);
		 node na = query(1,a,b,1,n);
		 debug("node debug",na.leftS, na.rightS, na.sum, na.best);
	 	 printf("%lld\n",na.best);
	 }
	 
	 
}

