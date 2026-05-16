#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n,m;
int arr[N];
string opp;
int mul;
vector<int> l,r;

vector<int> ans;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        mul=1;
        ans.clear();
        for (int i=1;i<=n;++i) {
            scanf("%d",&arr[i]);
        }
        int a=1,b=n;
        cin>>opp;
        for (int i=0;i<n;++i) {
            char op=opp[i];
            if (op=='L') {
                l.push_back(arr[a]); a++;
            } else {
                r.push_back(arr[b]); b--;
            }
        }
        for (int i=n-1;i>=0;--i) {
            char op=opp[i];
            if (op=='L') {
                mul*=l.back();
                mul%=m;
                ans.push_back(mul);
                l.pop_back();
            } else {
                mul*=r.back();
                mul%=m;
                ans.push_back(mul);
                r.pop_back();
            }
            // cout<<"test: "<<mul<<endl;
        }
        for (int i=n-1;i>=0;--i) {
            printf("%d ",ans[i]);
        }
        putchar(10);
    }
    return 0;
}