

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


template<class T>
string int_to_string(T n)
{
	stringstream ss;
	string s;
	ss<<n;
	ss>>s;
	return s;
}


template<class T>
void makeDotFile(const vector<vector<T> > adj, const long long int &V, bool directed=true, bool weighted=true)  //for matrix representation
{
	ofstream dotFile;
	dotFile.open("dotGraph.dot",ios::trunc | ios::out);

	//provisions for directed or undirected graph
	if(directed)                       
		dotFile<<"digraph G{\n";
	else 
		dotFile<<"digraph G{\n edge[dir=none]\n";

	long long int i,j;
	for(i=1;i<=V;i++)
	{
		string edge=int_to_string(i)+"->";
		for(j=1;j<=V;j++)
		{
			if(weighted && adj[i][j])
				dotFile<<edge<<int_to_string(j)<<"[label=\""<<int_to_string(adj[i][j])<<"\"];\n";
			else if(adj[i][j])
				dotFile<<edge<<int_to_string(j)<<";\n";
		}
	}

	dotFile<<"}";
	dotFile.close();
}

template<class T>
void makeDotFile(const vector<T> *adj, const long long int &V, bool directed=true)      //for adjacency list representation
{
	ofstream dotFile;
	dotFile.open("dotGraph.dot",ios::trunc | ios::out);

	if(directed)
		dotFile<<"digraph G{\n";
	else 
		dotFile<<"digraph G{\n edge[dir=none]\n";

	long long int i;
	for(i=1;i<=V;i++)
	{
		string edge=int_to_string(i)+"->";
		for(typeof(adj[i].begin()) it=adj[i].begin();it!=adj[i].end();it++)
			dotFile<<edge<<int_to_string(*it)<<";\n";
	}

	dotFile<<"}";
	dotFile.close();
}
