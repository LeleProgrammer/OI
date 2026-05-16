#include <bits/stdc++.h>
using namespace std;

int cost=0;

// [优惠票可用的最大价钱,优惠票可用的最迟时间]
queue<pair<int,int> > q;

int main() {
    int n;
    scanf("%d",&n);
    int vehicle,price,time;
    for (int i=0;i<n;++i) {
        scanf("%d %d %d",&vehicle,&price,&time);
        if (vehicle==0) {
            cost+=price;
            q.push(make_pair(price,time+45));
        } else {
            int qsize=q.size();
            bool used=false;
            for (int i=0;i<qsize;++i) {
                if (q.front().second<time) {
                    q.pop();
                } else { // the time is ok
                    if (q.front().first>=price && !used) { // the price is ok
                        used=true;
                        q.pop(); // pop and use it
                    } else { // the price isn't ok
                        q.push(q.front()); // maybe can be used later
                        q.pop();
                    }
                }
            }
            if (used) {
                continue;
            }
            cost+=price;
        }
    }
    printf("%d",cost);
    return 0;
}