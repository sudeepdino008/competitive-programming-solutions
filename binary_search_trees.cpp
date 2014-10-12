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
#define insent(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;

typedef struct n{
	struct n *left, *right;
	int data;
}node;

class binarySearchTree
{
private:
	node *root;
	void inorder(node*);
public:
	binarySearchTree();
	binarySearchTree(int n);
	void insert(int n);
	void delete_elem(int n);
	void print_tree_inorder();
};

binarySearchTree::binarySearchTree()
{
	root=NULL;
}

binarySearchTree::binarySearchTree(int n)
{
	root=NULL;
	insert(n);
} 

void binarySearchTree::insert(int n)
{
	node *ins_n=new node;
	ins_n->data=n;
	ins_n->left=ins_n->right=NULL;
	if(root==NULL)
	{
		root=ins_n;
		return ;
	} 
	node *parent,*temp=root;
	parent=NULL;
	while(temp!=NULL)
	{
		parent=temp;
		if(temp->data>n)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(parent->data>n)
		parent->left=ins_n;
	else
		parent->right=ins_n;
}

void binarySearchTree::print_tree_inorder()
{
	cout<<"\nprinting tree in inorder:\n";
	inorder(root);
	cout<<"\ntree printed!!\n\n";
}

void binarySearchTree::inorder(node *insert)
{
	if(insert==NULL)
		return;

	inorder(insert->left);
	cout<<insert->data<<" ";
	inorder(insert->right);
}

void binarySearchTree::delete_elem(int n)
{
	bool found=false;
	if(root==NULL)
	{
		cout<<"tree is empty.\n cannot delete.\n";
		return;
	}
	//see if element is insent in tree
	node *curr,*parent;
	curr=root;
	parent=NULL;
	while(curr!=NULL)
	{
		if(curr->data==n)
		{
			found=true;
			break;
		}
		parent=curr;
		if(curr->data>n)
			curr=curr->left;
		else
			curr=curr->right;
	}
	if(!found)
	{
		cout<<"element not found.\n";
		return;
	}
	//element has been found....3 cases, deal with them!
	if(curr->left==NULL && curr->right==NULL)               //no children
	{
		if(parent->left==curr)
			parent->left=NULL;
		else
			parent->right=NULL;
		delete(curr);
	}
	else if(curr->left==NULL)                             //only right child
	{
		if(parent->left==curr)
			parent->left=curr->right;
		else
			parent->right=curr->right;
		delete(curr);
	}
	else if(curr->right==NULL)                             //only left child
	{
		if(parent->left==curr)
			parent->left=curr->left;
		else
			parent->right=curr->left;
		delete(curr);
	}
	else
	{
		node *temp,*temp_parent;
		temp=curr->left;
		temp_parent=curr;
		while(temp->right!=NULL)
		{
			temp_parent=temp;
			temp=temp->right;
		}
		if(parent!=NULL)
			temp_parent->right=temp->left;
		else
		{
			curr->left=temp;
			temp->right=curr->right;
			temp->left=NULL;
			return;
			delete(curr);
		}
		if(parent->left==curr)
			parent->left=temp;
		else 
			parent->right=temp;
		temp->right=curr->right;
		temp->left=curr->left;
		delete(curr);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	binarySearchTree b(50);
	int i,k;
	for(i=0;i<2;i++)
	{
		k=rand()%100;
		cout<<k<<" ";
		b.insert(k);
	}
	b.print_tree_inorder();
	b.delete_elem(50);
	b.print_tree_inorder();
}
