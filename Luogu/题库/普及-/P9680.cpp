#include <bits/stdc++.h>
using namespace std;

int n;
string type,newvar,text;
int cnt=0;

unordered_map< string,string > hs;

string read_var_name() {
    string name;
    char c;
    while (true) {
        c=getchar();
        if (!isalpha(c)) {
            if (c=='(') break;
            else continue;
        } else {
            name+=c;
        }
    }
    return name;
}

string read_text() {
    string text;
    char c;
    bool start=false;
    int mode; // 0:var 1:text
    while (true) {
        c=getchar();
        if (!start) {
            if (c!='"') {
                mode=0;
                start=true;
                if (c==')') {
                    return hs.find(text)->second;
                } else {
                    text+=c;
                }
            } else {
                mode=1;
                start=true;
            }
            continue;
        } else {
            if (mode==0) {
                if (c==')') {
                    return hs.find(text)->second;
                } else {
                    text+=c;
                }
            } else {
                if (c=='"') {
                    return text;
                } else {
                    text+=c;
                }
            }
        }
    }
}

void flush_remain() {
    char c;
    while (true) {
        c=getchar();
        if (c==';') break;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        cin>>type;
        newvar=read_var_name();
        text=read_text();
        flush_remain();
        hs.insert(make_pair(newvar,text));
        if (type=="string") {
            cnt+=text.size();
        }
    }
    printf("%d",cnt);
    return 0;
}