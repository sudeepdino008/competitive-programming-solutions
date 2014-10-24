/*#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define SIZE 10
#define round(x) (int(x+0.5))
#define log2(x) int(log(x)/log(2))
using namespace std;

int main()
{
    int array[SIZE],i, ys=log2(SIZE), rmq[SIZE][ys+1], j;
    cout<<log2(SIZE)<<endl;
    for(i=0;i<SIZE;i++)
        scanf("%d",&array[i]);

    for(i=0;i<SIZE;i++)
        rmq[i][0]=i;

    for(j=1;(1<<j)<=SIZE;j++)
    {
        for(i=0;i+(1<<j)-1<SIZE;i++)
        {
            if(array[rmq[i][j-1]]<=array[rmq[i+(1<<(j-1))][j-1]])
                rmq[i][j]=rmq[i][j-1];
            else
                rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
        }
    }
    int n,m,k;
    for(i=0;i<10;i++)
    {
        cin>>n>>m;
        k=log2(m-n+1);
        if(array[rmq[n][k]]<=array[rmq[m-(1<<k)+1][k]])
            cout<<array[rmq[n][k]]<<endl;
        else
            cout<<array[rmq[m-(1<<k)+1][k]]<<endl;
    }


}
*/


#include<iostream>

using namespace std;

void print(int number)
{
    string s="";
    while(number!=0)
    {
        if(number%2==0)
            s="0"+s;
        else
            s="1"+s;
        number/=2;
    }
    cout<<"\n\n"<<s<<endl;
}



int main()
{
    int x;
    cin>>x;
    cout<<"number:\n";
    print(x);
    cout<<"\n\n";
        x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
        print(x);
    x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
print(x);
x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
print(x);
x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
print(x);
x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
print(x);


}

