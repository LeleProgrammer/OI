#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int e[M],ne[M],h[N],tot;
double w[M];
double f[N],per[N];
int in[N],out[N];
queue<int> q;

void add(int a,int b,double c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (!in[i]) q.push(i);
    }
    per[1]=1.00;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            f[e[i]]+=(f[u]+w[i]*per[u])/out[u];
            per[e[i]]+=per[u]/out[u];
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        double c;
        scanf("%d %d %lf",&a,&b,&c);
        add(a,b,c);
        in[b]++,out[a]++;
    }
    topu();
    printf("%.2lf",f[n]);
    return 0;
}