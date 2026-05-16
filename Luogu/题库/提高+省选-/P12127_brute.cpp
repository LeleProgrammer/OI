#include <bits/stdc++.h>
using namespace std;

namespace z {

#define int long long
const int N = 1e5 + 5;
int a[N], b[N], n, ans = 1, vis[N];
struct SGT {
    #define lc (p<<1)
    #define rc (p<<1|1)
    #define mid ((l+r)>>1)
    int t[N << 2], mx[N << 2];
    void clear() { memset(t, 0, sizeof t), memset(mx, -0x3f, sizeof mx); }
    void pd(int p) {
        if(t[p]) {
            mx[lc] += t[p], mx[rc] += t[p];
            t[lc] += t[p], t[rc] += t[p];
            t[p] = 0;
        }
    }
    void pu(int p) { mx[p] = max(mx[lc], mx[rc]); }
    void upd(int p, int l, int r, int L, int R, int v) {
        if(l >= L && r <= R) {
            t[p] += v, mx[p] += v;
            return;
        }
        pd(p);
        if(mid >= L) upd(lc, l, mid, L, R, v);
        if(mid < R) upd(rc, mid + 1, r, L, R, v);
        pu(p);
    }
    int query(int p, int l, int r, int L, int R) {
        if(l >= L && r <= R) return mx[p];
        pd(p);
        int res = -0x3f3f3f3f3f3f3f3f;
        if(mid >= L) res = max(res, query(lc, l, mid, L, R));
        if(mid < R) res = max(res, query(rc, mid + 1, r, L, R));
        return res;
    }
} sgt;
void main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1); auto ed = unique(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, ed, a[i]) - b;
    sgt.clear();
    for(int i = 1; i <= n; i++) {
        int x = sgt.query(1, 1, n, 1, a[i]);
        ans = max(ans, x + 2);
        if(!vis[a[i]]) {
            vis[a[i]] = 1;
            sgt.upd(1, 1, n, a[i], a[i], -sgt.query(1, 1, n, a[i], a[i]));
        }
        sgt.upd(1, 1, n, a[i] + 1, n, 1);
    }
    memcpy(b, a, sizeof a);
    memset(vis, 0, sizeof vis);
    sgt.clear();
    for(int i = 1; i <= n; i++) a[i] = b[n - i + 1];
    for(int i = 1; i <= n; i++) {
        int x = sgt.query(1, 1, n, 1, a[i]);
        ans = max(ans, x + 2);
        if(!vis[a[i]]) {
            vis[a[i]] = 1;
            sgt.upd(1, 1, n, a[i], a[i], -sgt.query(1, 1, n, a[i], a[i]));
        }
        sgt.upd(1, 1, n, a[i] + 1, n, 1);
    }
    cout << ans << '\n';
}

#undef int

}


int main()
{   
    freopen("P12127.in","r",stdin);
    freopen("P12127_ac.out","w",stdout);
    z::main();
    return 0;
}