#include <bits/stdc++.h>

#define inf -1000000

using namespace std;

int T,n,m;
int dis1,dis2;
int len1,len2;
pair<int,int> f1,f2;

struct node {
    int x,y;
} a,b,c,d;

int query(int x,int y) {
    printf("? %d %d\n",x,y);
    int ans;
    scanf("%d",&ans);
    return ans;
}

void answer(int x,int y) {
    cout<<"! "<<x<<" "<<y<<endl;
}

pair<int,int> fac(int x,int y) {
    y-=x;
    x-=x;
    return {1,y};
}

pair<int,int> fac2(int x1,int y1,int x2,int y2) {
    int kk=x1-x2;
    int l=y1-y2;
    int k=l/kk;
    int b=y1-x1*k;
    return {k,b};
}

pair<int,int> col(pair<int,int> a,pair<int,int> b) {
    int aa=a.first-b.first;
    int bb=b.second-a.second;
    int x=bb/aa;
    int y=a.first*x+a.second;
    if (a.first*x+a.second==b.first*x+b.second) return {x,y};
    else return {inf,inf};
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        dis1=query(1,1);
        dis2=query(n,m);
        // if (m>n) {
        //     if (dis1<m) {
        //         len1=min(n,dis1+1);
        //     } else {
        //         len1=n+m-dis1;
        //     }
        //     if (dis2<=m) len2=min(n,len2+1);
        //     else len2=n+m-dis2;
        // } else {
        //     if (dis1<m) {
        //         len1=dis1+1;
        //     } else {
        //         if (dis1-m+1>=n-m+1) len1=m-dis1+n-1;
        //         else len1=m;
        //         if (dis2-m+1>=n-m+1) len2=m-dis2+n-1;
        //         else len2=m;
        //     }
        // }
        b={dis1+1,1};
        a={1,dis1+1};
        if (a.y>n) {
            a.x+=a.y-n;
            a.y-=a.y-n;
        }
        if (b.x>m) {
            b.y+=b.x-m;
            b.x-=b.x-m;
        }
        int midx,midy;
        midx=a.x+b.x>>1;
        midy=a.y+b.y>>1;
        if ((a.x+b.x)%2) midx++;
        int dis3=query(midx,midy);
        f1=fac(a.x,a.y);
        f2=fac(b.x,b.y);
        pair<int,int> _1,_2;
        _1=fac2(midx,midy-dis3,midx+dis3,midy);
        _2=fac2(midx,midy+dis3,midx-dis3,midy);
        pair<int,int> col1,col2,col3,col4;
        col1=col(_1,f1);
        col2=col(_2,f1);
        col3=col(_1,f2);
        col4=col(_2,f2);
        pair<int,int> cola,colb;
        if (col1.first==inf) cola=col2;
        else cola=col1;
        if (col3.first==inf) colb=col4;
        else colb=col3;
        int dis4=query(cola.first,cola.second);
        if (dis4==0) {
            answer(cola.first,cola.second);
        } else {
            answer(colb.first,colb.second);
        }
    }
    return 0;
}