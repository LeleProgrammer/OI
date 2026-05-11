k,x=input().strip().split()
k=int(k)
x=int(x)

def ksm(a,b):
    if b==0: return 1
    k=ksm(a,b//2)
    if b%2: return k*k*a%1000
    else: return k*k%1000

x=ksm(x,x)
x-=1
ans=1
for i in range(x-k+2,x+1): ans*=i
for i in range(1,k): ans//=i

print(ans)