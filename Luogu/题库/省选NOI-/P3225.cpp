#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=1005;

int n,m,s,t;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
bool cut[N];
int dcc,root;
stack<int> stk;
vector<int> dcc_nodes[N];
int ans1;
unsigned long long ans2;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts; // 时间戳
    stk.push(u); // 入栈
    if (u==root && h[u]==-1) { // 单独一个根节点，没有其他节点
        dcc++; // 仍然是一个 dcc
        dcc_nodes[dcc].push_back(u);
        return;
    }
    int cnt=0; // u 可能是几个 dcc 的割点
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) { // 还没搜过
            tarjan(e[i]); // 搜索
            low[u]=min(low[u],low[e[i]]); // 更新 low
            if (dfn[u]<=low[e[i]]) { // u 可能是割点
                cnt++;
                // 根节点需要两个子节点以上，才是割点
                // 非根节点，则此时已经是割点
                if (u!=root || cnt>=2) {
                    cut[u]=true; // 标记
                }
                dcc++; // dcc 数量增加
                int k;
                do { // 出栈，把 dcc 除 u 外的所有节点标记并弹出
                    k=stk.top();
                    stk.pop();
                    dcc_nodes[dcc].push_back(k);
                } while (k!=e[i]); // u 同时属于至少两个 dcc 的割点，所以暂时不弹出
                dcc_nodes[dcc].push_back(u); // 虽不弹出，但 u 还是属于 dcc 的一者
            }
        } else {
            low[u]=min(low[u],dfn[e[i]]); // 搜过了，更新 low
        }
    }
}

int main() {
    int test_case=0;
    while (++test_case) {
        scanf("%d",&m);
        if (!m) break;
        for (int i=1;i<=dcc;++i) dcc_nodes[i].clear(); // 这句清空要写在初始化 dcc 的上面
        n=dcc=ts=tot=0; // 初始化 dcc 的时候要放在上面那一句的下面
        memset(h,-1,sizeof(h));
        memset(dfn,0,sizeof(dfn));
        memset(cut,0,sizeof(cut));
        ans1=0,ans2=1ULL; // ans2 是不同方案的个数，排列组合由乘法计算，初始是 1
        while (!stk.empty()) stk.pop(); // 清空栈
        while (m--) {
            scanf("%d %d",&s,&t);
            add(s,t); add(t,s);
            n=max(n,max(s,t)); // 题目未给出 n，需要自己计算
        }
        for (root=1;root<=n;++root) { // 枚举根节点
            if (!dfn[root]) { // 没搜过
                tarjan(root); // 搜索
            }
        }
        for (int i=1;i<=dcc;++i) { // 枚举每一个 dcc
            int cut_dots=0; // 割点个数
            for (int u:dcc_nodes[i]) { // 枚举 dcc 中每一个点
                if (cut[u]) { // 如果是割点
                    cut_dots++; // 割点个数 +1
                }
            }
            if (cut_dots==0) { // 没有割点
                if (dcc_nodes[i].size()==1) { // 如果 dcc 只有一个节点
                    ++ans1; // 只需放置一个
                } else { // 多个节点
                    ans1+=2; // 放置两个，防止另外一个出口损坏
                    ans2*=dcc_nodes[i].size()*(dcc_nodes[i].size()-1)/2; // dcc 的节点个数中任选两个的组合
                }
            } else if (cut_dots==1) { // 割点是一个
                // 在非割点的位置放置一个出口
                // 若割点损坏，则有出口可使用
                // 若出口损坏，则可通过割点到达别的 dcc
                ++ans1;
                ans2*=dcc_nodes[i].size()-1; // 不能放割点，所以是节点数量 -1 中取一个的组合
            }
        }
        printf("Case %d: ",test_case);
        printf("%d %llu",ans1,ans2);
        putchar(10);
    }
    return 0;
}