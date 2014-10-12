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

int binary_search(int lowest[], int size, int target)      //return max j such that lowest[j]<=target
{
   
	int start,end, mid;
	if(lowest[0]>target)
		return -1;
	for(start=0, end=size, mid=(start+end)/2;end-start>1;mid=(end+start)/2)
		((lowest[mid]>target)?end:start)=mid;
	
	return mid;
}

int longest_increasing_subsequence(int array[], int size)
{
	
}

int main()
{
	int lowest[]={90,100};
	cout<<binary_search(lowest,sizeof(lowest)/sizeof(int),50)<<endl;
}
