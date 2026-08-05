#include <bits/stdc++.h>
using namespace std;

int n;
int h,v;

struct station {
    int h,v,i;
};

stack<station> q;

int result[1000005];

int main() {
    scanf("%d",&n);
    memset(result,0,sizeof result);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&h,&v);
        station s={h,v,i};
        if (q.empty()) {q.push(s);continue;}
        if (q.top().h>s.h) {
            result[q.top().i]+=s.v;
            q.push(s);
        } else if (q.top().h<s.h) {
            while (true) {
                if (!q.empty()) {
                    if (q.top().h<s.h) {
                        result[s.i]+=q.top().v;
                        q.pop();
                    } else if (q.top().h>s.h) {
                        result[q.top().i]+=s.v;
                        break;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            q.push(s);
        } else {
            q.push(s);
        }
    }
    int maxx=-0x3f3f3f3f;
    for (int i=1;i<=n;++i) {
        maxx=max(maxx,result[i]);
    }
    printf("%d",maxx);
    return 0;
}

/*
3
4 2
3 5
6 10

result-----
5
0
0

3 5 2
4 2 1
bottom

3
4 2
100 5
5 10

result
0
12
0

5 10 3
100 5 2
bottom
*/