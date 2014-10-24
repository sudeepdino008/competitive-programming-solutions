
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
#define possible(i,j) ((i)>=1 && (j)>=1 && (i)<=r && (j)<=c)
#define equals(a,b) (a.compareTo(b)==0)    //for strings only
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


lld matrix[21][21];      // 0 for vacant cell, 1 for wall, 2 for monster
bool  dp[21][21][21][21];
lld r,c;

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

void input_matrix()
{
	lld i,j;
	char ch;
	for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++)
				matrix[i][j]=0;
		}
	for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				matrix[i][j]=(getchar_unlocked()=='^')?0:1;
			ch=getchar_unlocked();
		}
}

void populate_monsters()
{
	lld i,j;
	for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				{
					if(possible(i-1,j) && possible(i-2,j) && possible(i+1,j) && possible(i+2,j) && possible(i,j-1) && possible(i,j-2) && possible(i,j+1) && possible(i,j+2))
						{

							if(!(matrix[i-1][j]==1 || matrix[i-2][j]==1 || matrix[i+1][j]==1 || matrix[i+2][j]==1 || matrix[i][j-1]==1 || matrix[i][j-2]==1 || matrix[i][j+1]==1 || matrix[i][j+2]==1 || matrix[i][j]==1))
								matrix[i][j]=2;
						}
				}
		}
	//delete walls, no use now.
	for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				matrix[i][j]=(matrix[i][j]==1)?0:matrix[i][j];
		}
}

void init()
{
	lld i,j,k,l;
	for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++)
				{
					for(k=1;k<=20;k++)
						{
							for(l=1;l<=20;l++)
								dp[i][j][k][l]=false;
						}
				}
		}
	for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++)
				dp[j][j][i][i]=(matrix[i][j]==2);
		}
	for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++)
				{
					if(matrix[i][j]==2)
						{
							for(k=1;k<=20;k++)
								{
									for(l=k+1;l<=20;l++)
										{
											if(j>=k && j<=l)
												dp[k][l][i][i]=true;
											if(i>=k && i<=l)
												dp[j][j][k][l]=true;
										}
								}
						}
				}
		}
}


bool find_monsters_of_cell(lld i, lld j, lld k, lld p)
{
	lld q,w;
	for(q=i;q<=j;q++)
		{
			for(w=k;w<=p;w++)
				{
					if(matrix[w][q]==2)
						return true;
				}
		}
	return false;
}


void find_monsters_of_cell(lld i, lld j, lld k, lld p, vector<pair<lld,lld> > &monsters)
{
	lld q,w;
	monsters.clear();
	for(q=i;q<=j;q++)
		{
			for(w=k;w<=p;w++)
				{
					if(matrix[w][q]==2)
						monsters.push_back(make_pair(w,q));
				}
		}
}

bool calculate_winner()
{
	lld delta,i,j,k,p,x0,y0,count_2;
	vector<pair<lld,lld> > monsters;
	//debug("shaks ",dp[4][4][3][3]);
	for(delta=2;delta<=20;delta++)
		{
			for(i=1;i+delta<=21;i++)
				{
					j=i+delta-1;
					for(k=1;k+delta<=21;k++)
						{
							p=k+delta-1;
							find_monsters_of_cell(i,j,k,p,monsters);
							tr(monsters,it)
								{
									x0=it->first;
									y0=it->second;
									count_2 = (y0!=i && x0!=k && dp[i][y0-1][k][x0-1])+(y0!=j && x0!=k && dp[y0+1][j][k][x0-1])+(y0!=i && x0!=p && dp[i][y0-1][x0+1][p])+(y0!=j && x0!=p && dp[y0+1][j][x0+1][p]);
									if(i==3 && j==5 && k==3 && p==5)
										debug("monsters",x0,y0,i,j,k,p,count_2, dp[y0+1][j][k][x0-1],dp[y0+1][j][k][x0-1]);
									count_2=1-(count_2%2);
									// if(i==3 && j==4 && k==3 && p==4)
									// 	debug(count_2,x0,y0, dp[i][j][k][p]);
									dp[i][j][k][p] = dp[i][j][k][p] || count_2;
									if(dp[i][j][k][p])
										break;
								}
							if(dp[i][j][k][p])
								debug("(",i,",",j,")"," (",k,",",p,")",delta,dp[i][j][k][p]);
						}
				}
		}
	return dp[1][max(r,c)][1][max(r,c)];
}

int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
#endif
	lld t,i,j;
	inputInt(t);
	while(t--)
		{
			inputInt(r);
			inputInt(c);
			input_matrix();
			populate_monsters();
				// 		for(i=1;i<=r;i++)
				// {
				// 	for(j=1;j<=c;j++)
				// 		cout<<matrix[i][j]<<" ";
				// 	cout<<endl;
				// }
			// cout<<endl<<endl;
			init();
			if(calculate_winner())printf("Asuna\n");
			else printf("Kirito\n");
	 
		}
}

