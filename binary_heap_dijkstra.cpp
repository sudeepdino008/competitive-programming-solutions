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

typedef struct{
	int key;
	int index;
}node;

class minHeap
{
private:
	vector<node> h;
	map<int,int> m;                      //this will map the "index" of node to the index in the vector h
	int size;
	void heapify(int);
	void swap_node(int,int);                        //(swap h[i] and h[j])+update the map
	inline int left_child(int);
	inline int right_child(int);
	inline int parent(int);
public:
	minHeap(node *array, int size);
	void insert(node);
	void delete_top();
	node top();
	void print_binaryHeap();
	void decreaseKey(int index,int key);           //note that h[map[index]]>key...it is "decrease"Key
};

minHeap::minHeap(node *array, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		h.push_back(array[i]);
		m[array[i].index]=i;
	}
	this->size=size;
	for(i=size/2;i>=0;i--)
		heapify(i);
}

void minHeap::heapify(int i)
{
	int left=left_child(i),right=right_child(i),smallest=i;
	if(left<size && h[left].key<h[i].key)
		smallest=left;
	if(right<size && h[right].key<h[smallest].key)
		smallest=right;
	if(smallest!=i)
	{
		swap_node(smallest,i);
		heapify(smallest);
	}
}

void minHeap::swap_node(int i, int j)
{
	swap(m[h[i].index],m[h[j].index]);
	swap(h[i],h[j]);
}

inline int minHeap::left_child(int i)
{
	return (2*i+1);
}

inline int minHeap::right_child(int i)
{
	return (2*i+2);
}

inline int minHeap::parent(int i)
{
	return (i-1)/2;
}

void minHeap::insert(node n)
{
	this->size++;
	h[this->size-1]=n;
	int i=this->size-1;
	while(i>=0 && h[i].key<h[parent(i)].key)
	{
		swap_node(i,parent(i));
		i=parent(i);
	}
}

void minHeap::delete_top()
{
	if(size==0)
	{
		cout<<"cannot delete, heap empty\n";
		return;
	}
	size--;
	swap_node(0,size);
	heapify(0);
}

node minHeap::top()
{
	return h[0];
}

void minHeap::print_binaryHeap()
{
	cout<<"\nprinting heap:\n";
	for(int i=0;i<size;i++)
		cout<<h[i].index<<" "<<h[i].key<<endl;
}

void minHeap::decreaseKey(int index, int key)
{
	int i=m[index];
	h[i].key=key;
	while(i>=0 && h[i].key<h[parent(i)].key)
	{
		swap_node(i,parent(i));
		i=parent(i);
	}
}

int main()
{
	node array[11];
	array[0].key=100;
	array[0].index=1;

	array[1].key=19;
	array[1].index=3;

	array[2].key=36;
	array[2].index=5;

	array[3].key=17;
	array[3].index=7;

	array[4].key=3;
	array[4].index=9;

	array[5].key=25;
	array[5].index=8;
	
	array[6].key=1;
	array[6].index=6;

	array[7].key=2;
	array[7].index=4;

	array[8].key=7;
	array[8].index=2;
	
	array[9].key=78;
	array[9].index=10;
	
	array[10].key=190;
	array[10].index=11;

	minHeap m(array,11);
	m.print_binaryHeap();
	cout<<endl<<endl;
	node n;
	n.key=64;
	n.index=12;
	m.insert(n);
	m.print_binaryHeap();
	n=m.top();
	cout<<n.key<<" "<<n.index<<endl;
	m.delete_top();

	m.decreaseKey(10,0);
		m.print_binaryHeap();
}
