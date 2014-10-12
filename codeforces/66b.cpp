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
#include <unordered_map>
#include <unordered_set>
#include <sys/time.h>
#include <iomanip>
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

int main()
{
	lld n;
	cin>>n;
	lld a[n],left=1, right=0,i,j,max;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		if(a[i]>=a[i-1])
			left++;
		else break;
	}
	max=left+right;
	for(;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			right++;
			for(j=i+1;j<n;j++)
			{
				if(a[j]<=a[j-1])
					right++;
				else
					break;
			}
			i=j-1;
		}
		else if(a[i]>a[i-1])
		{
			left=right+1;
			right=0;
			for(j=i+1;j<n;j++)
			{
				if(a[j]>=a[j-1])
					right++;
				else break;
			}
			i=j-1;
		}
	
		if(max<left+right)
			max=left+right;
	}
	cout<<max<<endl;
}
