#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define lld long long int
using namespace std;


template<class T>
inline void inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

int main()
{
	lld n,t;
	inputInt(t);
	while(t--)
	{
		inputInt(n);
		if(n%49==0 && n%343!=0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
