ans=0
xq=7

def check(mon,day,xq):
    return ("1" in str(mon)) or ("1" in str(day)) or (xq==1)

for month in range(1,13):
    days=0
    if month in [1,3,5,7,8,10,12]:
        days=31
    elif month!=2:
        days=30
    else:
        days=28
    for day in range(1,days+1):
        if check(month,day,xq):
            ans+=5
        else:
            ans+=1
        xq+=1
        if xq==8:
            xq=1

print(ans)