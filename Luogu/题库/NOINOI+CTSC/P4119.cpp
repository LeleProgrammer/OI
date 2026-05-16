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

using IO::read;

const int N=100005;
const int M=335;
const int K=335;

int n,m,len,len2,bk,bk2;
int arr[N];
int cnt[K][N];
int pre[K][N];
int seg[K][M];
int fir[K][N];
int p[N];
int asi[M];
int bkt[N];

inline int get(int x) { // divide by 0
    return (x-1)/len;
}

inline int getl(int x) {
    return x*len+1;
}

inline int getr(int x) {
    return (x+1)*len;
}

inline int get2(int x) {
    return (x-1)/len2;
}

inline int getl2(int x) {
    return x*len2+1;
}

inline int getr2(int x) {
    return (x+1)*len2;
}

inline int find(int x) { // floating point exception
    if (p[x]==x) return x;
    else return p[x]=find(p[x]);
}

inline void init() {
    for (int i=1;i<=n;++i) {
        cnt[get(i)][arr[i]]++;
        // printf("cnt[%d][%d] = %d\n",get(i),arr[i],cnt[get(i)][arr[i]]);
    }
    for (int i=0;i<bk;++i) {
        for (int j=1;j<=n;++j) {
            if (i==0) {
                pre[i][j]=cnt[i][j];
                continue;
            }
            pre[i][j]=cnt[i][j]+pre[i-1][j];
            // printf("pre[%d][%d] = %d\n",i,j,pre[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        seg[get(i)][get2(arr[i])]++;
        // printf("seg[%d][%d] = %d\n",get(i),get2(arr[i]),seg[get(i)][get2(arr[i])]);
    }
    for (int i=1;i<bk;++i) {
        for (int j=0;j<bk2;++j) {
            seg[i][j]+=seg[i-1][j];
        }
    }
    memset(fir,-1,sizeof(fir));
    for (int i=1;i<=n;++i) {
        if (!~fir[get(i)][arr[i]]) {
            fir[get(i)][arr[i]]=i;
        }
        p[i]=fir[get(i)][arr[i]];
    }
    // for (int i=1;i<=n;++i) {
    //     printf("p[%d]=%d\n",i,p[i]);
    // }
}

inline void modify(int l,int r,int x,int y) { // divide by 0
    if (x==y) return;
    if (get(l)==get(r)) { // divide by 0 // tle
        int chgcnt=0;
        for (int i=getl(get(l));i<=min(getr(get(l)),n);++i) { // divide by 0
            // printf("find(%d) = %d\n",i,find(i));
            arr[i]=arr[find(i)];
        }
        for (int i=l;i<=r;++i) {
            if (arr[i]==x) {
                arr[i]=y;
                chgcnt++;
            }
        }
        cnt[get(l)][y]+=chgcnt;
        cnt[get(l)][x]-=chgcnt;
        fir[get(l)][x]=-1;
        fir[get(l)][y]=-1;
        for (int i=getl(get(l));i<=min(getr(get(l)),n);++i) {
            if (arr[i]!=x && arr[i]!=y) continue;
            if (!~fir[get(i)][arr[i]]) {
                fir[get(i)][arr[i]]=i;
            }
            p[i]=fir[get(i)][arr[i]];
        }
        for (int i=get(l);i<bk;++i) {
            seg[i][get2(y)]+=chgcnt;
            seg[i][get2(x)]-=chgcnt;
            pre[i][y]+=chgcnt;
            pre[i][x]-=chgcnt;
        }
        // printf("fir[%d][%d]=%d\n",get(l),x,fir[get(l)][x]);
        // printf("fir[%d][%d]=%d\n",get(l),y,fir[get(l)][y]);
    } else {
        modify(l,getr(get(l)),x,y);
        modify(getl(get(r)),r,x,y);
        int yadd=0;
        int xadd=0;
        int i;
        for (i=get(l)+1;i<=get(r)-1;++i) {
            if (~fir[i][x]) {
                if (~fir[i][y]) p[fir[i][x]]=fir[i][y];
                else fir[i][y]=fir[i][x],arr[fir[i][x]]=y;
                fir[i][x]=-1;
                yadd+=cnt[i][x];
                xadd+=-cnt[i][x];
                cnt[i][y]+=cnt[i][x];
                cnt[i][x]-=cnt[i][x];
            }
            seg[i][get2(y)]+=yadd;
            seg[i][get2(x)]+=xadd;
            pre[i][y]+=yadd;
            pre[i][x]+=xadd;
        }
        for (;i<bk;++i) {
            seg[i][get2(y)]+=yadd;
            seg[i][get2(x)]+=xadd;
            pre[i][y]+=yadd;
            pre[i][x]+=xadd;
        }
    }
}

inline int query(int l,int r,int k) {
    // cout<<"QUERY: "<<l<<" "<<r<<" "<<k<<endl;
    if (get(l)==get(r)) {
        for (int i=l;i<=r;++i) {
            bkt[arr[i]=arr[find(i)]]++;
            asi[get2(arr[i])]++;
            // printf("bkt[%d] = %d, asi[%d] = %d\n",arr[find(i)],bkt[arr[find(i)]],get2(arr[find(i)]),asi[get2(arr[find(i)])]);
        }
        int sum=0;
        int blk;
        for (blk=0;blk<bk2;++blk) {
            if (sum+asi[blk]<k) {
                sum+=asi[blk];
            } else {
                break;
            }
        }
        for (int i=getl2(blk);i<=getr2(blk);++i) {
            if (sum+bkt[i]<k) {
                sum+=bkt[i];
            } else {
                for (int j=l;j<=r;++j) { // reset
                    bkt[arr[j]]--;
                    asi[get2(arr[j])]--;
                }
                return i;
            }
        }
    } else {
        // cout<<l<<" "<<get(l)<<" "<<getr(get(l))<<endl;
        for (int i=l;i<=getr(get(l));++i) {
            bkt[arr[i]=arr[find(i)]]++;
            asi[get2(arr[i])]++;
            // printf("L: bkt[%d] = %d, asi[%d] = %d\n",arr[find(i)],bkt[arr[find(i)]],get2(arr[find(i)]),asi[get2(arr[find(i)])]);
        }
        for (int i=getl(get(r));i<=r;++i) {
            bkt[arr[i]=arr[find(i)]]++;
            asi[get2(arr[i])]++;
            // printf("R: bkt[%d] = %d, asi[%d] = %d\n",arr[find(i)],bkt[arr[find(i)]],get2(arr[find(i)]),asi[get2(arr[find(i)])]);
        }
        int sum=0;
        int blk;
        for (blk=0;blk<bk2;++blk) {
            if (sum+seg[get(r)-1][blk]-seg[get(l)][blk]+asi[blk]<k) {
                sum+=seg[get(r)-1][blk]-seg[get(l)][blk]+asi[blk];
            } else {
                break;
            }
        }
        for (int i=getl2(blk);i<=getr2(blk);++i) {
            if (sum+pre[get(r)-1][i]-pre[get(l)][i]+bkt[i]<k) {
                sum+=pre[get(r)-1][i]-pre[get(l)][i]+bkt[i];
            } else {
                for (int j=l;j<=getr(get(l));++j) { // reset
                    bkt[arr[j]]--;
                    asi[get2(arr[j])]--;
                }
                for (int j=getl(get(r));j<=r;++j) { // reset
                    bkt[arr[j]]--;
                    asi[get2(arr[j])]--;
                }
                return i;
            }
        }
    }
    assert(false);
    return -114514;
}

int main() {
    read(n); read(m);
    len=sqrt(n); bk=n/len; if (n%len) bk++;
    len2=sqrt(N); bk2=N/len2; if (N%len2) bk2++;
    for (int i=1;i<=n;++i) {
        read(arr[i]);
    }
    init();
    while (m--) {
        int op,l,r;
        read(op); read(l); read(r);
        if (op==1) {
            int x,y;
            read(x); read(y);
            modify(l,r,x,y);
        } else {
            int k;
            read(k);
            int ans=query(l,r,k);
            printf("%d\n",ans);
        }
    }
    return 0;
}

/*
cnt[i][j] 第 i 块 j 出现次数
pre[i][j] 前 i 块 j 出现次数
seg[i][j] 前 i 块值域第 j 块出现次数
*/