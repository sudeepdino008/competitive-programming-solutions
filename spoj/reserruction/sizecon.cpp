#include <iostream>
using namespace std;
main(){
	int t,n,s=0;
	cin>>t;
	while(t--)cin>>n,s+=max(n,0);
	cout<<s;
}
