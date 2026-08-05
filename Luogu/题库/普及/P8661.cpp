#include <bits/stdc++.h>
using namespace std;

int n,d,k;

struct event {
    int t;
    int id;
    friend bool operator < (const event& a,const event& b) {
        return a.t<b.t;
    }
} arr[100005];

deque<event> q;

int cnt[100005];

unordered_set<int> results;

int main() {
    scanf("%d %d %d",&n,&d,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&arr[i].t,&arr[i].id);
    }
    sort(arr+1,arr+1+n);
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;++i) {
        while (!q.empty() && q.front().t<arr[i].t-d+1) {
            cnt[q.front().id]--;
            q.pop_front();
        }
        q.push_back(arr[i]);
        cnt[q.back().id]++;
        if (cnt[q.back().id]>=k) {
            results.insert(q.back().id);
        }
    }
    vector<int> tmp;
    for (auto iter=results.begin();iter!=results.end();++iter) {
        tmp.push_back(*iter);
    }
    sort(tmp.begin(),tmp.end(),less<int>());
    for (int v:tmp) {
        printf("%d\n",v);
    }
    return 0;
}