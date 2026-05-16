#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,k,m;

struct node {
    int a,b,c,cnt,ans;
    friend bool operator < (const node& a,const node& b) {
        if (a.a!=b.a) return a.a<b.a;
        if (a.b!=b.b) return a.b<b.b;
        return a.c<b.c;
    }
    friend bool operator == (const node& a,const node& b) {
        return a.a==b.a && a.b==b.b && a.c==b.c;
    }
} in[N],arr[N],st[N];

int tr[M];
int res[M];

int lowbit(int x) {
    return x&-x;
}

void modify(int u,int k) {
    for (int i=u;i<M;i+=lowbit(i)) tr[i]+=k;
}

int query(int u) {
    int ans=0;
    for (int i=u;i;i-=lowbit(i)) ans+=tr[i];
    return ans;
}

void merge(int l,int r) {
    if (l>=r) return;
    int mid=l+r>>1;
    merge(l,mid); merge(mid+1,r);
    int i=l,j=mid+1,k=l;
    while (i<=mid && j<=r) {
        if (arr[i].b<=arr[j].b) modify(arr[i].c,arr[i].cnt),st[k++]=arr[i++];
        else arr[j].ans+=query(arr[j].c),st[k++]=arr[j++];
    }
    while (i<=mid) modify(arr[i].c,arr[i].cnt),st[k++]=arr[i++];
    while (j<=r) arr[j].ans+=query(arr[j].c),st[k++]=arr[j++];
    for (int i=l;i<=mid;++i) modify(arr[i].c,-arr[i].cnt);
    for (int i=l;i<=r;++i) arr[i]=st[i];
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        in[i]={a,b,c,1};
    }
    sort(in+1,in+1+n);
    arr[++m]=in[1];
    for (int i=2;i<=n;++i) {
        if (in[i]==arr[m]) arr[m].cnt++;
        else arr[++m]=in[i];
    }
    merge(1,m);
    for (int i=1;i<=m;++i) {
        res[arr[i].ans+arr[i].cnt-1]+=arr[i].cnt;
    }
    for (int i=0;i<n;++i) {
        printf("%d\n",res[i]);
    }
    return 0;
}