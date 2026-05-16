#include <bits/stdc++.h>
using namespace std;

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

const int N=500005;

int n,a[N];
priority_queue<int,vector<int>,greater<int>> q,w;

int main() {
    scanf("%d",&n);
    _rep(i,1,n) scanf("%d",&a[i]);
    _rep(i,1,n) {
        if (!w.empty()) {
            while (!q.empty() && q.top()<w.top()) {
                q.push(w.top());
                w.pop();
                w.push(q.top());
                q.pop();
            }
            // cout<<i<<" "<<a[i]<<" "<<w.top()<<" "<<w.size()<<" "<<q.size()<<endl;
            if (w.top()<=a[i]/2) {
                w.pop();
                q.push(a[i]);
            } else w.push(a[i]);
        } else {
            w.push(a[i]);
        }
        // cout<<i<<": "<<w.size()<<" "<<q.size()<<endl;
    }
    // printf("TEST: "); while (!q.empty()) printf("%d ",q.top()),q.pop(); putchar(10);
    printf("%d",q.size());
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10

6
2 4 7 8 10 14

ans: 3
*/