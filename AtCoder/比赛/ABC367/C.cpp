#include <bits/stdc++.h>
using namespace std;

const int N=15;

int n,k;
int arr[N];
vector<int> vec;

void print() {
    for (int i=0;i<vec.size();++i) {
        printf("%d ",vec[i]);
    }
    putchar(10);
}

void dfs(int pos,int sum) {
    if (pos==n+1) {
        if (sum%k==0) print();
        return;
    }
    for (int i=1;i<=arr[pos];++i) {
        vec.push_back(i);
        dfs(pos+1,sum+i);
        vec.pop_back();
    }
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
    dfs(1,0);
    return 0;
}