y=x=int(input())
k=0
while x:
    k+=((x&1)^1)
    x>>=1
y-=(1<<k)
print(y+1)