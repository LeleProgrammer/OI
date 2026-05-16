#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> _hash;

int main() {
    int n;
    scanf("%d",&n);
    string s;
    while (n--) {
        cin>>s;
        unordered_map<string,int>::iterator iter;
        iter=_hash.find(s);
        if (iter==_hash.end()) {
            _hash.insert(make_pair(s,0));
            printf("OK\n");
        } else {
            iter->second++;
            cout<<s;
            printf("%d\n",iter->second);
        }
    }
    return 0;
}