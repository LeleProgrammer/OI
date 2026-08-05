from functools import cmp_to_key
import sys

sys.set_int_max_str_digits(1000000)

def cmp(a,b):
    if a+b<=b+a: return 1
    else: return -1

n=int(input())
arr=[]
for i in range(1,n+1):
    arr.append(str(bin(i)).replace("0b",""))
arr.sort(key=cmp_to_key(cmp))
ans=""
for i in arr:
    ans+=i
print(int(ans,2))