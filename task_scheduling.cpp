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
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <sys/time.h>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
#define SWAP_TASK(i,j) std::swap(t[(i)].start, t[(j)].start);std::swap(t[(i)].end, t[(j)].end);std::swap(t[(i)].weight, t[(j)].weight);
#define NTASK 10

typedef struct task{
	int start, end, weight;
}task;

task t[NTASK];

void quick_sort(int s, int e)
{
	if(s>=e)
		return;
	int pivot=rand()%(e-s)+s, i, p=-1;
	SWAP_TASK(s, pivot);
	for(i=s+1;i<e;i++)
	{
		if(t[i].end<=t[s].end && p!=-1)
		{
			SWAP_TASK(i,p);
			p++;
		}
		else if(t[i].end>t[s].end && p==-1)
			p=i;
	}
	if(p==-1)
	{
		SWAP_TASK(s,e-1);
		quick_sort(s,e-1);
		return;
	}
	SWAP_TASK(p-1,s);
	quick_sort(s,p-1);
	quick_sort(p,e);	
}

void task_scheduling()
{
	int M[NTASK],i,j;
	int P[NTASK];
	P[0]=-1;
	for(i=1;i<NTASK;i++)
	{
		P[i]=-1;
		for(j=i-1;j>=0;j--)
		{
			if(t[j].end<=t[i].start)
			{
				P[i]=j;
				break;
			}
		}
	}
	M[0]=t[0].weight;
	for(i=1;i<NTASK;i++)
		M[i]=std::max(M[i-1],((P[i]!=-1)?M[P[i]]:0)+t[i].weight);
	std::cout<<"Maximum weight:"<<M[NTASK-1]<<"\n";
	for(i=NTASK-1;i!=-1;)
	{
		int t1=((P[i]!=-1)?M[P[i]]:0)+t[i].weight;
		if(t1>M[i-1])
		{
			std::cout<<"("<<t[i].start<<","<<t[i].end<<","<<t[i].weight<<")\n";
			i=P[i];
		}
		else
			i--;
	}
	
}

int main()
{
	srand((unsigned int)time(NULL));

	int i;
	for(i=0;i<NTASK;i++)
	{
		t[i].start=rand()%10;
		t[i].end=rand()%10;
		if(t[i].start>t[i].end)
			std::swap(t[i].start, t[i].end);
		t[i].weight=rand()%10;
	}
	std::cout<<"tasks:\n";
	for(i=0;i<NTASK;i++)
		std::cout<<"("<<t[i].start<<","<<t[i].end<<","<<t[i].weight<<")\n";
	std::cout<<"\n";
	quick_sort(0,NTASK);
	task_scheduling();
}
