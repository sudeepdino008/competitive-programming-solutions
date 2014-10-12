
//#define GRAPH
//#define DEBUG       //comment when you have to disable all debug macros.
#define LOCAL     //uncomment for testing from local file
#define NDEBUG    //comment when all assert statements have to be enabled.
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

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
#endif
	 lld n,p,i;
	 string str;
	 bool flag=false;
	 cin>>n>>p;
	 cin>>str;
	 lld arr[n], j,k;
	 for(i=0;i<n;i++)arr[i] = str[i]-'a'+1;
	 
	 for(i=n-1;i>=0;i--){
		 set<lld> left, right;
		 if(i>=1)left.insert(arr[i-1]);
		 if(i>=2)left.insert(arr[i-2]);
		 if(i<=n-2)right.insert(arr[i+1]);
		 if(i<=n-3)right.insert(arr[i+2]);
		 
		 for(j=arr[i]+1;j<=p;j++){
			 if(!present(left,j) && !present(right,j)){
				 str[i] = j+'a'-1;
				 arr[i] = j;
				 flag=true;
				 break;
			 }
		 }
		 if(flag)break;
		 for(j=arr[i]+1;j<=p;j++){
			 if(!present(left,j)){
				 str[i] = j+'a'-1;
				 arr[i] = j;
				 break;
			 }
		 }
		 
		 if(j!=p+1){
			 
			 left.clear();
			 right.clear();
			 if(i+1>=1)left.insert(arr[i]);
			 if(i+1>=2)left.insert(arr[i-1]);
			 debug("string",str);
			 for(j=i+1;j<n;j++){
				 debug("hey",i,j);
				 for(k=1;k<=p;k++){
					 if(!present(left,k)){
						 str[j] = k+'a'-1;
						 arr[j] = k;
						 debug("debug",j,str);
						 break;
					 }
				 }
				 debug(i,j);
				 if(j>=2)left.erase(arr[j-2]);
				 left.insert(arr[j]);
			 }
			 flag=true;
			 break;
		 }
		 
		 
	 }
	 if(flag)cout<<str<<endl;
	 else cout<<"NO"<<endl;
}

