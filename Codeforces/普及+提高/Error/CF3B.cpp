#include <bits/stdc++.h>
using namespace std;

int n,v;

int ans=0;
vector<int> res;

struct lorry {
    int weight;
    int value;
    int num;
    friend bool operator < (const lorry& a,const lorry& b) {
        if (double(a.value)/double(a.weight)==double(b.value)/double(b.weight)) {
            return a.weight>b.weight;
        }
        return double(a.value)/double(a.weight)<double(b.value)/double(b.weight);
    }
};

bool cmp_dict(const int& a,const int& b) {
    return a<b;
}

vector<lorry> q;

int main() {
    scanf("%d %d",&n,&v);
    for (int i=1;i<=n;++i) {
        int t,p;
        scanf("%d %d",&t,&p);
        lorry l;
        l.weight=t;
        l.value=p;
        l.num=i;
        q.push_back(l);
    }
    sort(q.begin(),q.end());
    while (v && !q.empty()) {
        if (v>=q.back().weight) {
            ans+=q.back().value;
            res.push_back(q.back().num);
            v-=q.back().weight;
        }
        q.pop_back();
    }
    sort(res.begin(),res.end(),cmp_dict);
    printf("%d\n",ans);
    for (int i=0;i<res.size();++i) {
        printf("%d ",res[i]);
    }
    return 0;
}