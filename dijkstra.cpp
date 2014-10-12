/*Two data structures required, a min-heap and a graph data structure(linked list). The algorithm runs in O(|E|+|V|log|V|) time */
/*indexing from 1*/

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


/*key used in 2 ways- for the minHeap class, the key gives the minimum distance involved in travelling till node index. Whereas for Graph class, adj[u][v] gives the weight of edge u,v*/
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
	bool isEmpty();
};

minHeap::minHeap(node *array, int size)
{
	int i;
	node n;
	n.key=n.index=-1;
	h.push_back(n);
	for(i=1;i<=size;i++)
	{
		h.push_back(array[i]);
		m[array[i].index]=i;

	}
	this->size=size;
	for(i=size/2;i>=1;i--)
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
	return 2*i;
}

inline int minHeap::right_child(int i)
{
	return (2*i+1);
}

inline int minHeap::parent(int i)
{
	return i/2;
}

void minHeap::insert(node n)
{
	this->size++;
	h[this->size]=n;
	int i=this->size;
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
	swap_node(1,size);
	heapify(1);
}

node minHeap::top()
{
	return h[1];	
}

void minHeap::print_binaryHeap()
{
	cout<<"\nprinting heap:\n";
	for(int i=1;i<=size;i++)
		cout<<h[i].index<<" "<<h[i].key<<endl;
}

void minHeap::decreaseKey(int index, int key)
{
	int i=m[index];
	h[i].key=key;
	while(i>=1 && h[i].key<h[parent(i)].key)
	{
		swap_node(i,parent(i));
		i=parent(i);
	}
}

bool minHeap::isEmpty()
{
	if(size)
		return false;
	else
		return true;
}



class Graph          //undirected graphs, change addEdge function for directed graphs
{
private:
	int V;    //number of edges
	vector<node> *adj;    //pointer to array of vectors for storing in adjacency list format
	void find_vertice(int u, int v, vector<node>::iterator &it);
public:
	Graph(int V);
	void addEdge(int u, int v,int weight,bool directed); //join u to v
	void printDFS(int u); //prints tree with origin u using the DFS algorithm
	void DFS(int i,bool *visited);
	void deleteEdge(int u, int v);
	void dijkstra(int start);
	bool isEmpty();
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new vector<node>[V+1];
}

void Graph::find_vertice(int u, int v, vector<node>::iterator &it)
{

	while(it!=adj[u].end())
	{
		if((*it).index==v)
			return;
	}
}

void Graph::deleteEdge(int u, int v)       //generic function for both directed and undirected
{
	vector<node>::iterator it;
	this->find_vertice(u,v,it);
	int uv=0;           //0->not present, 1-> uv present, 2-> uv and vu present
	if(it!=adj[v].end())
	{
		this->adj[u].erase(it);
		uv=1;
	}
		
	this->find_vertice(v,u,it);
	if(it!=adj[v].end())
	{
		this->adj[v].erase(it);
		uv=2;
	}
	if(uv==0)
		cout<<"no such edge\n";

}

void Graph::addEdge(int u, int v,int weight,bool directed)
{
	node n;
	n.index=v;
	n.key=weight;
	adj[u].push_back(n);
	if(!directed)
	{
		n.index=u;
		adj[v].push_back(n);     //for undirected graph
	}
}

void Graph::DFS(int u, bool *visited)
{
	stack<int> nodes;
	nodes.push(u);
	bool present = true;     //if the last node has produced another node or not. 
	while(!nodes.empty())
	{
		present=false;
		int k=nodes.top();
		for(vector<node>::iterator it=adj[k].begin(); it!=adj[k].end();it++)
		{
			if(!visited[(*it).index])
			{
				present=true;
				nodes.push((*it).index);
				visited[(*it).index]=true;
			}
		}
		if(!present)
		{
			cout<<nodes.top()<<" ";
			nodes.pop();
		}
	}
}

void Graph::printDFS(int u)
{
	bool visited[V+1], done=false;
	int i;
	memset(visited, false, sizeof visited);
	
	for(i=1;i<=V;i++)
	{
		if(!visited[i])
		{
			visited[i]=true;
			DFS(i, visited);
		}
	}
	
	
}

void Graph::dijkstra(int start)
{
	long long int distance[V+1],i;
	node array[V+1];
	for(i=1;i<=V;i++)
		distance[i]=INT_MAX;
	distance[start]=0;
	long long int temp;
	for(i=1;i<=V;i++)
	{
		array[i].key=distance[i];
		array[i].index=i;
	}
	minHeap mh(array,V);
    //bool visited[V+1];
	//memset(visited, false, sizeof visited);
	while(!mh.isEmpty())
	{
		node n=mh.top();
		mh.delete_top();
		if(n.key==INT_MAX)
			break;            //remaining nodes are inaccessible from the given start node
		for(vector<node>::iterator it=adj[n.index].begin();it!=adj[n.index].end();it++)
		{
			temp=distance[n.index]+(*it).key;
			if(distance[(*it).index]>temp)
			{
				distance[(*it).index]=temp;
				mh.decreaseKey((*it).index, temp);
			}
		}
	}
	cout<<"distances from "<<start<<endl;
	for(i=1;i<=V;i++)
		cout<<distance[i]<<endl;
	
}


int main()
{
	Graph g(8);
	g.addEdge(4,1,3,false);
	g.addEdge(4,2,4,false);
	g.addEdge(5,2,100,false);
	g.addEdge(4,3,2,false);
	g.addEdge(6,4,5,false);
	g.addEdge(6,5,11,false);
	g.addEdge(7,4,50,false);
	g.addEdge(8,5,1,false);
	g.addEdge(8,3,7,false);
	Graph g1(g);
	g1.printDFS(1);

	cout<<"\n\n";
	g1.dijkstra(1);
}
