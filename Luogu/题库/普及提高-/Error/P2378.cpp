#include <bits/stdc++.h>
using namespace std;

string s;
vector< pair<int,int> > v; // 系数 次数

int main() {
    cin>>s;
    int x=0,c=0,t=1;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='-' && x==0 && c==0) t=-1; // 符号
        else if (s[i]=='+' && x==0 && c==0) t=1;
        if (isdigit(s[i]) && c==0) { // 系数
            x=x*10+s[i]-'0';
        } else if (s[i]=='x' && c==0) {
            if (i+1<s.size() && s[i+1]=='^') { // 2次
                c=2;
                i+=2;
            } else { // 1次
                c=1;
            }
            if (x==0) x=1;
            v.push_back(make_pair(x*t,c)); // 项
            x=0,c=0;
        }
    }
    if (x!=0) {
        v.push_back(make_pair(x*t,c));
    }
    if (v.size()==2) { // 两项
        // 平方差公式
        if (int(sqrt(v[0].first))*int(sqrt(v[0].first))==v[0].first && v[0].second==2 && int(sqrt(abs(v[1].first)))*int(sqrt(abs(v[1].first)))==abs(v[1].first) && v[1].first<0) {
            int a=sqrt(v[0].first);
            int b=sqrt(-v[1].first);
            if (a==1) printf("(x+%d)(x-%d)",b,b);
            else printf("(%dx+%d)(%dx-%d)",a,b,a,b);
        }
        // 合并同类项
        if (v[0].second==2 && v[1].second==1) {
            ;
        }
    }
    return 0;
}