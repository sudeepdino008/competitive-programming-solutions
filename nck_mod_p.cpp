lld expo(lld a, lld n, lld m)
{
	if(n==0)
		return 1;
	lld p=expo(a,n/2,m);
	if(n%2==0)
		return (p*p)%m;
	else
		return (((p*p)%m)*a)%m;
}

lld inverse_modulo(lld a, lld m)
{
	return expo(a,m-2,m);
}

lld combi(lld n, lld k,lld m)
{
	if(n<k)
		return 0;
	if(n-k<k)
		return combi(n,n-k,m);
	lld i,p=1,t=1;
	for(i=n-k+1;i<=n;i++)
		p=(p*i)%m;
	for(i=1;i<=k;i++)
		t=(t*i)%m;
	return (p*inverse_modulo(t,m))%m;
}
