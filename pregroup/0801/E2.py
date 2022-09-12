fp=open("E2.biao","w")
js=[1]
n=151
for i in range(1,n+1):
    js.append(js[i-1]*i)
f=[]
sum=[]
for i in range(0,n*n*n+1):
    f.append(0)
    sum.append(0)
def trans(i,j,l):
    return (i)*n*n+(j)*n+l
def C(n,m):
    ret=1
    for i in range(1,m+1):
        ret=ret*(n-i+1)//i
    return ret
for i in range(0,n):
    f[trans(1,i,0)]=1
for i in range(1,n):
    for s in range(1,n):
        for l in range(1,s+1):
            for j in range(1,i):
                f[trans(i,s,l)]+=f[trans(i-j,s,l-1)]*sum[trans(0,j,s)]*C(i-1,j)
    sum[trans(0,i,0)]=f[trans(i,0,0)]
    for s in range(1,n):
        sum[trans(0,i,s)]=sum[trans(0,i,s-1)]+f[trans(i,s,s)]//js[s]
        
    fp.write(str(int(sum[trans(0,i,i)])))
    fp.write('\n')
# for i in range(1,n):
    # print('\n')
fp.close()