#include <bits/stdc++.h>
using namespace std;

const int A=10000;

typedef pair<int,int> pii;

int T,n;
deque<pii> res;

int get(int k) {
    int ans=0;
    while (k) {
        k/=10;
        ans++;
    }
    return ans;
}

bool check(int num,int n) {
    // int numa=num,numb=n;
    vector<int> nd;
    while (n) {
        nd.push_back(n%10);
        n/=10;
    }
    vector<int> numd;
    while (num) {
        numd.push_back(num%10);
        num/=10;
    }
    int i=nd.size()-1;
    int j=numd.size()-1;
    bool ok=true;
    while (~j) {
        if (nd[i]!=numd[j]) {
            ok=false;
            break;
        }
        --i,--j;
        if (!~i) i=nd.size()-1;
    }
    // if (ok) {
    //     printf("test: %d %d\n",numa,numb);
    // }
    return ok;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        int n_digit=get(n);
        for (int a=1;a<=A;++a) {
            int k=n*a;
            int digit=get(k);
            int na_digit=n_digit*a;
            for (int d=1;d<=digit;++d) {
                int b=na_digit-d;
                if (b>min(10000,a*n) || b<1) continue;
                if (check(k-b,n) && get(k-b)==d) {
                    // printf("a:%d b:%d\n",a,b);
                    // printf("a:%d n*a:%d\n",a,k);
                    // printf("nad:%d\n",na_digit);
                    // printf("d:%d\n",d);
                    // printf("check(%d,%d) is %d\n",k-b,n,check(k-b,n));
                    res.push_back({a,b});
                }
            }
        }
        printf("%d\n",res.size());
        while (!res.empty()) {
            printf("%d %d\n",res.front().first,res.front().second);
            res.pop_front();
        }
    }
    return 0;
}