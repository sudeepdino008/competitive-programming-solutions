//#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be disabled.
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
#define lld long long int
#define INF 1000000000
using namespace std;

template<class T>
inline void inputInt(T &n )
{
	n=0;

 	T ch=getchar_unlocked();
	/*int sign=1;
	  while(( ch < '0' || ch > '9') && ch!='-')
	  ch=getchar_unlocked();
	  if(ch=='-')
	  {
	  sign=-1;
	  ch=getchar_unlocked();
	  }
	  while(  ch >= '0' && ch <= '9' )
	  n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	  n*=sign;*/
	while( ch < '0' || ch > '9')
      ch=getchar_unlocked();
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

inline void inputString(string &s)
{
	char ch=getchar_unlocked();
	while(ch<'a' || ch >'z')ch=getchar_unlocked();
	s="";
	while(ch>='a' && ch<='z')
		s+=ch, ch=getchar_unlocked();
}

string s1,s2;
lld len1, len2,a,b,k;
typedef map<pair<lld,lld>, lld> MyMap;
MyMap mp, cost_map;
pair<lld,lld> arr[20100001];


lld numbering(){
	lld ma,mi,i,j,index=1;
	for(i=1;i<=len1;i++){
		ma = max((lld)1,i-k);
		mi = min(i+k,len2);
		for(j=ma;j<=mi;j++){
			arr[index] = make_pair(i,j);
			mp.insert(MyMap::value_type(make_pair(i,j), index));
			index++;
		}
	}
	return index;
}

void init(){
	mp.clear();
	cost_map.clear();
	lld i;
	for(i=0;i<=k;i++)cost_map[make_pair(i,0)] = i*a;
	for(i=0;i<=k;i++)cost_map[make_pair(0,i)] = i*a;
}

lld cost(lld x, lld y){
	pair<lld, lld> p = make_pair(x,y);
	lld val;
	if(cost_map.find(p)!=cost_map.end())val = cost_map[p];   //present
	else if(a) val = (lld)INF;	
	else val = 0;
	return val;
}

pair<lld,lld> calculate_cost(lld index){
	lld i,x,y,l_cost,u_cost,m_cost;
	pair<lld,lld> ins,pop;
	for(i=1;i<index;i++){
		ins = arr[i];
		x = ins.first; y = ins.second;
		l_cost = cost(x,y-1)+a;
		u_cost = cost(x-1,y)+a;
		m_cost = cost(x-1,y-1)+b*(s1[x-1]!=s2[y-1]);
		cost_map[make_pair(x,y)] = min(l_cost, min(u_cost, m_cost));
		//debug(x,y,l_cost,u_cost,m_cost,cost_map[make_pair(x,y)], s1[x-1], s2[y-1]);
	}
	return arr[index-1];
}

lld solve(){
	lld index,total_cost;
	init();
	index = numbering();
	pair<lld,lld> ans = calculate_cost(index);
	lld x = ans.first, y = ans.second;
	total_cost = cost(x,y)+a*(len2-y);
	//debug("sssss",x,y,total_cost,len2,k,cost(x,y),a);
	if(total_cost<=k)return total_cost;
	else return -1;
}

int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	//cin.sync_with_stdio(false);
	lld t;
	inputInt(t);
//	s1.reserve(100001);
//	s2.reserve(100001);
	while(t--){
		cin>>s1>>s2;
		inputInt(a);
	inputInt(b);
	inputInt(k);
	len1 = s1.length();
	len2 = s2.length();
	if(len2<len1)
	{
	swap(len1,len2);
	swap(s1,s2);
}
	if(a==0)printf("0\n");
	else if(b==0 && len1==len2)printf("0\n");
	else if(k==0)printf("-1\n");
	else printf("%lld\n",solve());
}
}
