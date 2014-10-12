#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <sys/time.h>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;


template <class T>
class Stack
{
private:
	typedef struct S{
		struct S *parent;
		T data;
	}S;
	S *top_elem;
public:
	bool isEmpty() const;
	void push(const T&);
	void pop();
	T top() const;
};

template <class T>
bool Stack<T>::isEmpty() const
{
	if(this->top_elem==NULL)
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::push(const T& elem)
{
	if(this->top_elem==NULL)
	{
		this->top_elem=(S*)malloc(sizeof(S));
		this->top_elem->data=elem;
		this->top_elem->parent=NULL;
		return;
	}
	S *newTop=(S*)malloc(sizeof(S));
	newTop->data=elem;
	newTop->parent=this->top_elem;
	this->top_elem=newTop;
}

template <class T>
void Stack<T>::pop()
{
	if(isEmpty())
	{
		cout<<"can't pop. Stack empty.\n";        //need to throw an exception here
		return ;
	}
	S *temp=this->top_elem->parent;
	free(this->top_elem);
	this->top_elem=temp;
}

template <class T>
T Stack<T>::top() const
{
	if(isEmpty())
	{
		cout<<"no top.\n";            //need to throw an exception here
		return -1;
	}
	return this->top_elem->data;
}

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(0);
	s.push(10);
	while(!s.isEmpty())
		cout<<s.top()<<" ", s.pop();
}
