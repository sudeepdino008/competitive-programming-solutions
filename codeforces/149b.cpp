
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

bool check(string &s, int base,bool hour)
{
	int len=s.length(),i,val=0;
	for(i=0;i<len;i++)
	{
		int ch=s[i];
		if(ch>='A' && ch<='Z')
			ch=10+ch-'A';
		else
			ch=ch-'0';

		val=ch+val*base;
		//debug(ch, val, base);
		if(ch>=base || (val>=24 && hour) || (val>=60 && !hour))
			return false;
	}
	return true;
}

int main()
{
	string inp,first="", second="";
	cin>>inp;
	int len=inp.length(),i,maax=-1;
	bool inf=true;
	for(i=0;i<len && inp[i]!=':';i++)
	{
		int ch=inp[i];
		if(ch>='A' && ch<='Z')
			ch=10+ch-'A';
		else
			ch=ch-'0';
		if(maax<ch)
			maax=ch;

		first=first+inp[i];
		if(inp[i+1]!=':' && inp[i]!='0')
			inf=false;
	}
	i++;
	for(;i<len;i++)
	{
		int ch=inp[i];
		if(ch>='A' && ch<='Z')
			ch=10+ch-'A';
		else
			ch=ch-'0';
		if(maax<ch)
			maax=ch;

		second+=inp[i];
		if(i!=len-1 && inp[i]!='0')
			inf=false;
	}
	if(inf && first[first.length()-1]<'O')
	{
		cout<<"-1\n";
		return 0;
	}
	else if(inf)
	{
		cout<<"0\n";
		return 0;
	}
	
	vector<int> pos;
	inf=true;
	//cout<<"sssssssss "<<maax<<endl;
	for(i=maax+1;(check(first, i, true) && check(second,i,false));i++)
	{
		cout<<i<<" ";
		inf=false;
	}
	if(inf)
		cout<<"0\n";
	
	
	
}
