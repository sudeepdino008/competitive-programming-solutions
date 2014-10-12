#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 1000010
#define MOD 1000000007

string text,pattern;
int failur[MX],length_a,length_b,cnt;

void FailureFunction()
{
    int i=1,j=0;
    failur[0]=0;
    while(i<length_b)
    {
        if(pattern[i]==pattern[j])
        {
            j++;
            failur[i]=j;
            i++;
        }
        else if(j>0)
            j=failur[j-1];
        else
        {
            failur[i]=0;
            i++;
        }
    }
//	 for(i=0;i<length_b;i++)printf("%d %d\n",i,failur[i]);
}

int main()
{
    int t,kk=1;
    cin>>t;
    while(t--)
    {
        cin>>length_b>>pattern;
        FailureFunction();
        cout<<"Test case #"<<kk++<<endl;

        for(int i=1;i<length_b;i++)
            {
                //cout<<i+1<<" "<<failur[i]<<endl;
                int miss_matched=i+1-failur[i];
                if((i+1)%miss_matched==0)
                    if((i+1)/miss_matched>1)
                        cout<<i+1<<" "<<(i+1)/miss_matched<<endl;
            }
        cout<<endl;
    }
return 0;
}
