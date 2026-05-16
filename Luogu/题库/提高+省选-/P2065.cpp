#include <bits/stdc++.h>
using namespace std;

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
        }
        c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using namespace IO;

const int N=10007;
const int M=502005;
const int inf=2e9;

int tt;
int m,n,S,T;
int a[N],b[N];
int e[M],f[M],ne[M],h[N],tot;
int layer[N],cur[N];
unordered_map<int,int> ps;
int idx;

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

int gcd(int a,int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

bool bfs() {
    queue<int> q;
    memset(layer,-1,sizeof(layer));
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(limit-k,f[i]));
            if (!ret) layer[e[i]]=-1;
            k+=ret; f[i]-=ret; f[i^1]+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

void process(int k,int item) {
    for (int i=2;i*i<=k;++i) {
        if (k%i) continue;
        int pt;
        if (ps.find(i)==ps.end()) {
            ps.insert({i,++idx});
            pt=idx;
        } else pt=ps.find(i)->second;
        add(item,n+m+pt,1);
        while (k%i==0) k/=i;
    }
    if (k!=1) {
        int pt;
        if (ps.find(k)==ps.end()) {
            ps.insert({k,++idx});
            pt=idx;
        } else pt=ps.find(k)->second;
        add(item,n+m+pt,1);
    }
}

void process2(int k,int item) {
    for (int i=2;i*i<=k;++i) {
        if (k%i) continue;
        int pt;
        if (ps.find(i)==ps.end()) {
            ps.insert({i,++idx});
            pt=idx;
        } else pt=ps.find(i)->second;
        add(n+m+pt,item,1);
        while (k%i==0) k/=i;
    }
    if (k!=1) {
        int pt;
        if (ps.find(k)==ps.end()) {
            ps.insert({k,++idx});
            pt=idx;
        } else pt=ps.find(k)->second;
        add(n+m+pt,item,1);
    }
}

int main() {
    // scanf("%d",&tt);
    read(tt);
    while (tt--) {
        // scanf("%d %d",&m,&n);
        ps.clear(); idx=0;
        memset(h,-1,sizeof(h));
        read(m); read(n);
        S=0,T=N-1;
        for (int i=1;i<=m;++i) {
            // scanf("%d",&a[i]);
            read(a[i]);
            process(a[i],i);
        }
        for (int i=1;i<=n;++i) {
            // scanf("%d",&b[i]);
            read(b[i]);
            process2(b[i],m+i);
        }
        for (int i=1;i<=m;++i) {
            add(S,i,1);
        }
        for (int i=1;i<=n;++i) {
            add(m+i,T,1);
        }
        // for (int i=0;i<tot;++i) {
        //     printf("%d to %d: %d\n",e[i^1],e[i],f[i]);
        // }
        // printf("%d\n",dinic());
        write(dinic()); putchar(10);
    }
    return 0;
}

/*
1
2 3
4 9
8 16 32
*/