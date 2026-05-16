#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105];
vector<int> teams;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
    }
    sort(arr+1,arr+1+n,greater<int>());
    int l=1,r=n;
    while (l<r) {
        teams.push_back(arr[l]+arr[r]);
        l++,r--;
    }
    sort(teams.begin(),teams.end(),less<int>());
    printf("%d\n",teams.back()-teams.front());
    return 0;
}