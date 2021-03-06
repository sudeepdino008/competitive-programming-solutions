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
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;


inline void inputInt(int &n )
{
	n=0;
 	int ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

inline void push_min(int n, deque<int> &dq_min, queue<int> &q)
{
	while(dq_min.size() && dq_min.back()>n)
		dq_min.pop_back();
	dq_min.push_back(n);
	q.push(n);
}

inline void pop_max(deque<int> &dq_max, queue<int> &q)
{
	int val=q.front();
	q.pop();
	if(val==dq_max.front())
		dq_max.pop_front();
}


inline void push_max(int n,deque<int> &dq_max, queue<int> &q)
{
	while(dq_max.size() && dq_max.back()<n)
		dq_max.pop_back();
	dq_max.push_back(n);
	q.push(n);
}

inline void pop_min(deque<int>& dq_min, queue<int>& q)
{
	int val=q.front();
	q.pop();
	if(val==dq_min.front())
		dq_min.pop_front();
}

int main()
{
	deque<int> dq_max,dq_min;
	queue<int> q;

	int n,w,i,count=0;
	inputInt(n);
	inputInt(w);
	int height[n+1];
	int max_elem[n-w+2], min_elem[n-w+2];
	
	for(i=1;i<=n;i++)
   		inputInt(height[i]);

	for(i=1;i<=w;i++)
		push_min(height[i], dq_min, q), push_max(height[i], dq_max, q);
	
	max_elem[1]=dq_max.front();
	min_elem[1]=dq_min.front();
	for(i=w+1;i<=n;i++)
	{
		push_min(height[i], dq_min, q);
		push_max(height[i], dq_max, q);
		pop_max(dq_max, q);
		pop_min(dq_min, q);
		if(max_elem[i-w]-min_elem[i-w]+1==w)
			count++;
		max_elem[i-w+1]=dq_max.front();
		min_elem[i-w+1]=dq_min.front();
	}
	if(max_elem[n-w+1]-min_elem[n-w+1]+1==w)
			count++;

	printf("%d\n", count);
	
}
