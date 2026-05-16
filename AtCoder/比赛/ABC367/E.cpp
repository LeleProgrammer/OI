#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int M=200005;

int n,k;
int x[N];
int arr[N];
int p[N],fa[N];
bool isst[N];
vector<int> st;
vector<int> t[N];
deque<int> q[N];
int ans[N];
vector<int> tt;
deque<int> qq;
int in[N];
int e[M],ne[M],h[N],tot,indeg[N],outdeg[N];
queue<int> qu;
int useq[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int find(int x) {
    if (p[x]==x) return p[x];
    else return p[x]=find(p[x]);
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (outdeg[i] && !indeg[i]) {
            qu.push_back(i);
        }
    }
}

signed main() {
    memset(in,-1,sizeof(in));
    scanf("%lld %lld",&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&x[i]);
    }
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
        fa[i]=x[i];
    }
    for (int i=1;i<=n;++i) {
        p[i]=i;
    }
    for (int i=1;i<=n;++i) {
        int a=find(i);
        int b=find(fa[i]);
        if (a!=b) p[a]=b;
        else {
            st.push_back(a);
            isst[a]=true;
        }
    }
    sort(st.begin(),st.end());
    for (int i=0;i<st.size();++i) {
        int j=st[i];
        while (true) {
            in[j]=t[i].size();
            t[i].push_back(j);
            q[i].push_back(j);
            j=fa[j];
            if (j==st[i]) break;
        }
    }
    for (int i=0;i<st.size();++i) {
        int len=t[i].size();
        int move=k%len;
        while (move--) {
            q[i].push_back(q[i].front());
            q[i].pop_front();
        }
    }
    for (int i=0;i<st.size();++i) {
        for (int j=0;j<t[i].size();++j) {
            printf("%lld ",t[i][j]);
        }
        putchar(10);
    }
    for (int i=1;i<=n;++i) {
        printf("%lld ",in[i]);
    }
    putchar(10);
    for (int i=0;i<st.size();++i) {
        tt=t[i],qq=q[i];
        while (!tt.empty()) {
            ans[tt.back()]=arr[qq.back()];
            tt.pop_back();
            qq.pop_back();
        }
    }
    for (int i=1;i<=n;++i) {
        if (~in[i]) continue;
        add(fa[i],i);
        indeg[i]++;
        outdeg[fa[i]]++;
    }
    topu();
}