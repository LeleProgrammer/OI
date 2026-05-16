#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n,ans;
char s[N];

bool issym(char c) {
    return !isalpha(c) && !isdigit(c) && !isspace(c);
}

int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int l=1;l<=n;++l) {
        for (int r=l+7;r<=n && r-l+1<=16;++r) {
            bool num=false,ch=false;
            for (int i=l;i<=r;++i) {
                if (isdigit(s[i])) num=true;
                else if (issym(s[i])) ch=true;
            }
            if (num && ch) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}