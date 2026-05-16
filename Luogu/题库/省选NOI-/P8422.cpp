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

const int N=55;
const int M=1005;

int n,m,k,q,ans;
int a[N][N];
int b[N][N];
unordered_set<int> color;
vector<unordered_set<int>> las5;
int cur[5];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool check() {
    bool ok=false;
    _rep(i,1,n) {
        _rep(j,1,m) {
            if (a[i][j]) {
                if (a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j]) {
                    ok=true;
                    break;
                }
                if (a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2]) {
                    ok=true;
                    break;
                }
            }
        }
        if (ok) break;
    }
    return ok;
}

bool checkBound(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=m;
}

bool swap(int x1,int y1,int x2,int y2) {
    if (abs(x1-x2)>=2 || abs(y1-y2)>=2) return false;
    if (x1==x2 && y1==y2) return false;
    if (abs(x1-x2)==1 && abs(y1-y2)==1) return false;
    if (!(a[x1][y1] && a[x2][y2])) return false;
    swap(a[x1][y1],a[x2][y2]);
    swap(b[x1][y1],b[x2][y2]);
    if (!check()) {
        swap(a[x1][y1],a[x2][y2]);
        swap(b[x1][y1],b[x2][y2]);
        return false;
    }
    return true;
}

void extra(set<pii>& del,int x,int y) {
    if (b[x][y]==1) {
        _rep(i,1,m) del.emplace(pii{x,i});
    } else if (b[x][y]==2) {
        _rep(i,1,n) del.emplace(pii{i,y});
    } else if (b[x][y]==3) {
        _rep(i,1,m) del.emplace(pii{x,i});
        _rep(i,1,n) del.emplace(pii{i,y});
    } else if (b[x][y]==4) {
        _rep(i,-1,1) _rep(j,-1,1) del.emplace(pii{x+i,y+j});
    } else if (b[x][y]==5) {
        _rep(i,-2,2) _rep(j,-2,2) del.emplace(pii{x+i,y+j});
    } else if (b[x][y]==6) {
        _rep(i,1,n) _rep(j,1,m) if (a[i][j]==a[x][y]) del.emplace(pii{i,j});
    }
}

void gravity() {
    _rep(j,1,m) _rep(i,1,n) if (!a[i][j]) _rrep(k,i-1,1) swap(a[k][j],a[k+1][j]),swap(b[k][j],b[k+1][j]);
}

void update(int r) {
    set<pii> del;
    _rep(i,1,n) {
        _rep(j,1,m) {
            if (!a[i][j]) continue;
            if (a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j]) {
                del.emplace(pii{i,j});
                del.emplace(pii{i+1,j});
                del.emplace(pii{i+2,j});
                if (r==1) color.emplace(a[i][j]);
            }
            if (a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2]) {
                del.emplace(pii{i,j});
                del.emplace(pii{i,j+1});
                del.emplace(pii{i,j+2});
                if (r==1) color.emplace(a[i][j]);
            }
        }
    }
    bool vis[N][N];
    memset(vis,0,sizeof(vis));
    queue<pii> q;
    _iter(it,del) {
        if (vis[it->first][it->second]) continue;
        vis[it->first][it->second]=true;
        q.emplace(pii{it->first,it->second});
        int cnt=0;
        while (!q.empty()) {
            auto tp=q.front(); q.pop();
            int x=tp.first,y=tp.second;
            cnt++;
            _rep(i,0,3) {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (checkBound(nx,ny) && del.count(pii{nx,ny}) && a[x][y]==a[nx][ny] && !vis[nx][ny]) {
                    vis[nx][ny]=true;
                    q.emplace(pii{nx,ny});
                }
            }
        }
        ans+=50*(cnt-3)*(cnt-3);
    }
    while (true) {
        int sz1=del.size();
        _iter(it,del) extra(del,it->first,it->second);
        int sz2=del.size();
        if (sz1==sz2) break;
    }
    int sum=0;
    _iter(it,del) sum+=a[it->first][it->second],a[it->first][it->second]=0,b[it->first][it->second]=0;
    ans+=sum*r;
    gravity();
    if (check()) update(r+1);
    else ans+=80*(r-1)*(r-1);
}

bool cmp(const pii& a,const pii& b) {
    return a.first<b.first;
}

void award(int pos,int& res) {
    if (pos==5) {
        unordered_map<int,int> cnt;
        _rep(i,0,4) cnt[cur[i]]++;
        vector<pii> vec;
        _iter(it,cnt) vec.emplace_back(pii{it->second,it->first});
        sort(vec.begin(),vec.end(),cmp);
        int sum=0;
        if ((int)vec.size()==5) { // 11111
            int mx=0;
            _rep(i,0,4) mx=max(mx,vec[i].second);
            sum+=50+mx;
        } else if ((int)vec.size()==4) { // 1112
            sum+=100+vec.back().second*2;
        } else if ((int)vec.size()==3) { // 122 / 113
            if (vec.back().first==2) { // 122
                sum+=200+max(vec[1].second,vec[2].second)*2+min(vec[1].second,vec[2].second);
            } else { // 113
                sum+=300+vec.back().second*3;
            }
        } else if ((int)vec.size()==2) { // 23 / 14
            if (vec.back().first==3) { // 23
                sum+=500+vec.back().second*3+vec[0].second;
            } else { // 14
                sum+=750+vec.back().second*5;
            }
        } else { // 5
            sum+=1000+vec.back().second*10;
        }
        res=max(res,sum);
    } else {
        _iter(it,las5[pos]) {
            cur[pos]=(*it);
            award(pos+1,res);
        }
    }
}

bool checkAllClear() {
    _rep(i,1,n) _rep(j,1,m) if (a[i][j]) return false;
    return true;
}

int main() {
    read(n),read(m),read(k),read(q);
    _rep(i,1,n) _rep(j,1,m) read(a[i][j]);
    _rep(i,1,n) _rep(j,1,m) read(b[i][j]);
    bool all_ok=true;
    while (q--) {
        int x1,y1,x2,y2;
        read(x1),read(y1),read(x2),read(y2);
        if (!swap(x1,y1,x2,y2)) {
            all_ok=false;
            continue;
        }
        color.clear();
        update(1);
        las5.emplace_back(color);
        if ((int)las5.size()==5) {
            int res=0;
            award(0,res);
            ans+=res;
            las5.clear();
        }
    }
    if (all_ok) ans+=1000;
    if (checkAllClear()) ans+=10000;
    write(ans);
    return 0;
}