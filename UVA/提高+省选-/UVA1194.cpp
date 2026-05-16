#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int M=2005;

int n,m,k;
int e[M],ne[M],h[N],tot;
int ans;
int mat[N];
bool sta[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool loc(int curr) {
    for (int i=h[curr];~i;i=ne[i]) {
        if (!sta[e[i]]) { // 没搜过
            sta[e[i]]=true; // 现在搜了
            if (mat[e[i]]==0 || loc(mat[e[i]])) { // 要么右边这个点还没有被左边的点匹配，要么右边的点原先匹配的左边的点找到一个新的右边的点成功匹配
                mat[e[i]]=curr;
                return true;
            }
        }
    }
    return false;
}

int main() {
    while (scanf("%d",&n),n) {
        memset(h,-1,sizeof(h)); tot=0;
        scanf("%d %d",&m,&k);
        while (k--) {
            int tmp,u,v;
            scanf("%d %d %d",&tmp,&u,&v);
            if (!u || !v) continue; // 初始就是 0 号模式，只要有 0 号模式的一开始全都完成了
            add(u,v);
        }
        ans=0;
        memset(mat,0,sizeof(mat)); // 输入的时候过滤掉 0 号的情况，这里填充 0 应该不会出问题
        for (int i=1;i<n;++i) { // 同样，过滤掉 0 号，即认为下标从 1 开始，但结束点仍然如原题为 n-1
            memset(sta,0,sizeof(sta)); // 每次匈牙利算法执行前需要清空 sta (state) 数组
            if (loc(i)) ans++; // 匹配成功
        }
        printf("%d\n",ans);
    }
    return 0;
}