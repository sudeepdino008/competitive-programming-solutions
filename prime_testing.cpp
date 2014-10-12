lld expo(lld a, lld n, lld p)
{
	if(n==0)
		return 1;
	lld ex=expo(a,n/2,p);
	if(n%2==1)
		return (((ex*ex)%p)*a)%p;
	else
		return (ex*ex)%p;
}

bool miller_rabin(lld n, lld a)
{
	if(n==2)
		return true;
	/*let n be the test value and 2<=a<=n-1. I find n-1=2^s*d. (a^d)%n=+1 or -1, return true; else check for (a^(2^i*d))%n=-1 for atleast one 2<=i<=s-1. If yes return true.*/
	  
	lld s,d,test;
	if(a>n-1)
		return true;
	d=n-1;
	s=0;
	while(d%2==0)
		s++, d=d/2;
	test=expo(a,d,n);
	if(test==1 || test==n-1)
		return true;
	while(s--)
	{
		test=expo(a,(1<<s)*d,n);
		if(test==n-1)
			return true;
	}
	return false;
}

bool prime_check(int i)
{
	if(i==1)
		return false;
	if(i==2)
		return true;
	if(miller_rabin(i,2) && miller_rabin(i,3) && miller_rabin(i,5) && miller_rabin(i,7) && miller_rabin(i,11) && miller_rabin(i,13) && miller_rabin(i,17))
		return true;
	return false;
}
