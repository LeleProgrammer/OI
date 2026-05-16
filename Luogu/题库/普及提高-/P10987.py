inf=int(2e9)

n,a,b=input().split()
n=int(n)
a=int(a)
b=int(b)

w=input().split()
for i in range(n):
    w[i]=int(w[i])

f=[[-inf for i in range(b+1)] for j in range(a+1)]
f[0][0]=0

ans=-inf

for i in range(n):
    for j in range(a,-1,-1):
        for k in range(b,-1,-1):
            if j-w[i]>=0:
                f[j][k]=max(f[j][k],f[j-w[i]][k]+w[i])
            if k-w[i]>=0:
                f[j][k]=max(f[j][k],f[j][k-w[i]]+w[i])
            ans=max(ans,f[j][k])

print(ans)