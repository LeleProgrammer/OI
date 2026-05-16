#include <bits/stdc++.h>
using namespace std;

int n;

string s="";

void dfs(int x) {
    if (x==n) {
        cout<<s<<endl;
        return;
    }
    for (char c='a';c<='c';++c) {
        s+=c;
        dfs(x+1);
        s=s.substr(0,s.size()-1);
    }
}

int main() {
    scanf("%d",&n);
    dfs(0);
    return 0;
}