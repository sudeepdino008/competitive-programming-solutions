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

inline void inputInt(lld &n )
{
	n=0;
 	lld ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

string seq;
int length;

bool possible(int len, int last)
{
	lld prev, next, i,p,k=len,j;
	for(i=last;i>=0;i--)
	{
		prev=0;
		p=1;
		for(j=i;j>=i-len+1;j--)
		{
			prev=prev+(seq[j]-'0')*p;
			p*=10;
		}
		cout<<"s"<<prev<<endl;
		if(i==last)
			next=prev;
		else if((prev+1)!=next)
			return false;
			
		
		
		i=j+1;
		if(prev==p)
			len--;
			
	}
	//well done sequence....now face the final music!
	if(last==length-1)         //backward check...need to forward check as well
		return true;  
	prev=0;
	p=1;
	for(j=length-1;j>=last+1;j--)
		prev=prev+(seq[j]-'0')*p, p*=10;
	next=0;
	p=1;
	for(j=last;j>=last-len+1;j--)
		next=next+(seq[j]-'0')*p, p*=10;

	p=1;
	for(j=1;j<=length-last-1;j++)
		p*=10;
	cout<<"ssssssss "<<prev<<" "<<next<<" "<<p<<endl;
	if(prev==(next/p+1))
		return true;
	else
		return false;
}

int main()
{
	lld t, q,c,i,j,k;
	bool sahi;
	inputInt(t);
	while(t--)
	{
		seq="";
		length=0;
		c=getchar_unlocked();
		while(c>='0' && c<='9')
			seq+=c, c=getchar_unlocked();
		length=seq.length();
		sahi=false;
		k=min(length,9);
		for(i=1;i<=k;i++)
		{
			for(j=0;j<i;j++)
			{
				if(possible(i,length-j-1))      //1st argument tells length of subsequence,2nd one tells the last position from where it has to start.
				{
					sahi=true;
					break;
				}
			}
			if(sahi)
				break;
		}
		if(sahi)
			printf("YES\n");
		else
			printf("NO\n");

	}

}
