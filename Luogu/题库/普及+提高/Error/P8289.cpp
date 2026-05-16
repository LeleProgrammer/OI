#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define rint register int
#define LL long long
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

int n;
map<string,string> def;

bool check(string& s,string t,int pos) {
    string k;
    _rep(i,pos,min((int)s.size()-1,(int)t.size()-1+pos)) k.push_back(s[i]);
    return k==t;
}

bool islegal(char c) {
    return isalpha(c) || isdigit(c) || c=='_';
}

pair<string,int> readPart(string& s,int pos) {
    string ans;
    while (pos<s.size() && !islegal(s[pos])) pos++;
    while (pos<s.size() && islegal(s[pos])) ans.push_back(s[pos++]);
    return {ans,pos};
}

pair<string,int> readAll(string& s,int pos) {
    string ans;
    while (pos<s.size() && isspace(s[pos])) pos++;
    while (pos<s.size() && !isspace(s[pos])) ans.push_back(s[pos++]);
    return {ans,pos};
}

int main() {
    // FRR("P8289_2.in");
    // FRW("P8289_my.out");
    read(n);
    while (n--) {
        string s;
        getline(cin,s);
        int cur=0;
        if (check(s,"#define",cur)) {
            cur+=7;
            auto res1=readPart(s,cur);
            cur=res1.second;
            auto res2=readAll(s,cur);
            def[res1.first]=res2.first;
        } else if (check(s,"#undef",cur)) {
            cur+=6;
            auto res1=readPart(s,cur);
            cur=res1.second;
            def.erase(res1.first);
        } else {
            while (true) {
                bool changed=false;
                cur=0;
                string nex;
                while (cur<s.size()) {
                    auto res=readPart(s,cur);
                    cur=res.second;
                    if (def.count(res.first)) {
                        changed=true;
                        nex+=def[res.first];
                        if (!isspace(s[cur])) {
                            auto res2=readAll(s,cur);
                            nex+=res2.first;
                            cur=res2.second;
                        }
                    } else {
                        nex+=res.first;
                        if (!isspace(s[cur])) {
                            auto res2=readAll(s,cur);
                            nex+=res2.first;
                        }
                    }
                    nex+=' ';
                    s=nex;
                }
                if (!changed) break;
            }
            cout<<s;
        }
        putchar(10);
    }
    return 0;
}