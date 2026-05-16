#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=335;

int n,m,len,bk;
int arr[N];
int fir[N];
int p[N];
int cnt[N];
int num[N];
int res[N];
int mx;
int tg;

struct Query {
    int op,l,r,x;
} q[N];

int get(int x) {
    return (x-1)/len;
}

int getl(int x) {
    return x*len+1;
}

int getr(int x) {
    return getl(x+1)-1;
}

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

void restore() {
    memset(fir,-1,sizeof(fir));
    memset(cnt,0,sizeof(cnt));
}

void init(int from,int to) {
    mx=0; tg=0;
    for (int i=from;i<=to;++i) {
        mx=max(mx,arr[i]);
        if (!~fir[arr[i]]) {
            fir[arr[i]]=i;
            num[i]=arr[i];
        }
        // printf("p[%d] = %d\n",i,fir[arr[i]]);
        p[i]=fir[arr[i]];
        cnt[arr[i]]++;
    }
    // for (int i=1;i<=9;++i) {
        // printf("cnt[%d] = %d\n",i,cnt[i]);
    // }
}

void connect(int from,int to) {
    // cout<<"CONN: "<<from<<" "<<to<<endl;
    if (~fir[to]) {
        p[fir[from]]=fir[to];
    } else {
        fir[to]=fir[from];
        num[fir[to]]=to;
    }
    cnt[to]+=cnt[from];
    cnt[from]-=cnt[from];
    fir[from]=-1;
}

void merge(pair<int,int> from,pair<int,int> to) {
    // assert(from.first<=from.second);
    // assert(to.first<=to.second);
    if (from.first>from.second) {
        swap(from.first,from.second);
        swap(to.first,to.second);
    }
    int i=from.second;
    int j=to.second;
    while (true) {
        if (i<=100000 && j<=100000) {
            if (~fir[i]) {
                connect(i,j);
            }
            if (i==from.first) break;
        }
        i--,j--;
    }
}

void modify(int x) {
    // printf("BEFORE:\n");
    // for (int i=1;i<=n;++i) {
        // printf("p[%d] = %d\n",i,p[i]);
    // }
    if (x>=mx+tg) return;
    if (2*x>mx+tg) {
        // cout<<"MOD1"<<endl;
        // cout<<x<<" "<<tg<<" "<<mx<<endl;
        // assert(1-tg<=mx-x);
        // if (1-tg>mx-x) {
        //     printf("%d-%d>%d-%d",1,tg,mx,x);
        //     exit(0);
        // }
        // x+1-tg > mx-x+1, that's true
        merge({x+1-tg,mx},{1-tg,mx-x});
        mx=min(mx,x-tg);
    } else {
        // cout<<"MOD2"<<endl;
        // assert(x-tg<=x*2-tg);
        // merge({-tg,x-tg},{x-tg,x*2-tg});
        merge({-tg+1,-tg+x},{-tg+x+1,-tg+x*2});
        tg+=-x;
    }
    // printf("NOW:\n");
    // for (int i=1;i<=n;++i) {
        // printf("p[%d] = %d\n",i,p[i]);
    // }
}

void modify(int l,int r,int x) {
    for (int i=getl(get(l));i<=min(getr(get(r)),n);++i) {
        arr[i]=num[find(i)];
        fir[arr[i]]=-1;
        cnt[arr[i]]=0;
        arr[i]+=tg;
    }
    for (int i=getl(get(l));i<=min(getr(get(r)),n);++i) {
        num[i]=0;
    }
    for (int i=l;i<=r;++i) {
        if (arr[i]>x) {
            arr[i]-=x;
        }
    }
    // restore();
    mx=0;
    tg=0;
    for (int i=getl(get(l));i<=min(getr(get(r)),n);++i) {
        mx=max(mx,arr[i]);
        if (!~fir[arr[i]]) {
            fir[arr[i]]=i;
            num[i]=arr[i];
        }
        p[i]=fir[arr[i]];
        cnt[arr[i]]++;
    }
}

int query(int x) {
    if (x-tg>100000) return 0;
    return cnt[x-tg];
}

int query(int l,int r,int x) {
    int ans=0;
    for (int i=l;i<=r;++i) {
        // cout<<num[i]<<" "<<find(i)<<" "<<num[find(i)]<<" "<<tg<<" test"<<endl;
        if (num[find(i)]+tg==x) ans++;
    }
    return ans;
}

int main() {
    memset(fir,-1,sizeof(fir));
    scanf("%d %d",&n,&m);
    len=sqrt(n); bk=n/len; if (n%len) bk++;
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    for (int i=1;i<=m;++i) {
        int op,l,r,x;
        scanf("%d %d %d %d",&op,&l,&r,&x);
        q[i]={op,l,r,x};
        // if (i<=3 && n>=10000) {
        //     printf("%d %d %d %d\n",op,l,r,x);
        // }
    }
    int idx;
    for (int i=0;i<bk;++i) {
        // printf("bk: %d\n",i);
        idx=0;
        init(getl(i),min(getr(i),n));
        for (int j=1;j<=m;++j) {
            int op,l,r,x;
            op=q[j].op;
            // printf("op: %d\n",op);
            l=q[j].l;
            r=q[j].r;
            x=q[j].x;
            if (op==2) idx++;
            if (l<=getl(i) && r>=getr(i)) {
                // printf("1: %d %d %d %d\n",l,r,getl(i),getr(i));
                if (op==1) modify(x);
                else res[idx]+=query(x);
            } else if ((l>=getl(i) && l<=getr(i)) || (r<=getr(i) && r>=getl(i))) {
                // printf("2: %d %d %d %d\n",l,r,getl(i),getr(i));
                int L=max(getl(i),l);
                int R=min(getr(i),r);
                // printf("%d %d\n",L,R);
                if (op==1) modify(L,R,x);
                else res[idx]+=query(L,R,x);
            }
            // cout<<"TEST: "<<cnt[x]<<" "<<res[idx]<<endl;
        }
        restore();
    }
    for (int i=1;i<=idx;++i) {
        printf("%d\n",res[i]);
    }
    return 0;
}

/*
10 1
9 2 3 4 7 1 2 7 2 1
2 1 3 1
*/

/*
7 3
1 9 2 6 8 1 7
2 1 7 1
1 4 7 7
1 3 4 5

7 2
1 9 2 6 8 1 7
2 1 7 1
1 3 4 5

7 2
1 9 2 6 8 1 7
2 1 7 1
1 4 7 7

7 1
1 9 2 6 8 1 7
2 1 7 1
*/

/*
5 2
1 5 5 5 8
1 2 4 3
2 1 5 5
*/

/*
5 1
1 5 5 5 8
2 1 5 8
*/

/*
5 8
1 5 5 5 8
2 1 5 1
2 1 5 5
2 1 5 8
2 1 2 1
2 1 2 5
2 2 3 1
2 2 3 5
2 2 3 8

1
3
1
1
1
0
2
0
*/