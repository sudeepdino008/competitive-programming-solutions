
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


template<class T>
inline void inputInt(T &n )
{
	n=0;
 	T ch=getchar_unlocked();
  	while( ch < '0' || ch > '9' )
      ch=getchar_unlocked();
   	while(  ch >= '0' && ch <= '9' )
       n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}


typedef struct s{
	struct s *left, *right;
	int balance;                //num_right-num_left
	int data;
}node;

node *root;
map<node*,node*> parent; //keeps a record of parent;


void insert(node *n)
{
	
}


void left_rotate(node *n)   //upper node
{
	node *p=parent[n];
	
	
}

int main()
{
	node *root=new root;
	parent[root]=root;
	int size=0,d;

	cin>>s;
	while(strcmp(s,"END")!=0)
	{
		if(strcmp(s,"MEDIAN")!=0)
		{
			cin>>d;
			if(size==0)
			{
				root->left=root->right=NULL;
				root->data=d;
				root->balance=0;
			}
			else
				insert(root,d);
			size++;
		}
		else
		{
			if(size%2!=0)
				printf("%d\n",root->data);
			else  if(root->balance==-1)
				printf("%d\n",(root->data+root->left->data)/2);
			else
				printf("%d\n",(root->data+root->right->data)/2);
		}
		
	}


}
