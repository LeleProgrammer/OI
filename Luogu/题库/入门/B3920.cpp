#include <bits/stdc++.h>
using namespace std;

const int N=2005;

char str[N];

string a="Genshin";
string b="player";

int ans=0;
int cnt=0;

int main() {
    scanf("%s",str);
    for (int i=0;str[i];++i) {
        if (str[i]=='G') {
            bool ok=true;
            for (int j=0;j<=6;++j) {
                if (str[i+j]!=a[j]) {
                    ok=false;
                    break;
                }
            }
            if (ok) {
                cnt++;
                i+=6;
            }
        } else if (str[i]=='p') {
            bool ok=true;
            for (int j=0;j<=5;++j) {
                if (str[i+j]!=b[j]) {
                    ok=false;
                    break;
                }
            }
            if (ok) {
                ans+=cnt;
            }
        }
    }
    printf("%d",ans);
    return 0;
}