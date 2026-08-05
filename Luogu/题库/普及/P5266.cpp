#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> hs;

int main() {
    int n,op,sco;
    string nm;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&op);
        if (op!=4) cin>>nm;
        else {
            printf("%d\n",hs.size());
            continue;
        }
        if (op==1) {
            scanf("%d",&sco);
            auto iter=hs.find(nm);
            if (iter==hs.end()) {
                hs.insert(make_pair(nm,sco));
            } else {
                iter->second=sco;
            }
            printf("OK\n");
        } else if (op==2) {
            auto iter=hs.find(nm);
            if (iter==hs.end()) {
                printf("Not found\n");
            } else {
                printf("%d\n",iter->second);
            }
        } else if (op==3) {
            auto iter=hs.find(nm);
            if (iter==hs.end()) {
                printf("Not found\n");
            } else {
                hs.erase(iter);
                printf("Deleted successfully\n");
            }
        }
    }
}