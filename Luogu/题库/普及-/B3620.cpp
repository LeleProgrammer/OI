#include <bits/stdc++.h>
using namespace std;

int x;
string S;
int res=0;

int main() {
    cin>>x>>S;
    for (int i=0,j=S.size()-1;i<S.size();++i,--j) {
        int k;
        if (isalpha(S[j])) {
            k=S[j]-'A'+10;
        } else {
            k=S[j]-'0';
        }
        res=res+k*pow(x,i);
    }
    cout<<res;
    return 0;
}