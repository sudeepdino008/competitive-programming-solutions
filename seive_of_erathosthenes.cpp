#define SIZE 100
vector<lld> primes;
void init()
{
	lld count=0,i,j;
	vector<lld> cop;
	cop.pb(-1);
	cop.pb(-1);
	for(i=2;i<=SIZE;i++)
		cop.pb(i);
	for(i=2;i<=SIZE;i++)
	{
		if(cop[i]!=-1)
		{
			primes.pb(i);
			for(j=2*i;j<=SIZE;j+=i)
				cop[j]=-1;
		}
	}

}
