#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,str;
int n;

void figure(string& s) {
    for (int i=0;i<s.size();++i) {
        if (isupper(s[i])) {
            s[i]=s[i]-'A'+'a';
        } else if (!isalpha(s[i])) {
            s.erase(s.begin()+i);
            --i;
        }
    }
}

int main() {
    cin>>s1>>s2>>s3;
    figure(s1);
    figure(s2);
    figure(s3);
    scanf("%d",&n);
    while (n--) {
        cin>>str;
        figure(str);
        if (s1+s2+s3==str || s1+s3+s2==str || s2+s1+s3==str || s2+s3+s1==str || s3+s1+s2==str || s3+s2+s1==str) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }
    return 0;
}