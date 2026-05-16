#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<ll> fac, invfac;
void init_fac(int n) {
    fac.resize(n + 1); invfac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % MOD;
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n-1; i >= 0; i--) invfac[i] = invfac[i+1] * (i+1) % MOD;
}
ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * invfac[m] % MOD * invfac[n-m] % MOD;
}

// 小段：直接用 DP
vector<ll> calc_small(int L) {
    vector<ll> f(L+1);
    for (int k = 0; k <= L; k++) {
        vector<ll> dp(L+1), pre(L+2);
        dp[0] = 1; pre[0] = 1;
        for (int i = 1; i <= L; i++) {
            dp[i] = pre[i-1];
            if (i - k - 1 >= 1)
                dp[i] = (dp[i] - pre[i-k-2] + MOD) % MOD;
            if (i <= k)
                dp[i] = (dp[i] + 1) % MOD;
            pre[i] = (pre[i-1] + dp[i]) % MOD;
        }
        f[k] = dp[L];
    }
    return f;
}

// 大段：用组合数公式
vector<ll> calc_large(int L, int N) {
    vector<ll> f(N+1);
    vector<ll> pow2(N+1);
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) pow2[i] = pow2[i-1] * 2 % MOD;
    
    for (int k = 0; k <= N; k++) {
        if (k >= L) {
            f[k] = pow2[L];
        } else {
            ll res = 0;
            int lim = (L + 1) / (k + 1);
            for (int j = 0; j <= lim; j++) {
                ll term = C(L + 1, j) * pow2[L - j*(k+1)] % MOD;
                if (j & 1) res = (res - term + MOD) % MOD;
                else res = (res + term) % MOD;
            }
            f[k] = res;
        }
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; string S;
    cin >> N >> S;
    init_fac(N + 1);
    
    map<int, int> cnt;
    int cur = 0;
    for (char c : S) {
        if (c == '.') cur++;
        else { if (cur) cnt[cur]++; cur = 0; }
    }
    if (cur) cnt[cur]++;
    
    const int B = 450;  // sqrt(200000)
    
    vector<ll> global_cdf(N+1, 1);
    
    for (auto &[L, c] : cnt) {
        vector<ll> f;
        if (L <= B) {
            f = calc_small(L);
            f.resize(N+1);
            for (int k = L+1; k <= N; k++) f[k] = f[L];
        } else {
            f = calc_large(L, N);
        }
        
        for (int k = 0; k <= N; k++) {
            global_cdf[k] = global_cdf[k] * qpow(f[k], c) % MOD;
        }
    }
    
    for (int k = 1; k <= N; k++) {
        ll ans = (global_cdf[k] - global_cdf[k-1] + MOD) % MOD;
        cout << ans << '\n';
    }
    
    return 0;
}