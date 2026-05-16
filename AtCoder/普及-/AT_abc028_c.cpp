#include <bits/stdc++.h>
using namespace std;

int arr[5];

set<int> st;

vector<int> v;

int main() {
    scanf("%d %d %d %d %d",arr,arr+1,arr+2,arr+3,arr+4);
    for (int i=0;i<=2;++i) {
        for (int j=i+1;j<=3;++j) {
            for (int p=j+1;p<=4;++p) {
                st.insert(arr[i]+arr[j]+arr[p]);
            }
        }
    }
    for (set<int>::iterator iter=st.begin();iter!=st.end();++iter) {
        v.push_back(*iter);
    }
    sort(v.begin(),v.end(),greater<int>());
    printf("%d\n",v[2]);
    return 0;
}