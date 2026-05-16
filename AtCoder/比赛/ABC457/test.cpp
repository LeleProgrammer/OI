#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> D(N + 1);
    for (int i = 1; i <= N - 1; ++i) cin >> D[i];
    
    if (D[N - 1] != 1) {
        cout << 0 << '\n';
        return 0;
    }
    
    // 逆元预处理
    vector<ll> inv(N + 1);
    inv[1] = 1;
    for (int i = 2; i <= N; ++i)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    
    vector<ll> f(N + 2, 0);
    vector<int> active;
    
    // 初始状态：i = N-1 的两种选择
    f[N - 1] = 1;
    f[N] = 1;
    active = {N - 1, N};
    ll mul = 1;
    int cur_d = 1;
    
    for (int i = N - 2; i >= 1; --i) {
        int C = N - i - 1;          // C >= 1
        if (D[i] == cur_d) {
            int sp = i + cur_d;
            if (f[sp] != 0) {
                ll val = f[sp];
                if (f[i] == 0) active.push_back(i);
                f[i] = (f[i] + val * inv[C]) % MOD;
                f[sp] = val * (C + 1) % MOD * inv[C] % MOD;
            }
            mul = mul * C % MOD;
        } else {
            // 强制边界，必须 A 或 B
            vector<ll> new_f(N + 2, 0);
            vector<int> new_act;
            int req = i + D[i];
            for (int p : active) {
                ll rp = f[p] * mul % MOD;
                if (p == req) {
                    if (new_f[i] == 0) new_act.push_back(i);
                    new_f[i] = (new_f[i] + rp) % MOD;
                    if (new_f[p] == 0) new_act.push_back(p);
                    new_f[p] = (new_f[p] + rp) % MOD;
                }
            }
            if (new_act.empty()) {
                cout << 0 << '\n';
                return 0;
            }
            // 清空旧状态
            for (int p : active) f[p] = 0;
            f = move(new_f);
            active = move(new_act);
            mul = 1;
            cur_d = D[i];
        }
    }
    
    ll ans = 0;
    for (int p : active) ans = (ans + f[p] * mul) % MOD;
    cout << ans << '\n';
    
    return 0;
}