#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (rint i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (rint i=(a);i<=(b);c)
#define _rrep(i,a,b) for (rint i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (rint i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define rint register int
#define LL long long
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=100005;
const int inf=2e9;

int n,m,len;
int a[N];
pii b[N];
int nn;
int B[N],L[N],R[N],BL[N],BR[N];
int mx[N],mn[N];
int s[N];
pii vl[N],vr[N];
int pl,pr;

inline void modify(int l,int r,int k) {
    if (B[l]==B[r]) {
        _rep(i,L[l],R[l]) a[i]+=s[B[i]],b[i].first+=s[B[i]];
        s[B[l]]=0;
        vector<pii> vl,vr;
        _rep(i,L[l],R[l]) if (b[i].second<l || b[i].second>r) vl.emplace_back(b[i]); else vr.emplace_back(pii{b[i].first+k,b[i].second}),a[b[i].second]+=k;
        // cout<<"vl: "; _iter(it,vl) cout<<it->second<<" "; putchar(10);
        int i=0,j=0,cur=L[l];
        while (i<vl.size() && j<vr.size()) {
            if (vl[i]<vr[j]) b[cur++]=vl[i++];
            else b[cur++]=vr[j++];
        }
        while (i<vl.size()) b[cur++]=vl[i++];
        while (j<vr.size()) b[cur++]=vr[j++];
        mx[B[l]]=-inf,mn[B[l]]=inf;
        _rep(i,L[l],R[l]) mx[B[l]]=max(mx[B[l]],a[i]),mn[B[l]]=min(mn[B[l]],a[i]);
        return;
    }
    _rep(i,B[l]+1,B[r]-1) s[i]+=k;
    _rep(i,L[l],R[l]) a[i]+=s[B[i]],b[i].first+=s[B[i]];
    _rep(i,L[r],R[r]) a[i]+=s[B[i]],b[i].first+=s[B[i]];
    s[B[l]]=s[B[r]]=0;
    pl=pr=0;
    _rep(i,L[l],R[l]) if (b[i].second<l) vl[++pl]=b[i]; else vr[++pr]=pii{b[i].first+k,b[i].second},a[b[i].second]+=k;
    int i=1,j=1,cur=L[l];
    while (i<=pl && j<=pr) {
        if (vl[i]<vr[j]) b[cur++]=vl[i++];
        else b[cur++]=vr[j++];
    }
    while (i<=pl) b[cur++]=vl[i++];
    while (j<=pr) b[cur++]=vr[j++];
    mx[B[l]]=-inf,mn[B[l]]=inf;
    _rep(i,L[l],R[l]) mx[B[l]]=max(mx[B[l]],a[i]),mn[B[l]]=min(mn[B[l]],a[i]);
    pl=pr=0;
    _rep(i,L[r],R[r]) if (b[i].second<=r) vl[++pl]=pii{b[i].first+k,b[i].second},a[b[i].second]+=k; else vr[++pr]=b[i];
    i=1,j=1,cur=L[r];
    while (i<=pl && j<=pr) {
        if (vl[i]<vr[j]) b[cur++]=vl[i++];
        else b[cur++]=vr[j++];
    }
    while (i<=pl) b[cur++]=vl[i++];
    while (j<=pr) b[cur++]=vr[j++];
    mx[B[r]]=-inf,mn[B[r]]=inf;
    _rep(i,L[r],R[r]) mx[B[r]]=max(mx[B[r]],a[i]),mn[B[r]]=min(mn[B[r]],a[i]);
}

inline bool cmp(const pii& a,const pii& b) {
    return a.first<b.first;
}

inline int query(int l,int r,int k) {
    if (k>r-l+1) return -1;
    int ll=inf,rr=-inf;
    if (B[l]==B[r]) {
        _rep(i,l,r) ll=min(ll,a[i]+s[B[i]]),rr=max(rr,a[i]+s[B[i]]);
    } else {
        _rep(i,B[l]+1,B[r]-1) ll=min(ll,mn[i]+s[i]),rr=max(rr,mx[i]+s[i]);
        _rep(i,l,R[l]) ll=min(ll,a[i]+s[B[i]]),rr=max(rr,a[i]+s[B[i]]);
        _rep(i,L[r],r) ll=min(ll,a[i]+s[B[i]]),rr=max(rr,a[i]+s[B[i]]);
    }
    while (ll<rr) {
        int mid=(i64)ll+rr>>1;
        int cnt=0;
        if (B[l]==B[r]) {
            // _rep(i,l,r) printf("a[%d] = %d, B[%d] = %d\n",i,a[i]+s[B[i]],i,B[i]);
            _rep(i,l,r) {
                if (cnt>=k) break;
                if (a[i]+s[B[i]]<=mid) cnt++;
            }
        } else {
            _rep(i,B[l]+1,B[r]-1) {
                // int lll=BL[i],rrr=BR[i];
                // while (lll<rrr) {
                //     int mmid=lll+rrr+1>>1;
                //     if (b[mmid].first<=mid-s[i]) lll=mmid;
                //     else rrr=mmid-1;
                // }
                int pos=upper_bound(b+BL[i],b+1+BR[i],pii{mid-s[i],-1},cmp)-b-1;
                cnt+=pos-BL[i]+1;
                if (cnt>=k) break;
            }
            _rep(i,l,R[l]) {
                if (cnt>=k) break;
                if (a[i]+s[B[i]]<=mid) cnt++;
            }
            _rep(i,L[r],r) {
                if (cnt>=k) break;
                if (a[i]+s[B[i]]<=mid) cnt++;
            }
        }
        if (cnt>=k) rr=mid;
        else ll=mid+1;
    }
    return ll;
}

int main() {
    // FRR("P5356.in");
    // FRW("P5356_wa.out");
    read(n),read(m),len=200;
    _rep(i,1,n) read(a[i]),b[i]=pii{a[i],i};
    _rep(i,1,n) {
        B[i]=i/len+1,nn=B[i];
        if (B[i]==B[i-1]) L[i]=L[i-1]; else L[i]=i;
    }
    _rrep(i,n,1) if (B[i]==B[i+1]) R[i]=R[i+1]; else R[i]=i;
    _rep(i,1,n) BL[B[i]]=L[i],BR[B[i]]=R[i];
    _rep(i,1,nn) mx[i]=-inf,mn[i]=inf;
    _rep(i,1,nn) _rep(j,BL[i],BR[i]) mx[i]=max(mx[i],a[j]),mn[i]=min(mn[i],a[j]);
    _rep(i,1,nn) sort(b+BL[i],b+1+BR[i],cmp);
    // cout<<"L: "; _rep(i,1,n) cout<<L[i]<<" "; putchar(10);
    // cout<<"R: "; _rep(i,1,n) cout<<R[i]<<" "; putchar(10);
    // cout<<"Test: "; _rep(i,1,n) writesp(a[i]+s[B[i]]); putchar(10);
    while (m--) {
        int op,l,r,k;
        read(op),read(l),read(r),read(k);
        if (op==1) {
            writeln(query(l,r,k));
        } else {
            modify(l,r,k);
        }
        // cout<<"Test: "; _rep(i,1,n) writesp(a[i]+s[B[i]]); putchar(10);
    }
    return 0;
}