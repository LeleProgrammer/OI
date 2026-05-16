#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<i64> X(n+1), Y(n+1);
    map<pii, vector<int>> t;
    
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
        i64 g = gcd(abs(X[i]), abs(Y[i]));
        i64 dx = X[i]/g;
        i64 dy = Y[i]/g;
        // 确保唯一表示：让方向向量指向第一或第二象限，或者x正半轴
        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }
        pii dir = {dx, dy};
        t[dir].push_back(i);
    }
    
    vector<pair<pii, int>> vec;
    for (auto &[dir, ids] : t) {
        vec.emplace_back(dir, ids.size());
    }
    
    int m = vec.size();
    // 按逆时针排序
    sort(vec.begin(), vec.end(), [&](const auto &a, const auto &b) {
        auto [x1, y1] = a.first;
        auto [x2, y2] = b.first;
        // 上半平面(含x正轴)优先
        bool half1 = (y1 > 0) || (y1 == 0 && x1 > 0);
        bool half2 = (y2 > 0) || (y2 == 0 && x2 > 0);
        if (half1 != half2) return half1 > half2;
        // 叉积判断逆时针
        return x1 * y2 - y1 * x2 > 0;
    });
    
    map<pii, int> w;
    for (int i = 0; i < m; i++) {
        w[vec[i].first] = i;
    }
    
    vector<int> monsterGroup(n+1);
    for (int i = 1; i <= n; i++) {
        i64 g = __gcd(abs(X[i]), abs(Y[i]));
        i64 dx = X[i]/g;
        i64 dy = Y[i]/g;
        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }
        pii dir = {dx, dy};
        monsterGroup[i] = w[dir];
    }
    
    vector<i64> pre(m+1, 0);
    for (int i = 0; i < m; i++) {
        pre[i+1] = pre[i] + vec[i].second;
    }
    i64 total = pre[m];
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        int ga = monsterGroup[a];
        int gb = monsterGroup[b];
        
        if (ga == gb) {
            cout << vec[ga].second << "\n";
        } else {
            i64 ans;
            if (ga < gb) {
                ans = pre[gb+1] - pre[ga];
            } else {
                ans = (total - pre[ga]) + pre[gb+1];
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}