#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int inf=2e9;

typedef pair<int,int> pii;

int n,m,len;
int w[N];
int maxx[N];
int minn[N];
int ans[N];
vector<int> nums;

struct Query {
    int id,l,r;
} q[N];

int get(int x) {
    return x/len;
}

bool cmp1(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const Query& a,const Query& b) {
    int al=get(a.l);
    int bl=get(b.l);
    if (al!=bl) return al<bl;
    return a.r<b.r;
}

void add(int x,int& s) {
    int k=w[x];
    maxx[k]=max(maxx[k],x);
    minn[k]=min(minn[k],x);
    s=max(s,maxx[k]-minn[k]);
}

void add(int x,int& s,vector<pii>& vecmax,vector<pii>& vecmin) {
    int k=w[x];
    if (x>maxx[k]) {
        vecmax.push_back({k,maxx[k]});
        maxx[k]=x;
    }
    if (x<minn[k]) {
        vecmin.push_back({k,minn[k]});
        minn[k]=x;
    }
    s=max(s,maxx[k]-minn[k]);
}

void init() {
    for (int i=0;i<N;++i) {
        maxx[i]=0;
        minn[i]=inf;
    }
}

int main() {
    scanf("%d",&n);
    len=sqrt(n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
        nums.push_back(w[i]);
    }
    sort(nums.begin(),nums.end(),cmp1);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for (int i=1;i<=n;++i) {
        w[i]=lower_bound(nums.begin(),nums.end(),w[i])-nums.begin();
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        q[i]={i,a,b};
    }
    sort(q+1,q+1+m,cmp2);
    init();
    int x=1;
    while (x<=m) {
        int y=x;
        while (y<=m && get(q[x].l)==get(q[y].l)) ++y;
        int right=get(q[x].l)*len+len-1;
        while (x<y && get(q[x].l)==get(q[x].r)) {
            int id=q[x].id;
            int l=q[x].l;
            int r=q[x].r;
            int s=0;
            for (int k=l;k<=r;++k) {
                add(k,s);
            }
            ans[id]=s;
            for (int k=l;k<=r;++k) {
                int t=w[k];
                maxx[t]=0;
                minn[t]=inf;
            }
            ++x;
        }
        int s=0;
        int i=right;
        int j=right+1;
        while (x<y) {
            int id=q[x].id;
            int l=q[x].l;
            int r=q[x].r;
            while (i<r) add(++i,s);
            int backup=s;
            vector<pii> recmax;
            vector<pii> recmin;
            while (j>l) {
                --j;
                add(j,s,recmax,recmin);
            }
            ans[id]=s;
            s=backup;
            reverse(recmax.begin(),recmax.end());
            reverse(recmin.begin(),recmin.end());
            for (int i=0;i<recmax.size();++i) {
                auto t=recmax[i];
                maxx[t.first]=t.second;
            }
            for (int i=0;i<recmin.size();++i) {
                auto t=recmin[i];
                minn[t.first]=t.second;
            }
            j=right+1;
            ++x;
        }
        init();
    }
    for (int i=1;i<=m;++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}