T=int(input())
for tt in range(T):
    n=int(input())
    ans=1
    while ans*2<=n:
        ans*=2
    print(ans)