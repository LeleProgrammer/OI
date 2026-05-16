#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_BITS = 30;

// 线性基类
struct LinearBasis {
    int basis[MAX_BITS];
    
    LinearBasis() {
        memset(basis, 0, sizeof(basis));
    }
    
    // 插入一个数
    void insert(int x) {
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            if (!(x >> i & 1)) continue;
            if (basis[i]) {
                x ^= basis[i];
            } else {
                basis[i] = x;
                return;
            }
        }
    }
    
    // 将一个数用线性基最小化
    int minimize(int x) {
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            if ((x >> i & 1) && basis[i]) {
                x ^= basis[i];
            }
        }
        return x;
    }
    
    // 获取所有基的mask
    int getMask() {
        int mask = 0;
        for (int i = 0; i < MAX_BITS; i++) {
            if (basis[i]) mask |= (1 << i);
        }
        return mask;
    }
    
    // 压缩空间：将每个数映射到其最小表示
    int compress(int x) {
        return minimize(x);
    }
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<pair<int, int>>> g(N + 1);
    vector<tuple<int, int, int>> edges(M);
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    // Step 1: BFS构建生成树，计算dist数组
    vector<int> dist(N + 1, -1);
    vector<int> parent(N + 1, -1);
    vector<int> parentEdgeId(N + 1, -1);
    
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    
    // 标记树边
    vector<bool> isTreeEdge(M, false);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto [v, w] : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] ^ w;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    // 标记树边：对于每条边，检查它是否连接父子节点
    for (int i = 0; i < M; i++) {
        auto [u, v, w] = edges[i];
        if ((parent[v] == u && dist[v] == (dist[u] ^ w)) ||
            (parent[u] == v && dist[u] == (dist[v] ^ w))) {
            isTreeEdge[i] = true;
        }
    }
    
    // Step 2: 构建环的线性基
    LinearBasis lb;
    for (int i = 0; i < M; i++) {
        if (!isTreeEdge[i]) {
            auto [u, v, w] = edges[i];
            int cycleXor = dist[u] ^ dist[v] ^ w;
            lb.insert(cycleXor);
        }
    }
    
    // Step 3: 计算每个节点的压缩值
    vector<int> compressed(N + 1);
    for (int i = 1; i <= N; i++) {
        compressed[i] = lb.minimize(dist[i]);
    }
    
    // Step 4: 用Trie统计答案
    // 由于压缩后值域是0..2^30-1，但实际可能更小
    // 使用字典树统计XOR ≤ K的对数
    
    struct TrieNode {
        TrieNode* child[2];
        int cnt;
        TrieNode() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };
    
    TrieNode* root = new TrieNode();
    
    auto insert = [&](int x) {
        TrieNode* cur = root;
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit]) {
                cur->child[bit] = new TrieNode();
            }
            cur = cur->child[bit];
            cur->cnt++;
        }
    };
    
    auto query = [&](int x) -> int {
        // 查询有多少已插入的数y满足 x XOR y ≤ K
        TrieNode* cur = root;
        int res = 0;
        
        for (int i = MAX_BITS - 1; i >= 0 && cur; i--) {
            int xb = (x >> i) & 1;
            int kb = (K >> i) & 1;
            
            if (kb == 1) {
                // 如果K的这一位是1，那么XOR的这一位可以是0或1
                // 先统计XOR这一位为0的情况（此时一定小于K）
                if (cur->child[xb]) {
                    res += cur->child[xb]->cnt;
                }
                // 然后继续走XOR这一位为1的路径
                cur = cur->child[xb ^ 1];
            } else {
                // 如果K的这一位是0，XOR的这一位必须也是0
                cur = cur->child[xb];
            }
        }
        
        // 如果完整遍历完，说明所有位的XOR都等于K，也要计入
        if (cur) {
            res += cur->cnt;
        }
        
        return res;
    };
    
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += query(compressed[i]);
        insert(compressed[i]);
    }
    
    cout << ans << "\n";
    
    // 清理内存（可选，由于总N有限，可以省略）
    // 这里为了简洁省略了内存释放
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}