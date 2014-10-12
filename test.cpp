
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
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
#include <functional>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>
using namespace std;


typedef struct{
		int u, v, weight;
	}edge;


class comparator{
public:
	bool operator()(const edge &e1, const edge &e2)
		{
			if(e1.weight<e2.weight)
				return true;
		}
};


void print_queue(priority_queue<edge, vector<edge> ,comparator> q)
{
	while(!q.empty())
		cout<<q.top().weight<<" ", q.pop();
	cout<<endl<<endl;
}

int main()
{

	priority_queue<edge, vector<edge> , comparator> q;
	edge e1={1,2,10};
	edge e2={1,3,23};
	edge e3={1,4,4};
	edge e4={1,5,99};
	edge e5={1,6,43};
	edge e6={1,7,29};

	q.push(e1);
	q.push(e2);
	q.push(e3);
	print_queue(q);
	q.push(e4);
	q.push(e5);
	q.push(e6);
	print_queue(q);
}

