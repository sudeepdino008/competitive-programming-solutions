#include <iostream>
#include<cstdio>
#include<cstring>
#include<set>

using namespace std;

set<int> total;
set<int> next, now;
int main()
{
	int i, j, a, b, n;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		next.clear();
		total.insert(a);
		for(set<int>:: iterator it = now.begin(); it != now.end(); it++)
		{
			int b = *it | a;
			total.insert(b);
			next.insert(b);
		}
		next.insert(a);
		now = next;
		cout<<"eee "<<total.size()<<endl;
	}
	printf("%d\n", total.size());
	return 0;
}
