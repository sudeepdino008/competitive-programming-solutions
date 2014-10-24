import sys

MOD = 1000000007
size = 200

fibonacci=[]
suma=[]

def recurse(length, k, val):
    if length<0:
        return val
    if suma[length]>=k:
        return recurse(length-1,k,2*val)
    else:
        return recurse(length-1,k-suma[length],2*val+1)

def findGroup(n):
    for i in range(1,size+1):
    #    print "aaa",i,n,suma[i], suma[i-1]
        if n<=suma[i]-1:
            return i,n-suma[i-1]+1;
    return -1,-1

def main():
    fibonacci.append(0)
    fibonacci.append(1)
    suma.append(1)
    suma.append(2)
    for i in range(2,size+1):
        fibonacci.append(fibonacci[i-1]+fibonacci[i-2])
        suma.append(suma[i-1]+fibonacci[i])

    p = sys.stdin().readlines()
    n = int(p[0])

    print p
    lis = [int(x) for x in p[1].split(" ")]
  
    val = 0
    for i in lis:
        group, k = findGroup(i)
#        print i, k, group
        if i==1:
            val=val^1
        else:
            k = recurse(group-3,k,2)
            #print 'sssssssss',i,k
            val=val^k
    print val%MOD


main()
