
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
#define tr(c,i) for(typeof(c.begin()) i = (c).begin(); i != (c).end(); i++) 
#define pb push_back
#define lld long long int
#define SIZE 4000001
#define PRECISION 0.000001
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
	int sign=1;
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
		 n*=sign;
	// while( ch < '0' || ch > '9')
   //    ch=getchar_unlocked();
	// while(  ch >= '0' && ch <= '9' )
	// 	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}

bool ifEqual(double a, double b){
	return abs(a-b)<PRECISION;
}

typedef struct p{
	double x,y;
	p(){
		x = 0;
		y = 0;
	}
	p(double a, double b){
		x = a;
		y = b;
	}
}point;
vector<vector<point> > vec(SIZE);
vector<point> input;
lld answer=2;
//square of sq_distance
inline double sq_distance(const point &a, const point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool operator==(point a, point b){
	if(ifEqual(a.x,b.x) && ifEqual(a.y,b.y))return true;
	return false;
}

//returns point perpendicuar to line p1p2 and at a distance d=dis(p1,p2) with one side of the line p1p2 (depends on sign)
point check(const point &p1, const point &p2, lld sign){
	double dis = sqrt(sq_distance(p1,p2));
	if(ifEqual(p1.x,p2.x))return p(p1.x+dis*sign, p1.y);
	if(ifEqual(p1.y,p2.y))return p(p1.x, p1.y+dis*sign);
	//debug("jkakakakka",p1.x,p1.y,p2.x,p2.y);
	double m,cdash,c,x_test1, y_test1;
	m = (p2.y-p1.y)/(p2.x-p1.x);
	cdash = p1.x/m+p1.y;
	c = (p1.y*p2.x-p1.x*p2.y)/(p2.x-p1.x);

	x_test1 =  (sign*dis*m*sqrt(1+m*m)+m*(cdash-c))/(1+m*m);
	y_test1 = cdash-x_test1/m;
	
	// if(p1==point(2,2) && p2==point(4,1))
	//debug("qqqqqqqqqqqqqq",m,cdash,c,dis,x_test1, y_test1, sign,x_test1,x_test1);
//	debug("tetete",x_test1, y_test1);

	return point(x_test1,y_test1);
	// debug("point p1",p1.x, p1.y);
	// debug("point p2",p2.x, p2.y);
	// debug("result",x_test1,y_test1);

}

bool if_present(point &pn){
	lld dis = (lld)(sqrt(sq_distance(point(0,0),pn))+0.5);
	//if(dis>=(lld)vec.size())return false;
	tr(vec[dis],it){
		if((*it)==pn)return true;
	}
	return false;
}

void solve(point &p1, point &p2, lld sign){
	point pt1 = check(p1, p2, sign), pt2;
	double d1,d2;
//	debug("yesh!",pt1.x,pt1.y, p1.x, p1.y, p2.x, p2.y,sign);
	if(if_present(pt1)){
		answer=1;
		// debug("point p1",p1.x, p1.y);
		// debug("point p2",p2.x, p2.y);
		// debug("result",pt1.x,pt1.y);

		pt2 = check(pt1, p1,1);
		d1 = sq_distance(pt2,pt1);
		d2 = sq_distance(pt2,p2);
		if(if_present(pt2) && ifEqual(d1,d2))goto mast;
		pt2 = check(pt1, p1, -1);
		if(if_present(pt2) && ifEqual(d1,d2))goto mast;
	}
	return ;
mast:
	printf("0\n");
	exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,x,y,i,count,j,index;
	 inputInt(n);
	 point origin(0,0);
	 for(i=1;i<=n;i++){
		 inputInt(x);
		 inputInt(y);
		 point p(x,y);
		 input.pb(p);
		 index = (lld)(sqrt(sq_distance(p,origin))+0.5);
		 //debug(index);
		 vec[index].pb(p);
	 }
	 if(n<=2){
		 printf("%lld\n",4-n);
		 exit(0);
	 }
	 count = 0;
	 point pin1,pin2, pt1, pt2;
	 for(i=0;i<n;i++){
		 for(j=i+1;j<n;j++){
			 solve(input[i], input[j], 1);
			 solve(input[i], input[j], -1);
			 solve(input[j], input[i], 1);
		 }
	 }
	 printf("%lld\n",answer);
}
