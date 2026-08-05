#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n;
vector<int> arr;

bool cmp1(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const int& a,const int& b) {
    return a>b;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int v;
        scanf("%d",&v);
        arr.push_back(v);
    }
    sort(arr.begin(),arr.end(),cmp1);
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    sort(arr.begin(),arr.end(),cmp2);
    if (arr.size()==1) puts("-1");
    else if (arr.size()==2) printf("%d",min(arr[0]%arr[1],arr[1]%arr[0]));
    else printf("%d",max(arr[0]%arr[1],arr[2]));
    return 0;
}