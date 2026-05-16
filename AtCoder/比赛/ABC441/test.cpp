#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> V[i];
    }
    
    // 全局最优解
    vector<long long> global_dp(M + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int w = M; w >= P[i]; w--) {
            global_dp[w] = max(global_dp[w], global_dp[w - P[i]] + V[i]);
        }
    }
    long long global_best = global_dp[M];
    
    string ans(N, ' ');
    
    // 对每个物品i，计算去掉它后的最优解
    for (int i = 0; i < N; i++) {
        vector<long long> dp_without(M + 1, 0);
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            for (int w = M; w >= P[j]; w--) {
                dp_without[w] = max(dp_without[w], dp_without[w - P[j]] + V[j]);
            }
        }
        
        long long best_without_i = dp_without[M];
        
        if (best_without_i < global_best) {
            // 必须选i才能达到全局最优
            ans[i] = 'A';
        } else {
            // 不选i也能达到全局最优，检查是否存在包含i的最优解
            long long best_with_i = (M >= P[i]) ? V[i] + dp_without[M - P[i]] : 0;
            if (best_with_i == global_best) {
                // 存在包含i的最优解
                ans[i] = 'B';
            } else {
                // 所有最优解都不包含i
                ans[i] = 'C';
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}