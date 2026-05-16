#include <bits/stdc++.h>
using namespace std;

int arr[10];
string a,b;

int main() {
    cin>>a>>b;
    if (a=="0" && b=="0") {
        printf("OK");
        return 0;
    }
    if (a.size()!=b.size()) {
        printf("WRONG_ANSWER");
        return 0;
    }
    memset(arr,0,sizeof(arr));
    for (int i=0;i<a.size();++i) {
        arr[a[i]-'0']++;
    }
    bool can_have_zero=false;
    for (int i=0;i<b.size();++i) {
        int j;
        if (!can_have_zero) {
            for (j=1;j<=9;++j) {
                if (arr[j]) break;
            }
            can_have_zero=true;
        } else {
            for (j=0;j<=9;++j) {
                if (arr[j]) break;
            }
        }
        if (j==10) {
            printf("WRONG_ANSWER");
            return 0;
        }
        arr[j]--;
        if (b[i]-'0'!=j) {
            printf("WRONG_ANSWER");
            return 0;
        }
    }
    printf("OK");
    return 0;
}