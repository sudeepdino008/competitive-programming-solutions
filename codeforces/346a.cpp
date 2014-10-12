
#define DEBUG       //comment when you have to disable all debug macros.
#define NDEBUG    //comment when all assert statements have to be disabled.
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
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;


#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }

}dbg;



int main()
{
	int n,a,count=0,i,j;
	cin>>n;
	bool arr[101]={false};
	set<int> s,z;
	for(i=1;i<=n;i++)
		cin>>a, s.insert(a), z.insert(a);
	for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
	{
		for(set<int>::iterator it1=s.begin(); it1!=s.end(); it1++)
		{
			if(*it1!=*it)
			{
				if(z.find(abs(*it1-*it))==z.end())
					count++, z.insert(abs(*it1-*it));
			}
		}
	}
	



	//debug(count);
	n=n%2;count=count%2;
	if(!(n && count) || (n && !count))
		cout<<"Bob\n";
	else
		cout<<"Alice\n";
}
