#include <bits/stdc++.h>
using namespace std;

int n,r;
int arr[25];

void dfs(int pt,vector<int> v) {
    if (v.size()==r) {
        for (int i=0;i<r;++i) {
            cout<<setw(3)<<v[i];
        }
        cout<<endl;
        return ;
    }
    for (int i=pt+1;i<n;++i) {
        v.push_back(arr[i]);
        dfs(i,v);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r;
    for (int i=0;i<n;++i) {
        arr[i]=i+1;
    }
    vector<int> tmp;
    dfs(-1,tmp);
    return 0;
}