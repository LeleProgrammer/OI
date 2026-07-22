#include <bits/stdc++.h>
using namespace std;

const int N=256005;

int n;
map< int,string > langs;
int lang_cnt;
int son[N][128];
int cnt;
int en[N];

bool is_char(char c) {
    return isalpha(c) || c=='\'' || c=='-';
}

void insert(string s,int lang) {
    int u=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i];
        if (isupper(c)) c=tolower(c);
        if (!son[u][c]) son[u][c]=++cnt;
        u=son[u][c];
    }
    en[u]=lang;
}

int query(string s) {
    int u=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i];
        if (isupper(c)) c=tolower(c);
        if (!son[u][c]) return 0;
        u=son[u][c];
    }
    return en[u];
}

void debug(char& c) {
    // assert(c>=0 && c<=127);
    if (!(c>=0 && c<=127)) {
        cout<<c;
        exit(0);
    }
}

int main() {
    // freopen("P3752_2.in","r",stdin);
    // freopen("P3752_test.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string lang;
        bool start=false;
        while (true) {
            char c=getchar();
            debug(c);
            if (c==' ' && start) break;
            else if ((c=='\n' || c=='\r' || c==' ') && !start) continue;
            lang.push_back(c);
            start=true;
        }
        langs[++lang_cnt]=lang;
        string word;
        start=false;
        while (true) {
            char c=getchar();
            debug(c);
            if ((c=='\n' || c=='\r') && start) {
                if (!word.empty()) {
                    insert(word,lang_cnt);
                }
                break;
            }
            else if ((c=='\n' || c=='\r' || c==' ') && !start) continue;
            if (is_char(c)) word.push_back(c);
            else {
                if (!word.empty()) {
                    insert(word,lang_cnt);
                }
                word.clear();
            }
            start=true;
        }
    }
    string word;
    string result;
    bool start=false;
    while (true) {
        char c;
        if (!~scanf("%c",&c)) break;
        debug(c);
        if ((c=='\n' || c=='\r') && start) {
            if (!word.empty()) {
                int lang=query(word);
                if (lang) result=langs[lang];
            }
            cout<<result<<endl;
            result.clear();
            word.clear();
            start=false;
            continue;
        } else if ((c=='\n' || c=='\r' || c==' ') && !start) continue;
        if (is_char(c)) word.push_back(c);
        else {
            if (!word.empty()) {
                int lang=query(word);
                if (lang) {
                    result=langs[lang];
                }
            }
            word.clear();
        }
        start=true;
    }
    return 0;
}

/*
1
Vulcan throks kilko-srashiv k'etwel
Dif-tor heh, Spohkh. I'tah trai k'etwel
*/