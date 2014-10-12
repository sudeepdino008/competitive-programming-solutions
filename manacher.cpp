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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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


/*
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking


string preProcess(string s) {
	int n = s.length();
	if (n == 0) return "^$";
	string ret = "^";
	for (int i = 0; i < n; i++)
		ret += " " + s.substr(i,1);
	ret += " $";
	return ret;
}
 
string longestPalindrome(string s) 
{	
	string T = preProcess(s);
	int n = T.length();
	int *P = new int[n];
	int C = 0, R = 0;
	for (int i = 1; i < n-1; i++)
	{
		int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
		P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
		debug(P[i],i,i_mirror, C);
		// Attempt to expand palindrome centered at i
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
 
		// If palindrome centered at i expand past R,
		// adjust center based on expanded palindrome.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}
 
	// Find the maximum element in P.
	int maxLen = 0;
	int centerIndex = 0;
	for (int i = 1; i < n-1; i++) {
		cout<<"pp "<<i<<" "<<P[i]<<endl;
		if (P[i] > maxLen) {
			maxLen = P[i];
			centerIndex = i;
		}
	}
	delete[] P;
  
	return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

*/

string preCompute(const string &s)
{
	string result="^";
	int len=s.length();
	if(len==0)
		return "^$";
	for(int i=0;i<len;i++)
		result=result+" "+s.substr(i,1);
	result=result+" $";
	return result;
}

int manacher(const string &s)      //return number of palindrome excluding those of length 1.
{
	string result=preCompute(s);
	int len=result.length();
	int R=0,C=0,i,sum=0;
	int arr[len],i_mirror;
	for(i=1;i<len-1;i++)
	{
		i_mirror=2*C-i;
		arr[i]=(R>i)?min(R-i,arr[i_mirror]):0;
		
		while(result[i+arr[i]+1]==result[i-arr[i]-1])
			arr[i]++;
		sum+=arr[i]/2;
		if(i+arr[i]>R)
		{
			C=i;
			R=i+arr[i];
		}
	}
	return sum;
}


int main()
{
	cout<<manacher("a")<<endl;
	cout<<manacher("babcbabcbaccbc")<<endl;
	cout<<manacher("aaaa")<<endl;
	cout<<manacher("aabaa")<<endl;
	cout<<manacher("ababa")<<endl;
	cout<<manacher("ababab")<<endl;
}


