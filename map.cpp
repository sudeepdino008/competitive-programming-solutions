#include <iostream>
#include <utility>
#include <unordered_map>
//#include <unordered_map>
#include <map>
using namespace std;


// struct KeyEqual {
// 	bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) const
//  {
//     return lhs.first == rhs.first && lhs.second == rhs.second;
//  }
// };


// typedef unordered_map<pair<int, int> ,int> MyMap;

// void mapInsert(MyMap &m, pair<int,int> &p, int value){
// 	m.insert(MyMap::value_type(p, value));
// }

// int main(){
// 	MyMap mp;
// 	mapInsert(mp,make_pair(1,1),2);
// 	mapInsert(mp,make_pair(2,2),8);
// 	//mp.insert(MyMap::value_type
// 	cout<<mp[make_pair(1,1)]<<endl;

// }

typedef struct{
	int operator()(const pair<int,int> &k) const{
		return (k.first*k.second);
	}
}myHash;

typedef pair<int,int> my_key_type;
typedef unordered_map<my_key_type, int, myHash> my_map_type;



my_map_type m;

int main(){
	m.insert(make_pair(make_pair(2,2), 2));
	m.insert(make_pair(make_pair(2,4), 3));
	//if(m.find(make_pair(2,2))!=m.end())cout<<"woopie\n";
	if(m.find(make_pair(1,4))!=m.end())cout<<"no woopie\n";
	cout<<m[make_pair(2,2)]<<endl;
	cout<<m[make_pair(1,4)]<<endl;
}
