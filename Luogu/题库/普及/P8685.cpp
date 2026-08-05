#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m,t;
int a[N];
bool cache[N];
int last[N];

struct node {
    int ts,id;
    friend bool operator < (const node& a,const node& b) {
        return a.ts<b.ts;
    }
} arr[N];

void update(int id,int time) {
    if (time-last[id]<=0) return;
    a[id]=max(0,a[id]-(time-last[id]));
    last[id]=time;
    if (a[id]<=3) cache[id]=false;
}

int main() {
    scanf("%d %d %d",&n,&m,&t);
    for (int i=1;i<=m;++i) {
        scanf("%d %d",&arr[i].ts,&arr[i].id);
    }
    sort(arr+1,arr+1+m);
    for (int i=1;i<=m;++i) {
        int ts,id;
        ts=arr[i].ts;
        id=arr[i].id;
        update(id,ts-1);
        a[id]+=2;
        if (a[id]>5) cache[id]=true;
        last[id]=ts;
    }
    for (int i=1;i<=n;++i) {
        update(i,t);
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (cache[i]) ans++;
    }
    printf("%d",ans);
    return 0;
}

/*
1 1
2 1
3 1
5 2
6 2
6 2
*/