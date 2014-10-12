#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <ctime>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define lld long long int
#define MOD 1000000007
#define SIZE 10
using namespace std;

int array[SIZE];

void quick_sort(int start, int end)
{
    if(start<end)
	{
		int pivot=SIZE%(end-start)+start;
		int p=end+1,i;
	  	swap(array[start], array[pivot]);
		for(i=start+1;i<=end;i++)
		{
			if(array[i]<=array[start] && p!=end+1)
				swap(array[i], array[p++]);
			else if(array[i]>array[start] && p==end+1)
			    p=i;
		}
	
		swap(array[p-1],array[start]);
		quick_sort(start, p-1);
		quick_sort(p, end);
	}
}

int main()
{
	srand((unsigned int)(time(NULL)));
	int i;
	for(i=0;i<SIZE;i++)
		array[i]=rand()%100;
	cout<<"initial array:\n";
	for(i=0;i<SIZE;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	quick_sort(0,SIZE-1);
	cout<<"\n\nsorted array:\n";
	for(i=0;i<SIZE;i++)
		cout<<array[i]<<" ";
	cout<<endl;
}
