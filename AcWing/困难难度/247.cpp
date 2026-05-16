#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN=100005;

int n;
int T;

struct Segment { // 存线段
    double x; // 横坐标，也就是这条竖直的线段的位置
    double y1; // 纵坐标
    double y2; // 纵坐标
    int k; // +1 或 -1
    friend bool operator < (const Segment& a,const Segment& b) {
        return a.x<b.x; // 横坐标小的放前面
    }
} seg[MAXN*2]; // 存每一条线段，也就是扫描线要移动到的位置

struct Node { // 线段树的节点，维护一个区间，用了离散化
    // l,r 用于 ys
    int l;
    int r;
    int cnt; // 有几个矩形覆盖
    double len; // 懒标记，表示当前总长
} tr[MAXN*8]; // n 个矩形，每个矩形有左右 2 个边界，线段树节点最多是 4 倍，所以 MAXN*2*4

vector<double> ys; // 纵坐标的每个位置，去除重复之后

// 二分查找寻找 y 在 ys 中的下标
int find(double y) {
    return lower_bound(ys.begin(),ys.end(),y)-ys.begin();
}

void pushup(int u) {
    if (tr[u].cnt) tr[u].len=ys[tr[u].r+1]-ys[tr[u].l]; // 有覆盖矩形就可以直接算长度 ***
    else if (tr[u].l!=tr[u].r) {
        tr[u].len=tr[u<<1].len+tr[u<<1|1].len; // 没有覆盖矩形就需要通过子节点获取数据 ***
    } else {
        tr[u].len=0; // 叶子节点一定是 0
    }
}

void build(int u,int l,int r) {
    tr[u].l=l;
    tr[u].r=r;
    tr[u].len=tr[u].cnt=0;
    if (l!=r) {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
    }
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) { // 整个区间在需要添加的区间内
        tr[u].cnt+=k; // 直接添加
        pushup(u); // pushup 更新该节点的 len 数据
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>=mid+1) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int main() {
    while (true) {
        scanf("%d",&n);
        if (!n) break;
        ys.clear();
        for (int i=0,j=0;i<n;++i) {
            double x1,x2,y1,y2;
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            seg[j].x=x1;
            seg[j].y1=y1;
            seg[j].y2=y2;
            seg[j].k=1;
            ++j;
            seg[j].x=x2;
            seg[j].y1=y1;
            seg[j].y2=y2;
            seg[j].k=-1;
            ++j;
            ys.push_back(y1);
            ys.push_back(y2);
        }
        sort(ys.begin(),ys.end());
        ys.erase(unique(ys.begin(),ys.end()),ys.end());
        sort(seg,seg+n*2);
        build(1,0,ys.size()-2);
        double ans=0.0;
        for (int i=0;i<=2*n-1;++i) {
            if (i) ans+=(seg[i].x-seg[i-1].x)*tr[1].len;
            modify(1,find(seg[i].y1),find(seg[i].y2)-1,seg[i].k);
        }
        printf("Test case #%d\n",++T);
        printf("Total explored area: %.2lf\n\n",ans);
    }
    return 0;
}