//segment tree data structure without lazy propagation for finding max in an interval



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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
#define SIZE 100
using namespace std;

int tree[2*SIZE+2];



int query(int node, int b, int e, int i, int j)
{
	
	if(i<=b && e<=j)
		return tree[node];
	if(j<b || e<i)
		return 0;
	int mid=(b+e)>>1,L=node<<1, R=L+1;
	return tree[node]=query(L,b,mid,i,j)+query(R,mid+1,e,i,j);
}

void update_segment_tree(int node, int b, int e, int x,int val)
{
	if(b==e && b==x)
	{
		tree[node]=val;
		return ;
	}
	if(x<b || e<x)
		return;
	int mid=(b+e)>>1, L=node<<1, R=L+1;
	update_segment_tree(L,b,mid,x,val);
	update_segment_tree(R,mid+1,e,x,val);
	tree[node]=tree[L]+tree[R];
}


void build(int node,int b, int e, int* arr)
{
	if(b==e)
	{
		tree[node]=arr[b];
		return ;
	}
	int mid=(b+e)>>1,L=node<<1, R=L+1;
	build(L,b,mid,arr);
	build(R,mid+1,e,arr);
	tree[node]=tree[L]+tree[R];
}


int main()
{
	int arr[]={4,5,6,1,3,9};
	build(1,0,5,arr);
	update_segment_tree(1,0,5,3,6);
	cout<<query(1,0,5,2,5)<<endl;
}
