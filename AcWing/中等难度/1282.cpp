#include <bits/stdc++.h>
using namespace std;

const int N=10005; // N 个单词
const int M=1000005; // 文章长度是 M
const int L=55; // 单词长度 L

int T,n,m;
int tr[N*L][26]; // trie
int cnt[N*L]; // 结束点有几个单词
int ne[N*L]; // next 数组
char str[L]; // 输入单词
char com[M]; // 输入文章
int tot; // 节点总数
queue<int> q; // 队列

void insert(char str[]) { // trie 插入
    int p=0;
    for (int i=0;str[i];++i) {
        int curr=str[i]-'a';
        if (!tr[p][curr]) tr[p][curr]=++tot;
        p=tr[p][curr];
    }
    cnt[p]++;
}

void build() { // AC 自动机 构建
    for (int i=0;i<26;++i) {
        if (tr[0][i]) q.push(tr[0][i]); // 根节点有连接的点都插入队列
    }
    while (!q.empty()) { // bfs
        /*
        curr: 当前下标
        tr[curr][i]: 添加了一个字符后的下标
        ne[curr]: 当前位置的 next
        ne[tr[curr][i]]: 添加了字符后的 next
        */
        int curr=q.front(); // 取队首
        q.pop();
        for (int i=0;i<26;++i) { // 26 个字母
            // 没有下一个符合条件的节点，指向 next 的位置
            if (!tr[curr][i]) tr[curr][i]=tr[ne[curr]][i];
            else {
                // 有符合条件的节点
                // 下一个节点的 next 也要更新
                ne[tr[curr][i]]=tr[ne[curr]][i];
                // 入队
                q.push(tr[curr][i]);
            }
        }
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        memset(ne,0,sizeof(ne));
        tot=0;
        scanf("%d",&n);
        while (n--) {
            scanf("%s",str);
            insert(str);
        }
        build(); // 构建 AC 自动机
        scanf("%s",com);
        int ans=0; // 结果
        int p=0; // trie 指针
        for (int i=0;com[i];++i) { // 枚举文章的字符
            int q=com[i]-'a'; // 取字符
            p=tr[p][q]; // 往下一个地方走
            for (int curr=p;curr;curr=ne[curr]) {
                // 沿途在 next 中不断往回搜，直到达到根节点
                // 一路上计算出现的单词数量
                // 这道题重复只计算一次
                // 所以查过就把 cnt 对应位置重置
                ans+=cnt[curr];
                cnt[curr]=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}