#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> bucket;

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string s="";
        for (int j=1;j<=8;++j) {
            string s2;
            cin>>s2;
            s+=s2;
        }
        bucket[s]++;
        printf("%d\n",bucket[s]);
    }
    return 0;
}