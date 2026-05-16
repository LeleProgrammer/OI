#include <bits/stdc++.h>
using namespace std;

const int MAXINPUTN=300005;
const int MAXN=MAXINPUTN*2;
const int MAXM=MAXN*32;

int n,m;
int pre[MAXN]; // 异或前缀和数组
int tr[MAXM][2]; // trie字典树数组
int maxx[MAXM]; // 存字典树里面一个节点的最后一次出现的位置，如果左界大于这个位置，那么就没有这个节点了
int roots[MAXN]; // 存每一个版本的根节点编号
int tot; // 节点数量
char op[2]; // 命令
int l,r,x; // 命令的参数

// 插入节点
// now: 插入的节点是第几个节点
// pos: 从高位到低位查找，查到了第几位，0 是二进制个位
// last: 当前的节点的在上一版本中的编号，无则是 0
// node: 当前节点的编号
void insert(int now,int pos,int last,int node) {
    // 查到 -1 位了，整个数字已经添加进去，叶子节点，所以最终出现位置是 now
    if (pos==-1) maxx[node]=now;
    else {
        int digit=(pre[now]>>pos)&1; // 获取数位
        // digit^1 表示非当前数位的那个子节点，
        // 插入的时候不会走过去，
        // 如果有上一版本的话，就把这个节点复制过来，
        // 而 digit 是要往下搜的，不能直接复制，要创建一份
        if (last) tr[node][digit^1]=tr[last][digit^1];
        // 创建节点，指向 digit
        tr[node][digit]=++tot;
        // 递归，上一版本便是创建的节点对应的上一版本
        insert(now,pos-1,tr[last][digit],tr[node][digit]);
        // 左界限制是更大的，如果是更小的那个，更大的不符合条件
        maxx[node]=max(maxx[tr[node][0]],maxx[tr[node][1]]);
    }
}

// 查询
// root: 当前版本，即版本的右界
// left: 左界，即版本的左界
int query(int root,int left,int res) {
    int p=root; // 指针指向根节点
    // 保险一点，开到 30 位二进制数
    for (int i=30;i>=0;--i) {
        int digit=(res>>i)&1; // 获取数位
        // 贪心的思路，1 则选 0，0 则选 1，无法选最优则选次优
        // 无法选的意思就是超过左界限制范围
        if (left<=maxx[tr[p][digit^1]]) p=tr[p][digit^1]; // 异则最优
        else p=tr[p][digit]; // 无法异则选择同
    }
    res^=pre[maxx[p]]; // ????
    return res;
}

int main() {
    scanf("%d %d",&n,&m);
    // 第 0 个版本，啥也没有
    maxx[0]=-0x3f3f3f3f;
    roots[0]=++tot;
    insert(0,30,0,roots[0]);
    for (int i=1;i<=n;++i) {
        scanf("%d",&pre[i]);
        pre[i]^=pre[i-1]; // 构建异或前缀和数组
        roots[i]=++tot; // 每添加一个数，都成为一个新的版本
        insert(i,30,roots[i-1],roots[i]); // 新的版本就要进行插入操作
    }
    while (m--) {
        scanf("%s",op);
        if (op[0]=='A') {
            scanf("%d",&x);
            // 新的版本，先添加一个根节点
            roots[++n]=++tot;
            // 更新异或前缀和数组
            pre[n]=pre[n-1]^x;
            // 新的版本中也应该添加新的节点
            insert(n,30,roots[n-1],roots[n]);
        } else {
            scanf("%d %d %d",&l,&r,&x);
            // 异或前缀和数组快速求区间 [a,b] 异或值
            // pre[a-1]^pre[b]
            // ????
            printf("%d\n",query(roots[r-1],l-1,x^pre[n]));
        }
    }
    return 0;
}