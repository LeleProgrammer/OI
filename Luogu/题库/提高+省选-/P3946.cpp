#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

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

const int N=1000005;
const int M=2000005;
const int inf=9e18;

int n,m,s,t,g,Q;
int e[M],ne[M],w[M],h[N],tot;
priority_queue<pii,vector<pii>,greater<pii>> q;
int dis[N],flag[N];

struct node {
	int h,l;
} arr[N];

void add(int a,int b,int c) {
	e[tot]=b,ne[tot]=h[a],w[tot]=c,h[a]=tot++;
}

void dijkstra() {
	_rep(i,1,n) dis[i]=inf,flag[i]=0;
	q.push({dis[s]=0,s});
	while (!q.empty()) {
		auto tp=q.top(); q.pop();
		int u=tp.second;
		if (flag[u]) continue;
		_graph(i,u) if ((arr[e[i]].h+Q*(dis[u]+w[i])<=arr[e[i]].l || e[i]==t) && dis[e[i]]>dis[u]+w[i] && !flag[e[i]]) q.push({dis[e[i]]=dis[u]+w[i],e[i]});
	}
}

signed main() {
	memset(h,-1,sizeof(h));
	read(n); read(m); read(s); read(t); read(g); read(Q);
	_rep(i,1,n) read(arr[i].h),read(arr[i].l);
	while (m--) {
		int a,b,c;
		read(a),read(b),read(c);
		add(a,b,c); add(b,a,c);
	}
	dijkstra();
//	_rep(i,1,n) printf("dis[%lld] = %lld\n",i,dis[i]);
	if (dis[t]>g) puts("wtnap wa kotori no oyatsu desu!");
	else printf("%lld",dis[t]);
	return 0;
}