

#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
//#define GRAPH
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
#define fd(i,a) for(i=1;i<=a;i++)
#define fa(i,a,b) for(i=a;i<=b;i++)
#define fs(i,a,b,c) for(i=a;i<=b;i+=c)
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define INDEX(arr,elem)        (lower_bound(all(arr),elem)-arr.begin())
#define lld long long int
#define MOD 1000000007
#define gcd __gcd
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
#define INF INT_MIN
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

typedef struct p{
	lld x, y, cost;
	p(lld _x, lld _y, lld _cost): x(_x), y(_y), cost(_cost) {}
	p(): x(0), y(0), cost(0) {}
}Obj;

lld n,m,dp[21][21][257],startx,starty, cTre = 0, cObj = 0;
//bool visited[21][21][257];
Obj object[10]; 
char table[22][22];
lld dx[]={1,-1,0,0}, dy[]={0,0,1,-1};


lld bfs(){
	queue<Obj> nodes;
	lld x,y,mask,k,xx,yy,i,m2,ans=0;
	nodes.push(Obj(startx, starty, 0));
	clr(dp,-1);
	dp[startx][starty][0]=0;
	while(!nodes.empty()){
		x = nodes.front().x;
		y = nodes.front().y;
		mask = nodes.front().cost; nodes.pop();
		for(k=0;k<4;k++){
			xx = x+dx[k]; yy = y+dy[k];
			m2 = mask;
			if(!(xx>=1 && xx<=n && yy>=1 && yy<=m && (table[xx][yy]=='.' || table[xx][yy]=='S')))continue;
			for(i=0;i<cObj;i++)
				if(object[i].x<xx && object[i].y>=min(yy,y) && object[i].y<max(y,yy))m2^=(1<<i);
			if(dp[xx][yy][m2]==-1){
				dp[xx][yy][m2] = dp[x][y][mask]+1;
				nodes.push(Obj(xx,yy,m2));
			}
		}
	}
	lld limit = 1<<cObj;
	for(i=0;i<limit;i++){
		m2 = -dp[startx][starty][i];
		if(m2!=1){
			for(k=0;k<cObj;k++)
				m2 += object[k].cost*((i>>k)&1);
			ans = max(ans, m2);
		}
	}
	return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld i, j;
	 scanf("%lld %lld",&n, &m);
	 for(i=1;i<=n;i++)scanf("%s",table[i]+1);

	 for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(table[i][j]=='S')startx=i, starty=j;

	 for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			 if('1'<=table[i][j] && table[i][j]<='9')
				 object[table[i][j]-'1'] = Obj(i,j,0), cTre++;
		 }
	 cObj = cTre;
	 for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			 if(table[i][j]=='B')
				 object[cObj++] = Obj(i,j,-INF);
		 }
	 for(i=0;i<cTre;i++)scanf("%lld",&object[i].cost);
	 printf("%lld\n",bfs());
}

