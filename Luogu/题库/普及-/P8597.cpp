#include <bits/stdc++.h>
using namespace std;

string a,b;

void flesh(int i) {
    if (a[i]=='o') {
        a[i]='*';
    } else {
        a[i]='o';
    }
}

int main() {
    cin>>a>>b;
    int count=0;
    for (int i=0;i<a.length()-1;++i) {
        if (a[i]!=b[i]) {
            flesh(i);
            flesh(i+1);
            ++count;
        }
    }
    printf("%d",count);
    return 0;
}