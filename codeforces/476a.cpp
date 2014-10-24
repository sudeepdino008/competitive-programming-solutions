#include <iostream>
using namespace std;

int main(){
    int n,m,x,y,k;
    cin>>n>>m;
    for(k=1;k<=n/m;k++){
        x = n-k*m;
        y = 2*k*m-n;
        //  cout<<x<<" "<<y<<" "<<(2*x+y)<<endl;
        if(x>=0 && y>=0 && 2*x+y==n){
            cout<<(x+y)<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
}
