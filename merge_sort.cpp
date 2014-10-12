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


void merge(int *array, int start, int end)
{
	int pivot=(start+end)/2, i;
	int left[pivot-start+1],right[end-pivot], l_ind=0, r_ind=0;
	for(i=start; i<=pivot;i++)
		left[i-start]=array[i];
	for(i=pivot+1;i<=end;i++)
		right[i-pivot-1]=array[i];
	for(i=start;i<=end;i++)
	{
		if((l_ind<(pivot-start+1) && r_ind<(end-pivot) && left[l_ind]<=right[r_ind]) || (r_ind==end-pivot))
			array[i]=left[l_ind++];
		else 		
			array[i]=right[r_ind++];
	}
	
}

void merge_sort(int *array,int start, int end)
{
	if(start>=end)
		return;
	int pivot=(start+end)/2;
	merge_sort(array,start,pivot);
	merge_sort(array,pivot+1,end);
	merge(array,start,end);
}

int main()
{
	int array[]={4,3,90,0,100,17,5,900},size=sizeof(array)/sizeof(int);
	merge_sort(array,0,size-1);
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
}
