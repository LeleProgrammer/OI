#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=20005;

int n,K;
int e[M],ne[M],w[M],h[N],tot;
int del[N];
int arr1[N],idx1,arr2[N],idx2;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

int get_size(int u,int fa) {
    if (del[u]) return 0;
    int ans=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        ans+=get_size(e[i],u);
    }
    return ans;
}

int get_center(int u,int fa,int tot,int& cen) {
    if (del[u]) return 0;
    int sum=1,mx=0;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        int ret=get_center(e[i],u,tot,cen);
        sum+=ret;
        mx=max(mx,ret);
    }
    if (mx<=tot/2) cen=u;
    return sum;
}

void get_dis(int u,int fa,int dis,int* arr,int& idx) {
    if (del[u]) return;
    arr[++idx]=dis;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        get_dis(e[i],u,dis+w[i],arr,idx);
    }
}

bool cmp(const int& a,const int& b) {
    return a<b;
}

int calc(int* arr,int idx) {
    sort(arr+1,arr+1+idx,cmp);
    int ans=0;
    for (int i=0,j=idx;j;--j) {
        while (i+1<=j && arr[i+1]+arr[j]<=K) i++;
        i=min(j-1,i);
        ans+=i-1;
    }
    return ans;
}

int solve(int u) {
    if (del[u]) return false;
    get_center(u,0,get_size(u,0),u);
    del[u]=true;
    idx1=0;
    int ans=0;
    for (int i=h[u];~i;i=ne[i]) {
        idx2=0; get_dis(e[i],u,w[i],arr2,idx2);
        ans-=calc(arr2,idx2);
        for (int j=1;j<=idx2;++j) {
            if (arr2[j]<=K) ans++;
            arr1[++idx1]=arr2[j];
        }
    }
    ans+=calc(arr1,idx1);
    for (int i=h[u];~i;i=ne[i]) ans+=solve(e[i]);
    return ans;
}

int main() {
    while (scanf("%d %d",&n,&K),n || K) {
        memset(h,-1,sizeof(h));
        memset(del,0,sizeof(del));
        for (int i=1;i<=n-1;++i) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c); a++; b++;
            add(a,b,c);
            add(b,a,c);
        }
        printf("%d\n",solve(1));
    }
    return 0;
}