#include<bits/stdc++.h>
#define il inline
#define rg register int
#define cout std::cout
#define cerr std::cerr
#define push_back emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef long double llf;
const ff eps=1e-8;
const int maxn=1e5+5,maxb=1e3+5,lim=2e9;

std::mt19937 ewq(time(nullptr));
il int get(int l,int r){
    std::uniform_int_distribution <> QAQ(l,r);
    return QAQ(ewq);
}

int main(){
freopen("P5356.in","w",stdout);
    int n=get(1,5e3),m=get(1,5e3),x;
    // int n=get(1,10),m=get(1,20),x;
    printf("%d %d\n",n,m);
    for(rg i=1;i<=n;++i)    x=get(-2e3,2e3),printf("%d ",x);putchar('\n');
    // for(rg i=1;i<=n;++i)    x=get(-5,5),printf("%d ",x);putchar('\n');
    int opt,l,r,k;
    while(m--){
        opt=get(1,2);
        if(opt==1){
            l=get(1,n);r=get(l,n);k=get(1,r-l+1);
            printf("%d %d %d %d\n",opt,l,r,k);
        }
        else{
            l=get(1,n);r=get(l,n);k=get(-2e3,2e3);
            printf("%d %d %d %d\n",opt,l,r,k);
        }
    }
    return 0;    
}