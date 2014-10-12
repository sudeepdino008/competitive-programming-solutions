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
#define BASE 10
#define PRIME 104729
#define PSIZE 2
#define TSIZE 100
using namespace std;

int exponentiation(int n)
{
	if(n==0)
		return 1;
	int v=exponentiation(n/2);
	if(n%2==1)
		return (((v*v)%PRIME)*BASE)%PRIME;
	else
		return (v*v)%PRIME;
}

void rabin_karp(string text, string pattern)
{
	int tlen=text.length(), plen=pattern.length(),i,thash=0,phash=0,bm;
	if(tlen<plen)
		return ;
	for(i=0;i<plen;i++)
		phash=(phash*10+pattern[i])%PRIME;
	for(i=0;i<plen;i++)
		thash=(thash*10+text[i])%PRIME;
	bm=exponentiation(plen-1);
	for(i=0;i+plen<tlen;i++)
	{
		if(phash==thash)
			cout<<"at "<<i<<endl;
		thash=thash-(text[i]*bm);
		thash=thash*BASE;
		thash=(thash+text[i+plen]+PRIME)%PRIME;
	}
	if(thash==phash)
		cout<<"at "<<i<<endl;
	cout<<endl;
}

string int_to_string(int n)
{
	stringstream ss;
	ss<<n;
	return ss.str();
}

int main()
{
	srand((unsigned int)time(NULL));
	string pattern="", text="";
	int i;
	for(i=0;i<PSIZE;i++)
		pattern+=int_to_string(rand()%10);
	for(i=0;i<TSIZE;i++)
		text+=int_to_string(rand()%10);
	cout<<endl<<"text: "<<text<<endl;
	cout<<endl<<"pattern: "<<pattern<<endl;
	rabin_karp(text, pattern);
}
