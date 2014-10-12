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
#include <cstdarg>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define lld long long int
using namespace std;

lld merge(lld array[], lld s, lld mid, lld e)
{
	if(s>=e)
		return 0;
	lld i=1,j=mid+1,k=s, count=0;
	lld temp[e-s+1];
	while(j<=e && k<=mid)
	{
		if(array[k]<=array[j])
			temp[i++]=array[k++];
		else
		{
			temp[i++]=array[j++];
			count+=mid-k+1;
		}
	}
	while(k<=mid)
		temp[i++]=array[k++];
	while(j<=e)
		temp[i++]=array[j++];

	
	for(i=s;i<=e;i++)
		array[i]=temp[i-s+1];
	return count;
}

lld count_inversion( lld array[], lld  s, lld e)
{
	if(e<=s)
		return 0;
	lld mid=(s+e)/2;
	return count_inversion(array,s,mid)+count_inversion(array, mid+1,e)+merge(array,s,mid,e);
}

int main()
{
	lld n,b,count=0,i;
	cin>>n;
	lld array[n+1];
	for(i=1;i<=n;i++)
		cin>>array[i];
	n=count_inversion(array, 1,n);
	cout<<n;
	return 0;
}
