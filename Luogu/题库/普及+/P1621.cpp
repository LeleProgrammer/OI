#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int a,b,P;
int p[N];
unordered_map<int,int> hs;
unordered_set<int> res;
int idx;
vector<int> arr[N];

void seperate(int n) {
    int k=n;
    for (int i=2;i*i<=n;++i) {
        if (n%i) continue;
        if (i>=P) {
            auto iter=hs.find(i);
            int t;
            if (iter==hs.end()) hs.insert({i,++idx}),t=idx;
            else t=iter->second;
            arr[t].push_back(k);
        }
        while (n%i==0) n/=i;
    }
    if (n!=1 && n>=P) {
        if (hs.find(n)!=hs.end()) {
            arr[hs[n]].push_back(k);
            return;
        }
        hs.insert({n,++idx});
        arr[idx].push_back(k);
    }
}

int find(int x) {
    return (p[x]==x)?(p[x]):(p[x]=find(p[x]));
}

int main() {
    scanf("%d %d %d",&a,&b,&P);
    for (int i=a;i<=b;++i) p[i]=i;
    for (int i=a;i<=b;++i) seperate(i);
    for (int i=1;i<=idx;++i) {
        for (int j=1;j<arr[i].size();++j) {
            if (find(arr[i][0])!=find(arr[i][j])) {
                p[find(arr[i][0])]=find(arr[i][j]);
            }
        }
    }
    for (int i=a;i<=b;++i) {
        res.insert(find(i));
    }
    printf("%d",res.size());
    return 0;
}