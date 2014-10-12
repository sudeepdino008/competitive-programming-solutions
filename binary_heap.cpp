//implemeting max heaps

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
using namespace std;

class binaryHeap         //indexing from 1
{
private:
	vector<int> h;
	int size;
	inline int parent(int);
	inline int left_child(int);
	inline int right_child(int);
	void heapify(int);
public:
	binaryHeap();
	binaryHeap(int *array, const int &size);     //construct a heap from array
	void insert(int const&);    
	void delete_elem();
	int root() const;
	void print_binaryHeap();
};

binaryHeap::binaryHeap()
{
	size=0;
	h.push_back(-1);
}

inline int binaryHeap::parent(int i)
{
	return (i/2);
}

inline int binaryHeap::left_child(int i)
{
	return (2*i);
}

inline int binaryHeap::right_child(int i)
{
	return (2*i+1);
}

void binaryHeap::heapify(int index)
{
	int smallest=index, left=left_child(index), right=right_child(index);
	if(left<=size && h[smallest]<h[left])
		smallest=left;
	if(right<=size && h[smallest]<h[right])
		smallest=right;
	if(smallest!=index)
	{
		swap(h[smallest], h[index]);
		heapify(smallest);
	}
}

binaryHeap::binaryHeap(int *array, const int &size)
{
	int i;
	h.push_back(-1);     //garbage value to be pushed
	this->size=size;
	for(i=0;i<size;i++)
		h.push_back(array[i]);
	for(i=size/2;i>=1;i--)
		heapify(i);
	
}

void binaryHeap::insert(int const &n)
{
	size++;
	int i=size;
	h.push_back(n);
	while(parent(i)!=0 && h[i]>h[parent(i)])
	{
		swap(h[i],h[parent(i)]);
		i=parent(i);
	}
}

int binaryHeap::root() const
{
	return h[1];
}

void binaryHeap::delete_elem()
{
	if(size==0)
	{
		cout<<"cannot delete\n";
		return;
	}
	h[1]=h[size--];
	int smallest=1,left=left_child(smallest),right=right_child(smallest);
	while((left<=size && h[smallest]<h[left]) || (right<=size && h[smallest]<h[right]))
	{
		if(h[left]>h[right])
		{
			swap(h[left],h[smallest]);
			smallest=left;
		}
		else
		{
			swap(h[right],h[smallest]);
			smallest=right;
		}
		left=left_child(smallest);
		right=right_child(smallest);
	}
}

void binaryHeap::print_binaryHeap()
{
	cout<<"printing binary heap:\n";
	for(int i=1;i<=size;i++)
		cout<<h[i]<<" ";
	cout<<endl<<endl;
}

int main()
{
	int arr[]={1,3,5,6,7,8,9};
	binaryHeap b(arr,7);
	b.print_binaryHeap();
	b.delete_elem();
	b.print_binaryHeap();
}
