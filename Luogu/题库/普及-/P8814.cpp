#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
依题意得
Ni=PiQi |1|
EiDi=(Pi-1)(Qi-1)+1
Mi=Ni-EiDi+2 |4|
整式分解得 Eidi=PiQi-Pi-Qi+2 |2|
把|1|代入|2|得 Eidi=Ni-Pi-Qi+2 |3|
把|3|带入|4|得 Mi=Pi+Qi
即 || Pi+Qi=Ni-EiDi+2
   || PiQi=Ni

已知a+b与ab，求a-b：
∵ (a+b)^2=a^2+2ab+b^2 完全平方和
又∵ (a-b)^2=a^2-2ab+b^2 完全平方差
∴ (a+b)^2-(a-b)^2=a^2+2ab+b^2-a^2+2ab-b^2
化简得 (a+b)^2-(a-b)^2=4ab
即 (a-b)^2=(a+b)^2-4ab
得 sqrt((a-b)^2)=sqrt((a+b)^2-4ab)
即 a-b=sqrt((a+b)^2-4ab)

∴ 可得方程组 || Pi-Qi=sqrt((Ni-Eidi+2)^2-4Ni)    [1]
             || Pi+Qi=Ni-EiDi+2                  [2]
∴ [1]+[2] 得 2Pi=Ni-EiDi+2+sqrt((Ni-Eidi+2)^2-4Ni)
∴ 两边同除2 得 Pi=(Ni-EiDi+2+sqrt((Ni-Eidi+2)^2-4Ni))/2
由[2]得 Qi=Ni-Eidi+2-Pi
∴ Qi=Ni-Eidi+2-(Ni-EiDi+2+sqrt((Ni-Eidi+2)^2-4Ni))/2
∴ Qi=(2Ni-2Eidi+4)/2-(Ni-EiDi+2+sqrt((Ni-Eidi+2)^2-4Ni))/2
∴ Qi=(2Ni-2Eidi+4-Ni+Eidi-2-sqrt((Ni-Eidi+2)^2-4Ni))/2
∴ 化简得 Qi=(Ni-Eidi+2-sqrt((Ni-Eidi+2)^2-4Ni))/2
∴ 解得
Pi=(Ni-EiDi+2+sqrt((Ni-Eidi+2)^2-4Ni))/2
Qi=(Ni-Eidi+2-sqrt((Ni-Eidi+2)^2-4Ni))/2

*/

bool has_result(ll n,ll e,ll d) {
    if ((n-e*d+2)*(n-e*d+2)-4*n<0) {
        return false;
    } else {
        return true;
    }
}

ll P(ll n,ll e,ll d) {
    if (!has_result(n,e,d)) {
        return -1;
    }
    return (n-e*d+2+sqrt((n-e*d+2)*(n-e*d+2)-4*n))/2;
}

ll Q(ll n,ll e,ll d) {
    if (!has_result(n,e,d)) {
        return -1;
    }
    return (n-e*d+2-sqrt((n-e*d+2)*(n-e*d+2)-4*n))/2;
}

int main() {
    ll k;
    scanf("%lld",&k);
    ll n,e,d,p,q;
    for (ll i=0;i<k;++i) {
        scanf("%lld %lld %lld",&n,&e,&d);
        p=P(n,e,d);
        q=Q(n,e,d);
        if (p==-1 || q==-1) {
            printf("NO\n");
            continue;
        }
        if (p>q) {
            swap(p,q);
        }
        if (p*q==n && e*d==(p-1)*(q-1)+1 && p>=1 && q>=1) {
            printf("%lld %lld\n",p,q);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}