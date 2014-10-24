
//#include GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
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
#include <unordered_map>
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
#define INF 1000000000
#define gcd __gcd
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
using namespace std;

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

#ifdef GRAPH
#include "drawGraph.cpp"
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }

}dbg;

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

// inline void inputString(string &s)
// {
//     char ch=getchar_unlocked();
//     s="";
//     while(ch!='\n')
//         s+=ch, ch=getchar_unlocked();
// }


typedef struct{
	int operator()(const pair<int,int> &k) const{
		return (k.first*100000+k.second)%MOD;
	}
}myHash;



string s1,s2;
lld len1, len2,a,b,k;
typedef unordered_map<pair<lld,lld>, lld, myHash> MyMap;
MyMap mp, cost_map;
vector<lld> arrX;
vector<lld> arrY;

inline lld actualK(){
	return k/a+1;
}



inline void mapInsert(MyMap &m, pair<lld,lld> p, lld value){
	m.insert(make_pair(p,value));
}

inline lld numbering(){
	lld ma,mi,i,j,index=1, t= actualK();
	arrX.pb(-1);
	arrY.pb(-1);
	for(i=1;i<=len1;i++){
		ma = max((lld)1,i-t);
		mi = min(i+t,len2);
		for(j=ma;j<=mi;j++){
			arrX.pb(i);
			arrY.pb(j);
			mapInsert(mp,make_pair(i,j),index);
			index++;
		}
	}
	return index;
}

inline void init(){
	mp.clear();
	cost_map.clear();
	arrX.clear();
	arrY.clear();
	lld i, t = actualK();
	for(i=0;i<=t;i++)mapInsert(cost_map, make_pair(i,0), i*a);
	for(i=0;i<=t;i++)mapInsert(cost_map, make_pair(0,i), i*a);
}

inline lld cost(lld x, lld y){
	pair<lld, lld> p = make_pair(x,y);
	lld val;
	if(cost_map.find(p)!=cost_map.end())val = cost_map[p];   //present
	else if(a) val = (lld)INF;	
	else val = 0;
	return val;
}

inline pair<lld,lld> calculate_cost(lld index){
	lld i,x,y,l_cost,u_cost,m_cost;
	pair<lld,lld> ins,pop;
	for(i=1;i<index;i++){

		x = arrX[i]; y = arrY[i];
		l_cost = cost(x,y-1)+a;
		u_cost = cost(x-1,y)+a;
		m_cost = cost(x-1,y-1)+b*(s1[x-1]!=s2[y-1]);
		mapInsert(cost_map, make_pair(x,y), min(l_cost, min(u_cost, m_cost)));
		//debug(x,y,l_cost,u_cost,m_cost,cost_map[make_pair(x,y)], s1[x-1], s2[y-1]);
	}
	return make_pair(arrX[index-1],arrY[index-1]);
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
	 //std::ios_base::sync_with_stdio (false);
	 lld t;
	 inputInt(t);
	 
	 while(t--){
		 inputString(s1);
		 inputString(s2);
		 //cin>>s1>>s2;
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
		 if(a==0){
			 printf("0\n");
			 continue;
		 }
		 if(k==0 || (len2-len1)*a>k){
			 printf("-1\n");
			 continue;
		 }
		 printf("%lld\n",solve());
	 }
}

