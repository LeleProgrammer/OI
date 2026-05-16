#include <bits/stdc++.h>
using namespace std;

int T,m;
int a,b,c;
int delta;

int gcd(int a,int b) {
    if (a<0) a=abs(a);
    if (b<0) b=abs(b);
    if (a<b) swap(a,b);
    if (!b) return a;
    return gcd(b,a%b);
}

pair<int,int> sqrt_change(int pw) {
    pair<int,int> res;
    int &a=res.first; a=1;
    int &b=res.second;
    for (int i=2;i*i<=pw;++i) {
        while (pw%(i*i)==0) a*=i,pw/=(i*i);
    }
    b=pw;
    return res;
}

int negative_or_positive(double a,double b,double c) {
    double delta=b*b-4*a*c;
    double positive=(-b+sqrt(delta))/(2*a);
    double negative=(-b-sqrt(delta))/(2*a);
    if (positive>negative) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    scanf("%d %d",&T,&m);
    while (T--) {
        scanf("%d %d %d",&a,&b,&c);
        delta=b*b-4*a*c;
        if (delta<0) {
            printf("NO\n");
            continue;
        }
        int q1u=-b,q1d=2*a;
        int q2u=negative_or_positive(a,b,c),q2d=2*a;
        // delta=8; q1u=2; q1d=-1234; q2u=1; q2d=4;
        if (q1d<0) {
            q1d*=-1;
            q1u*=-1;
        }
        if (q2d<0) {
            q2d*=-1;
            q2u*=-1;
        }
        auto sc=sqrt_change(delta);
        q2u*=sc.first;
        delta=sc.second;
        // printf("%d %d %d %d %d\n",q1u,q2u,q1d,q2d,delta);
        if (delta==1) {
            int q3u=q1u+q2u;
            int q3d=q1d;
            int tmp=gcd(q3u,q3d);
            q3d/=tmp,q3u/=tmp;
            if (q3d<0) {
                q3d*=-1,q3u*=-1;
            }
            if (q3d==1) {
                printf("%d",q3u);
            } else {
                printf("%d/%d",q3u,q3d);
            }
            putchar(10);
            continue;
        } else if (delta==0) {
            if (q1d<0) {
                q1d*=-1,q1u*=-1;
            }
            int tmp=gcd(q1d,q1u);
            q1d/=tmp,q1u/=tmp;
            if (q1d==1) {
                printf("%d",q1u);
            } else {
                printf("%d/%d",q1u,q1d);
            }
            putchar(10);
            continue;
        }
        if (q2u<0) {
            q2u*=-1,q1u*=-1;
        }
        if (q1u!=0) {
            int tmp=gcd(q1u,q1d);
            q1u/=tmp,q1d/=tmp;
            if (q1d==1 && q1u) {
                printf("%d+",q1u);
            } else if (q1u) {
                printf("%d/%d+",q1u,q1d);
            }
        }
        int tmp=gcd(q2u,q2d);
        q2u/=tmp,q2d/=tmp;
        if (q2u!=1) {
            printf("%d*",q2u);
        }
        printf("sqrt(%d)",delta);
        if (q2d!=1) {
            printf("/%d",q2d);
        }
        putchar(10);
    }
    return 0;
}

/*
(-b+sqrt(delta))/(2a)
-b/2a + sqrt(delta)/2a
*/