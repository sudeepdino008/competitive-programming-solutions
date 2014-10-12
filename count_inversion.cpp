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

int merge(int arr[], int s, int mid, int e)
{
	int i=s, j=mid+1, k=0, temp[e-s+1], count=0;
	while(i<=mid && j<=e)
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
		{
			count+=(mid+1-i);
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=e)
		temp[k++]=arr[j++];
	for(j=s;j<=e;j++)
		arr[j]=temp[j-s];
	return count;
}

int count_inversion(int arr[], int s, int e)
{
	if(s>=e)
		return 0;
	int mid=(s+e)/2;
	return count_inversion(arr,s,mid)+count_inversion(arr,mid+1,e)+merge(arr,s,mid,e);
}

int main()
{
	int arr[]={5,4,3,2,1};
	cout<<count_inversion(arr,0,4)<<endl;
}
