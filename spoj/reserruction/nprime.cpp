#include <cstdio>
#define L 1300000
#define f(i,a,b) for(i=a;i<L;i+=b)
int a[L],b[L],i,k,t;main(){f(i,2,1)a[i]=i;f(i,2,1)if(a[i]+1){b[++k]=a[i];f(t,2*i,i)a[t]=-1;}while(scanf("%d",&t)!=EOF)printf("%d\n",b[t]);}
