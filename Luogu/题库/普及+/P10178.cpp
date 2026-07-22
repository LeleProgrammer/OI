// #include <bits/stdc++.h>

// #define int long long
// #define inf 1000000000000000000LL

// using namespace std;

// const int N=300005;
// const int M=300005;

// int T,n,m,k;
// int e[M],w[M],ne[M],fr[M],h[N],tot;
// int e2[M],w2[M],ne2[M],h2[N],tot2;
// int dis_min[N];
// int dis_max[N];
// bool flag[N];
// bool flag2[N];
// pii edges[N];
// // int in[N];

// int usage;

// void add(int a,int b,int c) {
//     e[tot]=b,w[tot]=c,fr[tot]=a,ne[tot]=h[a],h[a]=tot++;
// }

// void add2(int a,int b,int c) {
//     e2[tot2]=b,w2[tot2]=c,ne2[tot2]=h2[a],h2[a]=tot2++;
// }

// map< pair<int,int>,int > hs;
// map< pair<int,int>,pair<int,pair<int,int> > > ans; // from,to -> add,from,to

// void bfs1() {
//     queue<int> q;
//     q.push(1);
//     flag[1]=true;
//     while (!q.empty()) {
//         int u=q.front(); q.pop();
//         for (int i=h[u];~i;i=ne[i]) {
//             if (hs.find(make_pair(u,e[i]))==hs.end()) {
//                 hs.insert(make_pair(make_pair(u,e[i]),0));
//             }
//             hs[make_pair(u,e[i])]++;
//             if (!flag[e[i]]) {
//                 flag[e[i]]=true;
//                 q.push(e[i]);
//             }
//         }
//     }
// }

// void bfs2() {
//     queue<int> q; // node
//     dis_min[1]=0;
//     dis_max[1]=0;
//     q.push(1);
//     while (!q.empty()) {
//         int u=q.front(); q.pop();
//         for (int i=h2[u];~i;i=ne2[i]) {
//             int j=e2[i];
//             if (dis_min[j]==inf) {
//                 int addd=dis_max[u]-dis_min[u]+1;
//                 dis_min[j]=dis_min[u]+1;
//                 dis_max[j]=dis_min[j]+w2[i]*addd-1;
//                 usage=max(usage,1+w2[i]*addd);
//                 ans.insert(make_pair(u,j),make_pair(addd,make_pair(1,1+w2[i]*addd)))
//             } else {
//                 int more_addd=dis_max[j]-dis_min[u];
//                 if (more_addd<0) more_addd=0;
//                 int addd=dis_max[u]-dis_min[u]+1;
//                 int tmp=dis_min[u]+more_addd+1;
//                 dis_max[j]=tmp+w2[i]*addd-1;
//                 usage=max(usage,dis_max[j]-dis_max[u]);
//                 ans.insert(make_pair(u,j),make_pair(addd,make_pair(tmp-dis_min[u],dis_max[j]-dis_max[u])));
//             }
//             q.push(j);
//         }
//     }
// }

// signed main() {
//     scanf("%lld",&T);
//     while (T--) {
//         scanf("%lld %lld %lld",&n,&m,&k);
//         for (int i=1;i<=n;++i) h[i]=-1,dis_min[i]=dis_max[i]=2000000000,h2[i]=-1,flag[i]=flag2[i]=0;
//         tot=0; tot2=0;
//         usage=0;
//         hs.clear();
//         ans.clear();
//         while (m--) {
//             int a,b,c;
//             scanf("%lld %lld %lld",&a,&b,&c);
//             add(a,b,c);
//             edges[tot-1]=make_pair(a,b);
//         }
//         bfs1();
//         for (auto it=hs.begin();it!=hs.end();++it) {
//             int _from,_to,_w;
//             _from=(it->first).first;
//             _to=(it->first).second;
//             _w=it->second;
//             add2(_from,_to,_w);
//             // in[_to]++;
//         }
//         bfs2();
//         for (int i=0;i<tot;++i) {
//             int _from,_to;
//             _from=fr[i];
//             _to=e
//         }
//     }
// }

#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

const int N=300005;
const int M=300005;

int T,n,m,k;
int e[M],w[M],ne[M],h[N],tot;
int dis[N];
int usage;
int readin[M];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs() {
    queue<int> q;
    dis[1]=0;
    q.push(1);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            int j=e[i];
            if (dis[j]==inf) {
                dis[j]=dis[u]+1;
                w[i]=1;
                usage=max(usage,1LL);
                q.push(j);
            } else {
                int use=dis[j]+1-dis[u];
                w[i]=use;
                usage=max(usage,use);
            }
        }
    }
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&m,&k);
        for (int i=1;i<=n;++i) {
            dis[i]=inf;
            h[i]=-1;
        }
        tot=0;
        usage=0;
        while (m--) {
            int a,b;
            scanf("%lld %lld",&a,&b);
            add(a,b);
        }
        bfs();
        if (usage>k) puts("No");
        else {
            puts("Yes");
            for (int i=0;i<tot;++i) {
                printf("%lld ",w[i]);
            }
            putchar(10);
        }
    }
    return 0;
}