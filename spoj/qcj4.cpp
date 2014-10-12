
//#include GRAPH
#define DEBUG       //comment when you have to disable all debug macros.
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
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define INDEX(arr,elem)        (lower_bound(all(arr),elem)-arr.begin())
#define lld long long int
#define MOD 1000000007
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

typedef struct{
	double x, y;
}point;

typedef struct{
	double sq_radius;
	point centre;
}circle;

typedef struct{
	double a, b, c;
}LINE;               //equation of line ax+by=c

point *plane;


template<class T>
inline void inputInt(T &n )
{
	n=0;
	int sign=1;
 	T ch=getchar_unlocked();
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
}

inline double distance(const point &p1, const point &p2)
{
	return pow(p1.x-p2.x, 2)+pow(p1.y-p2.y,2);
}

inline point midPoint(const point &p1, const point &p2)
{
	point p;
	p.x = (p1.x+p2.x)/2.0;
	p.y = (p1.y+p2.y)/2.0;
	return p;
}

/*all the straight LINE related functions*/

LINE makeLine(const point &p1, const point &p2)
{
	LINE line;
	line.a = p2.y - p1.y;
	line.b = p1.x - p2.x;
	line.c = p1.x*(p2.y-p1.y) + p1.y*(p1.x-p2.x);
	return line;
}

LINE perpendicularBisector(const LINE &line, const point &p)  //line passing through p and perpendicular to line
{
	LINE pb;
	pb.a = -1*line.b;
	pb.b = line.a;
	pb.c = pb.b*p.y + pb.a*p.x;
	return pb;
}

point intersection(const LINE &line1, const LINE &line2)
{
	double d = line2.a*line1.b - line1.a*line2.b;  //denominator of intersection
	point p;
	p.x = ((line2.c*line1.b-line1.c*line2.b)/d);
	p.y = ((line1.c*line2.a-line2.c*line1.a)/d);
	return p;
}
/*END: all the straight LINE related functions*/


circle CIRCLE(const point &p1, const point &p2, const point &p3)   //return circle with p1, p2 and p3  as points on circumference
{
	/* the intersection of any 2 perpendicular bisectors of line joining a pair of given points give the centre. given the centre, radius can be found*/
	CIRCLE c;
	LINE line1 = makeLine(p1,p2);
	LINE line2 = makeLine(p2,p3);
	line1 = perpendicularBisector(line1, midPoint(p1,p2));
	line1 = perpendicularBisector(line1, midPoint(p1,p2));
	c.centre = intersection(line1, line2);
	c.radius = distance(c.centre, p1);
	return c;
}

bool notInCircle(const circle &c, point p)
{
	if(distance(p, c.centre)<=c.sq_radius)
		return false;
	else
		return true;
}

circle MEC2(point p1, point p2, lld start, lld k)
{
	circle c = CIRCLE(p1,p2);
	lld i;
	for(i=start;i<=k;i++)
	{
		if(notInCircle(c,plane[i]))
			c = CIRCLE(p1,p2,plane[i]);
	}
	return c;
}

circle MEC1(point p, lld start, lld j)
{
	circle c = CIRCLE(p,plane[start]);
	lld i;
	for(i=start+1;i<=j;i++)
	{
		if(notInCircle(c, plane[i]))
			c = MEC2(p, plane[i], start, i);
	}
	return c;
}

double MEC(lld start, lld end)
{
	if(start==end)
		return 0;
	lld i;
	circle c = CIRCLE(plane[start], plane[start+1]);
	for(i=start+2;i<=end;i++)
	{
		if(notInCircle(c, plane[i]))
			c = MEC1(plane[i], start, i);
	}
	return sqrt(4*c.sq_radius);
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 srand(time(NULL));
	 lld n,i;
	 inputInt(n);
	 plane = (point*)malloc(sizeof(point)*n);
	 for(i=0;i<n;i++)
	 {
		 scanf("%f %f", d1,d2);
		 plane[i].x = d1;
		 plane[i].y = d2;
	 }
	 for(i=0;i<n;i++)
		 swap(plane[i], plane[rand()%n]);
	 printf("%f\n",MEC(0,n-1));
}

