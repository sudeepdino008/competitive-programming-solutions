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
#define MOD 1000000007
using namespace std;


//using heuristics by weight and path compression to improve running time
typedef struct n{
	struct n *parent;
	int u,v,weight;
	int rank;        //if node is the parent, it keeps track of number of children. if not, it is -1.
}node;

node* MAKE(int u, int v, int weight)
{
	node *n=(node*)malloc(sizeof(node));
	n->parent=n;
	n->u=u;
	n->v=v;
	n->weight=weight;
	n->rank=0;
	return n;
}

node *FIND(node *n)
{
	if(n->parent==n)
		return n;
	n->parent=FIND(n->parent);
	return n->parent;
}

void MERGE(node *n1, node *n2)     //merge n1 and n2 and store in n1.
{
	assert(n1->rank!=-1);
	assert(n2->rank!=-1);
	if(n1->rank<n2->rank)
	{
		MERGE(n2,n1);
		return ;
	}
	n2->parent=n1;
	n1->rank=n1->rank+n2->rank+1;
	n2->rank=-1;
}

int main()
{
	node *n1=MAKE(1,2,100);
	node *n2=MAKE(2,3,300);
	node *n3=MAKE(4,5,600);
	node *n4=MAKE(1,5,500);
	MERGE(n1,n2);
	MERGE(n3,n4);
	MERGE(n1,n3);
	node *n5=FIND(n4);
	cout<<n1->weight<<" "<<n1->parent->weight<<endl;
	cout<<n2->weight<<" "<<n2->parent->weight<<endl;
	cout<<n3->weight<<" "<<n3->parent->weight<<endl;
	cout<<n4->weight<<" "<<n4->parent->weight<<endl;
}
