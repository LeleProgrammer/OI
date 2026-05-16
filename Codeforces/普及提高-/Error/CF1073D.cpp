#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,t;
int arr[200005];
int summ;
int cnt=0;
vector<int> flag;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>t;
    for (int i=1;i<=n;++i) {
        cin>>arr[i];
    }
    for (int i=1;i<=n;++i) flag.push_back(i);
    for (int i=0;i<flag.size();++i) {
        if (arr[flag[i]]>t) flag.erase(flag.begin()+i),i--;
    }
    while (flag.size()) {
        summ=0;
        for (int i=0;i<flag.size();++i) {
            summ+=arr[flag[i]];
        }
        if (summ>t) {
            for (int i=0;i<flag.size();++i) {
                if (arr[flag[i]]<=t) {
                    t-=arr[flag[i]];
                    cnt++;
                }
            }
            break;
        }
        cnt+=t/summ*flag.size();
        t%=summ;
        for (int i=0;i<flag.size();++i) {
            if (arr[flag[i]]>t) flag.erase(flag.begin()+i),i--;
        }
    }
    cout<<cnt;
    return 0;
}