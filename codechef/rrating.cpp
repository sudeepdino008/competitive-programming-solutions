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
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;

inline void inputInt(lld &n )
{
	n=0;
 	lld ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
	lld n,size=0,x,x1,x2;
	inputInt(n);
	priority_queue<lld, vector<lld>, less<lld>> h1;
	priority_queue<lld, vector<lld>, greater<lld>> h2;          //the actual review heap(min heap)
	while(n--)
	{
		inputInt(x);
		if(x==1)
		{
			inputInt(x);
			size++;
			h1.push(x);
			
			if(size/3>h2.size())
			{
				//cout<<"s"<<h1.top()<<endl;
				h2.push(h1.top());
				h1.pop();
				while(h2.size()>0 && h2.top()<h1.top())
				{
					x1=h1.top();h1.pop();
					x2=h2.top();h2.pop();
					h1.push(x2);
					h2.push(x1);
				}
			}
			
		
		
		}
		else if(size>=3)
		{
			while(h2.size()>0 && h2.top()<h1.top())
			{
				x1=h1.top();h1.pop();
				x2=h2.top();h2.pop();
				h1.push(x2);
				h2.push(x1);
			}
			printf("%lld\n", h2.top());
		}
		else
			printf("No reviews yet\n");
	}
}
