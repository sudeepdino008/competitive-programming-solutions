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
#define lld long long int
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
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


class binaryHeap         //indexing from 1
{
private:
	vector<lld> h;
	lld size;
	inline lld parent(lld);
	inline lld left_child(lld);
	inline lld right_child(lld);
	void heapify(lld);
public:
	binaryHeap();
	binaryHeap(lld *array, const lld &size);     //construct a heap from array
	void insert(lld const&);    
	void delete_elem();
	lld root() const;
	void print_binaryHeap();
};

binaryHeap::binaryHeap()
{

}

inline lld binaryHeap::parent(lld i)
{
	return (i/2);
}

inline lld binaryHeap::left_child(lld i)
{
	return (2*i);
}

inline lld binaryHeap::right_child(lld i)
{
	return (2*i+1);
}

void binaryHeap::heapify(lld index)
{
	lld smallest=index, left=left_child(index), right=right_child(index);
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

binaryHeap::binaryHeap(lld *array, const lld &size)
{
	lld i;
	h.push_back(-1);     //garbage value to be pushed
	this->size=size;
	for(i=0;i<size;i++)
		h.push_back(array[i]);
	for(i=size/2;i>=1;i--)
		heapify(i);
	
}

void binaryHeap::insert(lld const &n)
{
	size++;
	lld i=size;
	h.push_back(n);
	while(h[i]>h[parent(i)])
	{
		swap(h[i],h[parent(i)]);
		i=parent(i);
	}
}

lld binaryHeap::root() const
{
	if(size==0)
		return 0;
	return h[1];
}

void binaryHeap::delete_elem()
{
	if(size==0)
		return;
	h[1]=h[size--];
	lld smallest=1,left=left_child(smallest),right=right_child(smallest);
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
	cout<<"prllding binary heap:\n";
	for(lld i=1;i<=size;i++)
		cout<<h[i]<<" ";
	cout<<endl<<endl;
}


int main()
{
	lld t,c,n,m,i,j,sum;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		inputInt(m);
		lld P[m];
		for(i=0;i<m;i++)
			inputInt(P[i]);
		binaryHeap lemonade[n];
		for(i=0;i<n;i++)
		{
			inputInt(c);
			lld A[c];
			for(j=0;j<c;j++)
				inputInt(A[j]);
			binaryHeap b(A,c);
			lemonade[i]=b;
		}
		sum=0;
		for(i=0;i<m;i++)
		{
			sum+=lemonade[P[i]].root();
			lemonade[P[i]].delete_elem();
		}
		printf("%lld\n",sum);
	}
}
