#include <bits/stdc++.h>
using namespace std;

int n;
string word;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>word;
        sort(word.begin(),word.end(),[](const char& a,const char& b) {
            if (tolower(a)==tolower(b)) return a<b;
            else return tolower(a)<tolower(b);
        });
        do {
            cout<<word<<endl;
        } while (next_permutation(word.begin(),word.end(),[](const char& a,const char& b) {
            if (tolower(a)==tolower(b)) return a<b;
            else return tolower(a)<tolower(b);
        }));
    }
    return 0;
}