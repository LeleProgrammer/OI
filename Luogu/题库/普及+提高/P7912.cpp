#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n;

struct node {
    int cnt;
    int start;
    int type;
};

vector<node> v;
deque<node> q;
queue<node> q2;

bool flag[N];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int val;
        scanf("%d",&val);
        if (v.empty()) {
            v.push_back({1,i,val});
            continue;
        }
        if (val==v.back().type) {
            v.back().cnt++;
        } else {
            v.push_back({1,i,val});
        }
    }
    for (int i=0;i<v.size();++i) {
        q.push_back(v[i]);
    }
    while (!q.empty() || !q2.empty()) {
        while (!q.empty()) {
            auto u=q.front(); q.pop_front();
            while (u.cnt) {
                if (flag[u.start]) {
                    u.start++;
                    u.cnt--;
                } else {
                    break;
                }
            }
            if (!u.cnt) continue;
            printf("%d ",u.start),u.cnt--,flag[u.start]=1,u.start++;
            if (!u.cnt) continue;
            q2.push(u);
        }
        while (!q2.empty()) {
            auto u=q2.front(); q2.pop();
            if (!q.empty() && u.type==q.back().type) {
                q.back().cnt=u.start-q.back().start+u.cnt;
            } else q.push_back(u);
        }
        putchar(10);
    }
    return 0;
}