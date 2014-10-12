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
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <utility> //std::pair
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;



class Tries{                      //assuming only small lettered english alphabets
private:
	typedef struct n{
		struct n *child[26];
		int prefix_count;          
		int word_count;
	}node;
	node *root;
	void map_value();
public:
	Tries();
	void insert_word(const string &s);
	int word_count(const string &s);
	int prefix_count(const string &s);
};

Tries::Tries()
{
	root=new node;
	for(int i=0;i<26;i++)
		root->child[i]=NULL;
	root->prefix_count=root->word_count=0;
}

void Tries::insert_word(const string &s)
{
	node *present=root;
	int i, size=s.length();
	int p;
	for(i=0;i<size;i++)
	{
		p=s[i]-'a';
		if(present->child[p]==NULL)
		{
			present->child[p]=new node;
			present->child[p]->prefix_count=present->child[p]->word_count=0;
		}
		present->prefix_count++;
		present=present->child[p];
	}
	present->word_count++;
	//present->prefix_count;          //if the whole word itself counts as a prefix
}

int Tries::word_count(const string& s)
{
	node *present=root;
	int i, size=s.length(),p;
	for(i=0;i<size;i++)
	{
		p=s[i]-'a';
		if(present->child[p]==NULL)
			return 0;
		present=present->child[p];
	}
	return present->word_count;
}

int Tries::prefix_count(const string& s)
{
	node *present=root;
	int i, size=s.length(),p;
	for(i=0;i<size;i++)
	{
		p=s[i]-'a';
		if(present->child[p]==NULL)
			return 0;
		present=present->child[p];
	}
	return present->prefix_count;
}

int main()
{
	Tries val;
	val.insert_word("tree");
	val.insert_word("trie");
	val.insert_word("algo");
	val.insert_word("assoc");
	val.insert_word("all");
	val.insert_word("also");
	val.insert_word("algo");
	cout<<val.word_count("algo")<<" "<<val.prefix_count("tr")<<" "<<val.prefix_count("we")<<endl;
}
