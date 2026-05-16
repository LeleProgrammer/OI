#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct AhoCorasick {
    struct Node {
        map<char, int> next;
        int fail = -1;
        int output = 0;
    };
    vector<Node> nodes;
    int root = 0;

    AhoCorasick() {
        nodes.emplace_back();
    }

    void insert(const string &s, int id) {
        int cur = root;
        for (char c : s) {
            if (nodes[cur].next.find(c) == nodes[cur].next.end()) {
                nodes[cur].next[c] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].next[c];
        }
        nodes[cur].output |= (1 << id);
    }

    void build() {
        queue<int> q;
        q.push(root);
        nodes[root].fail = root;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &p : nodes[cur].next) {
                char c = p.first;
                int next = p.second;
                if (cur == root) {
                    nodes[next].fail = root;
                } else {
                    int f = nodes[cur].fail;
                    while (f != root && nodes[f].next.find(c) == nodes[f].next.end()) {
                        f = nodes[f].fail;
                    }
                    if (nodes[f].next.find(c) != nodes[f].next.end()) {
                        f = nodes[f].next[c];
                    }
                    nodes[next].fail = f;
                }
                nodes[next].output |= nodes[nodes[next].fail].output;
                q.push(next);
            }
        }
    }

    int go(int state, char c) {
        while (state != root && nodes[state].next.find(c) == nodes[state].next.end()) {
            state = nodes[state].fail;
        }
        if (nodes[state].next.find(c) != nodes[state].next.end()) {
            state = nodes[state].next[c];
        }
        return state;
    }
};

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    AhoCorasick ac;
    for (int i = 0; i < N; ++i) {
        ac.insert(S[i], i);
    }
    ac.build();

    int total_mask = (1 << N) - 1;
    vector<vector<vector<int>>> dp(L + 1, vector<vector<int>>(ac.nodes.size(), vector<int>(1 << N, 0)));
    dp[0][ac.root][0] = 1;

    for (int l = 0; l < L; ++l) {
        for (int state = 0; state < ac.nodes.size(); ++state) {
            for (int mask = 0; mask <= total_mask; ++mask) {
                if (dp[l][state][mask] == 0) continue;
                for (char c = 'a'; c <= 'z'; ++c) {
                    int new_state = ac.go(state, c);
                    int new_mask = mask | ac.nodes[new_state].output;
                    dp[l + 1][new_state][new_mask] = (dp[l + 1][new_state][new_mask] + dp[l][state][mask]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int state = 0; state < ac.nodes.size(); ++state) {
        ans = (ans + dp[L][state][total_mask]) % MOD;
    }
    cout << ans << endl;

    return 0;
}