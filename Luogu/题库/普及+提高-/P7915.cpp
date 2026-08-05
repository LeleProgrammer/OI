#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=1000005;

int T,n;
int arr[N];
vector<char> ans1,ans2;
deque<int> a,b;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n); n<<=1;
        _rep(i,1,n) scanf("%d",&arr[i]);
        ans1.clear();
        ans2.clear();
        a.clear();
        b.clear();
        int i;
        for (i=2;i<=n;++i) {
            if (arr[i]==arr[1]) break;
            a.emplace_back(arr[i]);
        }
        ++i;
        for (;i<=n;++i) {
            b.emplace_back(arr[i]);
        }
        bool ok=true;
        while (true) {
            if (a.empty() && b.empty()) break;
            if (!a.empty() && !b.empty() && a.front()==b.front()) {
                ans1.push_back('L');
                ans2.push_back('R');
                a.pop_front();
                b.pop_front();
            } else if (a.size()>=2 && a.front()==a.back()) {
                ans1.push_back('L');
                ans2.push_back('L');
                a.pop_front();
                a.pop_back();
            } else if (b.size()>=2 && b.front()==b.back()) {
                ans1.push_back('R');
                ans2.push_back('R');
                b.pop_front();
                b.pop_back();
            } else if (!a.empty() && !b.empty() && a.back()==b.back()) {
                ans1.push_back('R');
                ans2.push_back('L');
                a.pop_back();
                b.pop_back();
            } else {
                ok=false;
                break;
            }
        }
        if (ok) {
            putchar('L');
            _iter(it,ans1) printf("%c",*it);
            _rrep(i,(int)ans2.size()-1,0) printf("%c",ans2[i]);
            putchar('L');
            putchar(10);
            continue;
        }
        a.clear();
        b.clear();
        ans1.clear();
        ans2.clear();
        for (i=n-1;i;--i) {
            if (arr[i]==arr[n]) break;
            a.emplace_back(arr[i]);
        }
        --i;
        for (;i;--i) {
            b.emplace_back(arr[i]);
        }
        ok=true;
        while (true) {
            if (a.empty() && b.empty()) break;
            if (b.size()>=2 && b.front()==b.back()) {
                ans1.push_back('L');
                ans2.push_back('L');
                b.pop_front();
                b.pop_back();
            } else if (!a.empty() && !b.empty() && a.back()==b.back()) {
                ans1.push_back('L');
                ans2.push_back('R');
                a.pop_back();
                b.pop_back();
            } else if (!a.empty() && !b.empty() && a.front()==b.front()) {
                ans1.push_back('R');
                ans2.push_back('L');
                a.pop_front();
                b.pop_front();
            } else if (a.size()>=2 && a.front()==a.back()) {
                ans1.push_back('R');
                ans2.push_back('R');
                a.pop_front();
                a.pop_back();
            } else {
                ok=false;
                break;
            }
        }
        if (ok) {
            putchar('R');
            _iter(it,ans1) printf("%c",*it);
            _rrep(i,(int)ans2.size()-1,0) printf("%c",ans2[i]);
            putchar('L');
            putchar(10);
            continue;
        }
        puts("-1");
    }
    return 0;
}

/*
1
20
5 13 1 3 2 16 7 19 6 18 10 4 4 10 20 18 6 19 7 8 2 14 1 11 17 9 13 5 15 3 16 12 20 12 8 14 15 11 17 9
*/

/*
1
20
3 5 13 2 19 9 20 6 11 4 10 8 7 17 15 1 18 14 16 18 15 17 7 12 8 10 4 11 6 20 9 19 2 13 3 5 1 14 16 12
*/