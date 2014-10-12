
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
	lld freqR;
	lld freqL;
	lld bestF;
	lld L,R;
}node;

node tree[1<<18];
lld arr[100001];


void build_tree(lld n, lld i, lld j){
	if(i==j){
		tree[n].L = tree[n].R = arr[i];
		tree[n].bestF = tree[n].freqL = tree[n].freqR = 1;
		return;
	}
	build_tree(2*n, i, (i+j+1)/2-1);
	build_tree(2*n+1, (i+j+1)/2, j);
	node present = tree[n], leftC = tree[2*n], rightC = tree[2*n+1];
	
	present.freqR = rightC.freqR + ((rightC.L==rightC.R && leftC.R==rightC.L)?(leftC.freqR):0);
	present.freqL = leftC.freqL + ((leftC.L==leftC.R && leftC.R==rightC.L)?(rightC.freqL):0);
	present.L = leftC.L;
	present.R = rightC.R;
	present.bestF = max(leftC.bestF, max(rightC.bestF, (leftC.R==rightC.L)?(leftC.freqR+rightC.freqL):LLONG_MIN));
	tree[n] = present;
}

node query(lld n, lld i, lld j, lld x, lld y){
	if(j<x || y<i || x>y || i>y){
		node t;
		t.L = LLONG_MIN;
		return t;
	}
	if(x==i && j==y)
		return tree[n];

	lld m = (i+j+1)/2-1;
	
	node leftC, rightC;
	leftC = query(2*n, i, m, x, min(y,m));
	rightC = query(2*n+1, m+1, j, max(x,m+1) , y);

	if(leftC.L==LLONG_MIN)return rightC;
	if(rightC.L==LLONG_MIN)return leftC;

	node present = tree[n];
	
	present.freqR = rightC.freqR + ((rightC.L==rightC.R && leftC.R==rightC.L)?(leftC.freqR):0);
	present.freqL = leftC.freqL + ((leftC.L==leftC.R && leftC.R==rightC.L)?(rightC.freqL):0);
	present.L = leftC.L;
	present.R = rightC.R;
	present.bestF = max(leftC.bestF, max(rightC.bestF, (leftC.R==rightC.L)?(leftC.freqR+rightC.freqL):LLONG_MIN));
	return present;
}

int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld i,n,q,a,b;
	inputInt(n);
	while(n){
		inputInt(q);
		for(i=1;i<=n;i++)inputInt(arr[i]);
		build_tree(1,1,n);

		while(q--){
			inputInt(a);
			inputInt(b);
			printf("%lld\n",query(1,1,n,a,b).bestF);
		}
		inputInt(n);
	}
}

