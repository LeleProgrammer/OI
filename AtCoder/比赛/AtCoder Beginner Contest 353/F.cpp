#include <bits/stdc++.h>

#define int long long

using namespace std;

int k;
int sx,sy;
int tx,ty;
int a,b,c,d;
int lenx,leny;
int xin,yin,xout,yout;

bool get_type(int x,int y) {
    if (((x/k)+(y/k))%2) return true; // big
    else return false; // small
}

signed main() {
    scanf("%lld",&k);
    scanf("%lld %lld",&sx,&sy);
    scanf("%lld %lld",&tx,&ty);
    if (tx<sx) {
        swap(tx,sx);
        swap(ty,sy);
    }
    a=sx/k;
    b=sy/k;
    c=tx/k;
    d=ty/k;
    if (k==1) {
        printf("%lld",abs(a-c)+abs(b-d));
        return 0;
    }
    if (get_type(tx,ty)) {
        xin=yin=1;
    } else {
        if (ty<sy) {
            xin=min(tx-(c*k-1),(c*k+k)-tx);
            yin=min((d*k+k)-ty,ty-(d*k-1));
        } else {
            yin=min(ty-(d*k-1),(d*k+k)-ty);
            xin=min(tx-(c*k-1),(c*k+k)-tx);
        }
    }
    if (get_type(sx,sy)) {
        xout=yout=1;
    } else {
        if (tx<sy) {
            xout=min((a*k+k)-sx,sx-(a*k-1));
            yout=min(sy-(b*k-1),(b*k+k)-sy);
        } else {
            yout=min((b*k+k)-sy,sy-(b*k-1));
            xout=min((a*k+k)-sx,sx-(a*k-1));
        }
    }
    lenx=abs(a-c);
    leny=abs(b-d);
    a=1,b=1;
    c=lenx,d=leny;
}