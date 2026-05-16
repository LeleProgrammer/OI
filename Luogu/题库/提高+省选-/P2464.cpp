#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,m,len;
int arr[N];
int cnt[N];
int ans[N];
vector<int> nums;

struct Query {
    int id,l,r,k,t;
} q[N];

int cntq;

struct Modify {
    int a,b;
} mod[N];

int cntm;

int get(int x) {
    return x/len;
}

bool cmp1(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const Query& a,const Query& b) {
    int al=get(a.l);
    int bl=get(b.l);
    int ar=get(a.r);
    int br=get(b.r);
    if (al!=bl) return al<bl;
    if (ar!=br) return ar<br;
    return a.t<b.t;
}

void add(int x) {
    cnt[x]++;
}

void del(int x) {
    cnt[x]--;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
        nums.push_back(arr[i]);
    }
    for (int i=1;i<=m;++i) {
        char op[2];
        scanf("%s",op);
        if (*op=='Q') {
            int a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            ++cntq;
            q[cntq]={cntq,a,b,c,cntm};
            nums.push_back(c);
        } else {
            int a,b;
            scanf("%lld %lld",&a,&b);
            mod[++cntm]={a,b};
            nums.push_back(b);
        }
    }
    len=cbrt(n*cntm)+1;
    sort(nums.begin(),nums.end(),cmp1);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for (int i=1;i<=n;++i) {
        arr[i]=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin();
    }
    for (int i=1;i<=cntm;++i) {
        mod[i].b=lower_bound(nums.begin(),nums.end(),mod[i].b)-nums.begin();
    }
    for (int i=1;i<=cntq;++i) {
        q[i].k=lower_bound(nums.begin(),nums.end(),q[i].k)-nums.begin();
    }
    sort(q+1,q+1+cntq,cmp2);
    for (int k=1,i=0,j=1,t=0;k<=cntq;++k) {
        int id=q[k].id;
        int l=q[k].l;
        int r=q[k].r;
        int p=q[k].k;
        int tt=q[k].t;
        while (i<r) add(arr[++i]);
        while (i>r) del(arr[i--]);
        while (j<l) del(arr[j++]);
        while (j>l) add(arr[--j]);
        while (t<tt) {
            ++t;
            if (mod[t].a>=l && mod[t].a<=r) {
                del(arr[mod[t].a]);
                add(mod[t].b);
            }
            swap(mod[t].b,arr[mod[t].a]);
        }
        while (t>tt) {
            if (mod[t].a>=l && mod[t].a<=r) {
                del(arr[mod[t].a]);
                add(mod[t].b);
            }
            swap(mod[t].b,arr[mod[t].a]);
            --t;
        }
        ans[id]=cnt[p];
    }
    for (int i=1;i<=cntq;++i) printf("%lld\n",ans[i]);
    return 0;
}