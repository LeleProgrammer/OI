#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> result;

// 找出2~n之间，是2的若干次方的数，存在q中，并从大到小排好
inline void make_list(int n) {
    vector<int> tmp;
    int maximum=n;
    for (int i=2;i<=maximum;i*=2) {
        tmp.push_back(i);
    }
    while (!tmp.empty()) {
        q.push(tmp.back());
        tmp.pop_back();
    }
    return ;
}

int main() {
    int n;
    scanf("%d",&n);
    make_list(n);
    while (true) {
        if (!q.empty()) {
            if (n>=q.front()) {
                n-=q.front();
                result.push_back(q.front());
                q.pop();
                if (n==0) {
                    for (int res:result) {
                        printf("%d ",res);
                    }
                    return 0;
                }
            } else {
                q.pop();
            }
        } else {
            printf("-1");
            return 0;
        }
    }
    return 0;
}