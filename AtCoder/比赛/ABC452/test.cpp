#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int INF = 1e9;

// 后缀自动机
struct SAM {
    struct State {
        int len;      // 最长子串长度
        int link;     // 后缀链接（parent tree 父节点）
        int next[10]; // 转移边（字符 1-9，用 1-9 索引）
    } st[MAXN * 2];
    
    int sz;           // 状态总数
    int last;         // 当前最后添加的状态
    
    // 每个位置对应的 SAM 状态
    int posState[MAXN];
    
    void init() {
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, 0, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }
    
    void extend(int c, int pos) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        memset(st[cur].next, 0, sizeof(st[cur].next));
        
        int p = last;
        while (p != -1 && !st[p].next[c]) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
        posState[pos] = cur;
    }
    
    // 按 len 降序获取所有状态（用于拓扑排序）
    vector<int> getOrder() {
        vector<int> order(sz);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return st[a].len > st[b].len;
        });
        return order;
    }
} sam;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    string s;
    cin >> s;
    
    // 构建 SAM
    sam.init();
    for (int i = 0; i < N; i++) {
        int c = s[i] - '0';
        sam.extend(c, i + 1);  // 位置从 1 开始
    }
    
    // 读取查询，按右端点分组
    vector<vector<int>> queries_by_r(N + 2);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        queries_by_r[r].push_back(l);
    }
    
    // 扫描法求 minL 和 maxLen
    vector<int> minL(N + 2, INF);
    vector<int> maxLen(N + 2, 0);
    
    int nowMinL = INF;
    for (int p = N; p >= 1; p--) {
        // 加入所有右端点为 p 的查询
        for (int l : queries_by_r[p]) {
            nowMinL = min(nowMinL, l);
        }
        minL[p] = nowMinL;
        
        // 计算 maxLen
        if (minL[p] <= p) {
            maxLen[p] = p - minL[p] + 1;
        } else {
            maxLen[p] = 0;
        }
    }
    
    // 初始化每个状态的 maxCoverLen
    vector<int> maxCoverLen(sam.sz, 0);
    for (int p = 1; p <= N; p++) {
        int v = sam.posState[p];
        maxCoverLen[v] = max(maxCoverLen[v], maxLen[p]);
    }
    
    // 在 parent tree 上向上传递最大值
    vector<int> order = sam.getOrder();
    for (int v : order) {
        if (v == 0) continue;  // 根节点没有父节点
        int parent = sam.st[v].link;
        maxCoverLen[parent] = max(maxCoverLen[parent], maxCoverLen[v]);
    }
    
    // 计算答案
    long long ans = 0;
    for (int v = 1; v < sam.sz; v++) {  // 跳过根状态 0
        int minLenInV = sam.st[sam.st[v].link].len + 1;
        int maxLenInV = sam.st[v].len;
        int coverLen = min(maxLenInV, maxCoverLen[v]);
        
        if (coverLen >= minLenInV) {
            ans += coverLen - minLenInV + 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}

/*
10 4
2 3 1 3 1 2 1 9 1 4
1 3
3 6
6 7
9 10
*/