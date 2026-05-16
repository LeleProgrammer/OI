#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=100005;

int n1,n2,m;
int e[M],ne[M],h[N],tot;
bool sta[N]; // 右边的节点是否被搜过
int mat[N]; // 右边的点匹配的左边的点是谁

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool loc(int curr) {
    for (int i=h[curr];~i;i=ne[i]) { // 枚举每一条边
        if (!sta[e[i]]) { // 还没搜过才搜，也就是右边的节点还未确定匹配的左边的节点是谁的情况下，不然会死循环
            sta[e[i]]=true; // 能匹配就直接匹配
            if (mat[e[i]]==0 || loc(mat[e[i]])) { // 右边的节点还没有匹配的左节点，或是右边的节点匹配的左边的节点能够匹配新的右节点，就可以进行
                mat[e[i]]=curr; // 匹配
                return true;
            }
        }
    }
    return false; // 所有可能的边都搜过了还不能完成匹配
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&n1,&n2,&m);
    while (m--) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v); // 从左边向右边连边
    }
    int ans=0; // 统计答案
    for (int i=1;i<=n1;++i) { // 枚举左边的点
        memset(sta,0,sizeof(sta)); // 将右边的点标记为尚未搜索的状态
        if (loc(i)) ans++; // 匹配成功
    }
    printf("%d",ans);
    return 0;
}