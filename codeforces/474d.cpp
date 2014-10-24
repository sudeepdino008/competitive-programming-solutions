#include <cstdio>
#define lld long long int
#define MOD 1000000007
#define SIZE 100001
using namespace std;

lld dp[SIZE], sum[SIZE],i,k,t,a,b;

int main(){
    scanf("%lld %lld",&t,&k);
    dp[0]=1;sum[0]=1;
    for(i=1;i<SIZE;i++)dp[i]=(dp[i-1]+((i>=k)?dp[i-k]:0))%MOD, sum[i]=(sum[i-1]+dp[i])%MOD;
    while(t--)scanf("%lld",&a), scanf("%lld",&b), printf("%lld\n",(sum[b]-sum[a-1]+MOD)%MOD);
}
