#include <bits/stdc++.h>
using namespace std;

queue<int> q;
stack<int> s;
priority_queue< int,vector<int>,greater<int> > small_heap;
priority_queue< int,vector<int>,less<int> > big_heap;
int n,opt,v;
bool flag_q=true;
bool flag_s=true;
bool flag_small_heap=true;
bool flag_big_heap=true;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&opt,&v);
        if (opt==1) {
            q.push(v);
            s.push(v);
            small_heap.push(v);
            big_heap.push(v);
        } else {
            if (flag_q) {
                if (q.empty()) flag_q=false;
                else {
                    if (q.front()!=v) flag_q=false;
                    q.pop();
                }
            }
            if (flag_s) {
                if (s.empty()) flag_s=false;
                else {
                    if (s.top()!=v) flag_s=false;
                    s.pop();
                }
            }
            if (flag_small_heap) {
                if (small_heap.empty()) flag_small_heap=false;
                else {
                    if (small_heap.top()!=v) flag_small_heap=false;
                    small_heap.pop();
                }
            }
            if (flag_big_heap) {
                if (big_heap.empty()) flag_big_heap=false;
                else {
                    if (big_heap.top()!=v) flag_big_heap=false;
                    big_heap.pop();
                }
            }
        }
    }
    printf(flag_q?"Yes\n":"No\n");
    printf(flag_s?"Yes\n":"No\n");
    printf(flag_big_heap?"Yes\n":"No\n");
    printf(flag_small_heap?"Yes\n":"No\n");
    return 0;
}