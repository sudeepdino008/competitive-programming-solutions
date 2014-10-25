#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
//#define GRAPH
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

typedef struct s{
	struct s *parent;
	lld val, rank;
}node;

node *makeSet(lld n){
	node *nod = (node*)malloc(sizeof(node));
	nod->parent = nod;
	nod->val = n;
	nod->rank = 0;
	return nod;
}

node *findSet(node *x){
	if(x->parent!=x)x->parent = findSet(x->parent); //path compression
	return x->parent;
}

void link(node *x1, node *x2){  //using union by rank heuristic
	if(x1->rank>x2->rank){
		x2->parent = x1;
	}
	else{
		x1->parent = x2;
		if(x1->rank==x2->rank)x2->rank++;  
	}
}

void merge(node *x1, node *x2){    //link set pointed by node x2 to x1 and delete x2
	link(findSet(x1), findSet(x2));
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 node *n1 = makeSet(1), *n2=makeSet(2), *n3=makeSet(3), *n4=makeSet(4), *n5=makeSet(5);
	 debug(n1->val, n3->val, n5->val);
	 assert(n3->val==3);
	 merge(n1,n2);  //n2 gone
	 debug(findSet(n1)->val, n2->val);
	 merge(n4,n5);
	 debug(findSet(n5)->val, n5->val);
	 merge(n1, n4);
	 debug(findSet(n1)->val, findSet(n2)->val, findSet(n3)->val, findSet(n4)->val, findSet(n5)->val);
	 
}


