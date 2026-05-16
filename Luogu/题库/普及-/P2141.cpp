#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
vector<int> arr;
int cnt;
bool flag[N];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int k;
        scanf("%d",&k);
        arr.push_back(k);
    }
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    n=arr.size();
    for (int a=0;a<n;++a) {
        for (int b=a+1;b<n;++b) {
            for (int c=b+1;c<n;++c) {
                if (arr[a]+arr[b]==arr[c] && !flag[c]) cnt++,flag[c]=true;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}