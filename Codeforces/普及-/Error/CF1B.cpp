#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    while (n--) {
        cin>>s;
        if (s[0]=='R' && isdigit(s[1])) {
            int num=0;
            bool start=false;
            for (int i=0;i<s.size();++i) {
                if (start) num=num*10+(s[i]-'0');
                if (s[i]=='C') start=true;
            }
            string res="";
            while (num) {
                if (num%26==0) res="Z"+res;
                else res=((char)((num%26)+'A'-1))+res;
                num/=26;
            }
            cout<<res;
            num=0;
            for (int i=1;i<s.size();++i) {
                if (s[i]=='C') break;
                num=num*10+(s[i]-'0');
            }
            printf("%d\n",num);
        } else {
            cout<<s<<endl;
            printf("R");
            int num=0;
            bool start=false;
            for (int i=0;i<s.size();++i) {
                if (isdigit(s[i])) start=true;
                if (start) num=num*10+(s[i]-'0');
            }
            printf("%d",num);
            num=0;
            printf("C");
            start=false;
            int exp=0;
            for (int i=s.size()-1;i>=0;--i) {
                if (isalpha(s[i])) start=true;
                if (!start) continue;
                //cout<<"TEST: "<<s[i]<<endl;
                //cout<<s[i]<<" TEST: "<<(int)(s[i]-'A')<<endl;
                num=(int)((s[i]-'A'+1)*pow(26,exp))+num;
                ++exp;
            }
            printf("%d\n",num);
        }
    }
    return 0;
}