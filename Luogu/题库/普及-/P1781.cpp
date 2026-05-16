#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int max_i;
    string maximum="0";
    string in;
    for (int i=0;i<n;++i) {
        cin>>in;
        if (in.length()>maximum.length() || (in.length()==maximum.length() && in>maximum)) {
            maximum=in;
            max_i=i+1;
        }
    }
    cout<<max_i<<endl;
    cout<<maximum;
    return 0;
}