#include <bits/stdc++.h>
using namespace std;

int n;
queue<pair<int,int> > q;
int ablt[130]; // 11 22 33 44 ...
int next[130]; // x 1 2 3 4 5 6 ...
int tmp[130]; // x 1 2 3 4 5 6 ...

int main() {
    scanf("%d",&n);
    for (int i=1;i<=pow(2,n);++i) {
        scanf("%d",&ablt[i]);
    }
    for (int i=1;i<=pow(2,n);++i) {
        ::next[i]=i;
    }
    while (true) {
        swap(::next,tmp);
        memset(::next,0,sizeof(::next));
        int l=1;
        int r=pow(2,n);
        q.push(make_pair(l,r));
        int count=1;
        while (!q.empty()) {
            l=q.front().first;
            r=q.front().second;
            q.pop();
            if (l+1==r) {
                if (ablt[tmp[l]]>ablt[tmp[r]]) {
                    ::next[count]=tmp[l];
                    ++count;
                } else {
                    ::next[count]=tmp[r];
                    ++count;
                }
            } else {
                int ml=(l+r)/2;
                int mr=ml+1;
                q.push(make_pair(l,ml));
                q.push(make_pair(mr,r));
            }
        }
        --n;
        if (n==1) {
            if (ablt[::next[1]]>ablt[::next[2]]) {
                printf("%d",::next[2]);
            } else {
                printf("%d",::next[1]);
            }
            return 0;
        }
    }
}