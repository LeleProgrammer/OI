#include <bits/stdc++.h>
using namespace std;

long long n,a,b,k[200];
long long minimum=9223372036854775807;
long long k_min[200];
bool cannot=false;
deque<long long> nows;
deque<long long> timess;

void bfs() {
    long long now=nows[0];
    long long times=timess[0];
    nows.pop_front();
    timess.pop_front();
    if (cannot) return;
    if (times>=1000000) {
        cannot=true;
        return;
    }
    if (now==b) {
        if (times<minimum) {
            minimum=times;
        }
        return;
    }
    if (k_min[now-1]>times) {
        k_min[now-1]=times;
    }
    if (times<minimum) {
        if (now+k[now-1]<=n) {
            if (k_min[now+k[now-1]-1]<times+1) {
                nows.push_back(now+k[now-1]);
                timess.push_back(times+1);
                bfs();
            }
        }
        if (now-k[now-1]>=1) {
            if (k_min[now-k[now-1]-1]<times+1) {
                nows.push_back(now-k[now-1]);
                timess.push_back(times+1);
                bfs();
            }
        }
    }
}

void init() {
    memset(k_min,9223372036854775807,sizeof(k_min));
    scanf("%d %d %d",&n,&a,&b);
    for (long long i=0;i<n;++i) {
        scanf("%d",&(k[i]));
    }
    nows.push_back(a);
    timess.push_back(0);
}

int main() {
    init();
    bfs();
    if (cannot) printf("-1");
    else printf("%d",minimum);
    return 0;
}