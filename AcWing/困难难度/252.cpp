#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=20005;

int n,k;
int e[M],ne[M],w[M],h[N],tot;
int del[N];
int arr1[N],idx1,arr2[N],idx2;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

int get_size(int u,int fa) {
    if (del[u]) return 0;
    int sz=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        sz+=get_size(e[i],u);
    }
    return sz;
}

int get_center(int u,int fa,int sz,int& cen) {
    if (del[u]) return 0;
    int mx=0;
    int sum=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        int k=get_center(e[i],u,sz,cen);
        sum+=k;
        mx=max(mx,k);
    }
    mx=max(mx,sz-sum);
    if (mx<=sz/2) cen=u;
    return sum;
}

void get_dis(int u,int fa,int dis,int& idx) {
    if (del[u]) return;
    arr2[++idx]=dis;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        get_dis(e[i],u,dis+w[i],idx);
    }
}

bool cmp(const int& a,const int& b) {
    return a<b;
}

int calc(int* arr,int idx) {
    int res=0;
    sort(arr+1,arr+1+idx,cmp);
    for (int i=0,j=idx;j;--j) {
        while (i+1<j && arr[i+1]+arr[j]<=k) i++;
        i=min(i,j-1);
        res+=i-1;
    }
    return res;
}

int solve(int u) {
    if (del[u]) return 0;
    get_center(u,0,get_size(u,0),u);
    del[u]=true;
    int res=0;
    idx1=0;
    for (int i=h[u];~i;i=ne[i]) {
        idx2=0; get_dis(e[i],u,w[i],idx2);
        res-=calc(arr2,idx2);
        for (int j=1;j<=idx2;++j) {
            if (arr2[j]<=k) res++;
            arr1[++idx1]=arr2[j];
        }
    }
    res+=calc(arr1,idx1);
    for (int i=h[u];~i;i=ne[i]) res+=solve(e[i]);
    return res;
}

int main() {
    while (scanf("%d %d",&n,&k),n || k) {
        for (int i=1;i<=n;++i) del[i]=false,h[i]=-1;
        for (int i=1;i<=n-1;++i) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c); a++,b++;
            add(a,b,c); add(b,a,c);
        }
        printf("%d\n",solve(1));
    }
    return 0;
}