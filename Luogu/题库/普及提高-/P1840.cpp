#include <bits/stdc++.h>
using namespace std;

int n,m,l,r,tot;

struct area {
    int l;
    int r;
    area(int l,int r) {
        this->l=l;
        this->r=r;
    }
};

vector<area> v;

int main() {
    scanf("%d %d",&n,&m);
    v.push_back(area(1,n));
    while (m--) {
        scanf("%d %d",&l,&r);
        for (int i=0;i<v.size();++i) {
            if (v[i].l>=l && v[i].r<=r) { // 占掉整个区域
                v.erase(v.begin()+i);
                i--;
            } else if (v[i].l<l && v[i].r>r) { // 挖掉区域中间一块
                /* 注意下面两行的顺序 */
                v.push_back(area(r+1,v[i].r));
                v[i].r=l-1;
            } else if (l<=v[i].l && r<v[i].r && r>=v[i].l) { // 砍掉区域左边一块
                v[i].l=r+1;
            } else if (l>v[i].l && l<=v[i].r && r>v[i].r) { // 砍掉区域右边右边一块
                v[i].r=l-1;
            }
        }
        tot=0;
        for (int i=0;i<v.size();++i) {
            tot=tot+(v[i].r-v[i].l+1);
        }
        printf("%d\n",tot);
    }
    return 0;
}

/*
1 1 , 4 4 , 8 10
*/