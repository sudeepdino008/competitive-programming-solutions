def func(n,r):
    p=1
    if r<n-r:
        return func(n,n-r);
    for i in range(r+1,n+1):
        p=(p*i)/(i-r)
    return p

def calc():
    for i in range(1,70):
        print func(i,i/2), i

calc()
        
