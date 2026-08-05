ans=1
n=2025
flag=[False for i in range(2030)]
f=[[0,0] for i in range(2030)]
mod=10**9+7

f[1][0]=f[1][1]=1
for i in range(2,n+1):
    f[i][0]=(f[i-1][0]+f[i-1][1])%mod
    f[i][1]=f[i-1][0]
for i in range(1,n+1):
    if not flag[i]:
        cnt=0
        j=i
        while j<=n:
            cnt+=1
            flag[j]=True
            j<<=1
        ans=ans*(f[cnt][0]+f[cnt][1])%mod
print(ans)