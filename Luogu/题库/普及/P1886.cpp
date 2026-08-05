#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[1000005];
deque<int> av,ai,bv,bi;
vector<int> resa,resb;

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) scanf("%d",arr+i);
    for (int i=1;i<=n;++i) {
        if (!ai.empty() && ai.front()<i-k+1) {
            ai.pop_front();
            av.pop_front();
        }
        if (!bi.empty() && bi.front()<i-k+1) {
            bi.pop_front();
            bv.pop_front();
        }
        if (av.empty() || arr[i]<=av.back()) {
            av.push_back(arr[i]);
            ai.push_back(i);
        } else {
            while (!av.empty() && av.back()<arr[i]) {
                av.pop_back();
                ai.pop_back();
            }
            av.push_back(arr[i]);
            ai.push_back(i);
        }
        if (bv.empty() || arr[i]>=bv.back()) {
            bv.push_back(arr[i]);
            bi.push_back(i);
        } else {
            while (!bv.empty() && bv.back()>arr[i]) {
                bv.pop_back();
                bi.pop_back();;
            }
            bv.push_back(arr[i]);
            bi.push_back(i);
        }
        if (i>=k) {
            resa.push_back(av.front());
            resb.push_back(bv.front());
        }
    }
    for (int v:resb) printf("%d ",v);
    printf("\n");
    for (int v:resa) printf("%d ",v);
    return 0;
}