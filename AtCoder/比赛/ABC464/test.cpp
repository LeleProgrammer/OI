#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll mod_pow(ll a, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll total_mod = total % MOD;
    
    int nL = N / 2;
    int nR = N - nL;
    
    vector<pair<ll, int>> L;
    for (int mask = 0; mask < (1 << nL); ++mask) {
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < nL; ++i) {
            if (mask >> i & 1) {
                sum += A[i];
                cnt++;
            }
        }
        L.emplace_back(sum, cnt);
    }
    
    vector<pair<ll, int>> R;
    for (int mask = 0; mask < (1 << nR); ++mask) {
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < nR; ++i) {
            if (mask >> i & 1) {
                sum += A[nL + i];
                cnt++;
            }
        }
        R.emplace_back(sum, cnt);
    }
    
    sort(L.begin(), L.end(), [](auto &a, auto &b) { return a.first > b.first; });
    sort(R.begin(), R.end(), [](auto &a, auto &b) { return a.first < b.first; });
    
    // F[k]: 和为 < X 的大小为 k 的子集个数
    // G[k]: 这些子集的元素和之和
    vector<ll> F(N + 1, 0), G(N + 1, 0);
    
    // cnt[sz]: 当前符合条件的右子集中大小为 sz 的个数
    // sum_val[sz]: 这些子集的总和之和
    vector<ll> cnt(nR + 1, 0), sum_val(nR + 1, 0);
    int j = -1;
    int m = R.size();
    
    for (auto &[sumL, szL] : L) {
        ll limit = X - sumL;
        while (j + 1 < m && R[j + 1].first < limit) {
            ++j;
            int szR = R[j].second;
            ll val = R[j].first % MOD;
            cnt[szR] = (cnt[szR] + 1) % MOD;
            sum_val[szR] = (sum_val[szR] + val) % MOD;
        }
        ll sumL_mod = sumL % MOD;
        for (int szR = 0; szR <= nR; ++szR) {
            if (cnt[szR] == 0) continue;
            int k = szL + szR;
            F[k] = (F[k] + cnt[szR]) % MOD;
            G[k] = (G[k] + sumL_mod * cnt[szR] + sum_val[szR]) % MOD;
        }
    }
    
    vector<ll> fact(N + 1, 1), inv_fact(N + 1, 1);
    for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[N] = mod_pow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    
    ll ans = 0;
    for (int k = 0; k <= N - 1; ++k) {
        ll term = (total_mod * F[k] % MOD - G[k] + MOD) % MOD;
        term = term * fact[k] % MOD * fact[N - 1 - k] % MOD;
        ans = (ans + term) % MOD;
    }
    ans = ans * inv_fact[N] % MOD;
    
    cout << ans << endl;
    return 0;
}