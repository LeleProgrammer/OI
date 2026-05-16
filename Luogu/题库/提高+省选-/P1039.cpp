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
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
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
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
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
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=105;

int m,n,p,idx;
map<string,int> s;
map<string,int> d;
int dat[N];
unordered_set<int> yes,no;

struct tex {
	int a,b,c; // a: b c(is/not) guilty //// a: b=0 is (c) day
} arr[N];

deque<string> readline() {
	string txt;
	getline(cin,txt);
	while (isspace(txt.back())) txt.pop_back();
	deque<string> res;
	string cur;
	_rep(i,0,(int)txt.size()-1) {
		if (txt[i]==' ') res.emplace_back(cur),cur="";
		else cur+=txt[i];
	}
	res.emplace_back(cur);
	if (res.size()==1) return readline();
	return res;
}

void init() {
	d["Monday"]=1;
	d["Tuesday"]=2;
	d["Wednesday"]=3;
	d["Thursday"]=4;
	d["Friday"]=5;
	d["Saturday"]=6;
	d["Sunday"]=7;
}

int cnt1(int k) {
	int ans=0;
	while (k) ans+=(k&1),k>>=1;
	return ans;
}

int main() {
	init();
	read(m),read(n),read(p);
	_rep(i,1,m) {
		string str;
		readstr(str);
		s[str]=i;
	}
	_rep(i,1,p) {
		auto q=readline();
		string nam=q.front(); q.pop_front();
		nam.pop_back();
		string sub=q.front(); q.pop_front();
		if (q.empty()) continue;
		string ver=q.front(); q.pop_front();
		if (q.empty()) continue;
		string nex=q.front(); q.pop_front();
		if (nex=="not") {
			if (q.empty()) continue;
			string obj=q.front(); q.pop_front();
			if (obj.back()=='.') obj.pop_back();
			if (!q.empty()) continue;
			if (ver=="am") {
				if (sub!="I") continue;
				if (obj!="guilty") continue;
				arr[++idx]={s[nam],s[nam],0};
			} else {
				if (!s.count(nam)) continue;
				if (ver!="is") continue;
				if (obj!="guilty") continue;
				arr[++idx]={s[nam],s[sub],0};
			}
		} else {
			string obj=nex;
			if (obj.back()=='.') obj.pop_back();
			if (!q.empty()) continue;
			if (sub=="Today") {
				if (ver!="is") continue;
				if (!d.count(obj)) continue;
				arr[++idx]={s[nam],0,d[obj]};
			} else {
				if (ver=="am") {
					if (sub!="I") continue;
					if (obj!="guilty") continue;
					arr[++idx]={s[nam],s[nam],1};
				} else {
					if (!s.count(nam)) continue;
					if (ver!="is") continue;
					if (obj!="guilty") continue;
					arr[++idx]={s[nam],s[sub],1};
				}
			}
		}
	}
	unordered_set<int> res;
	_rep(g,0,(1<<m)-1) {
		if (cnt1(g)!=m-n) continue;
		memset(dat,-1,sizeof(dat));
		yes.clear();
		no.clear();
		bool ok=true;
		_rep(i,1,idx) {
			int t=((g>>(arr[i].a-1))&1);
			if (!arr[i].b) {
				if (t) {
					if (no.count(arr[i].c)) {
						ok=false;
						break;
					}
					int cnt=yes.size();
					cnt-=yes.count(arr[i].c);
					if (cnt) {
						ok=false;
						break;
					}
					yes.emplace(arr[i].c);
				} else {
					if (yes.count(arr[i].c)) {
						ok=false;
						break;
					}
					no.emplace(arr[i].c);
				}
			} else {
				if (!~dat[arr[i].b]) dat[arr[i].b]=(arr[i].c^(t^1));
				else if ((arr[i].c^(t^1))!=dat[arr[i].b]) {
					ok=false;
					break;
				}
			}
		}
		if (!ok) continue;
		int cnt0=0;
		_rep(i,1,m) if (!dat[i]) cnt0++;
		if (cnt0==m-1) _rep(i,1,m) if (!~dat[i]) dat[i]=1;
		int cnt=0,gui;
		_rep(i,1,m) if (dat[i]==1) cnt++,gui=i;
		if (no.size()==7) continue; // HACK #1
		if (!cnt) {
			_rep(i,1,m) if (!~dat[i]) res.emplace(i);
			continue;
		} else if (cnt>=2) continue;
		res.emplace(gui);
	}
	if (res.size()>=2) puts("Cannot Determine");
	else if (res.empty()) puts("Impossible");
	else _iter(it,s) if (it->second==(*res.begin())) cout<<it->first;
	return 0;
}
