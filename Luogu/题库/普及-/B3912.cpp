#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN=100005;
const int MAXK=5005;

int k,n,p,pt;
vector<int> pts[MAXN]; // belongs to which subtask(s)
int subtask[MAXK]; // a subtask's answer
int scores[MAXK]; // a subtask's score
unordered_map< int,int > hs; // an answer to fill in , how many scores can get

signed main() {
    scanf("%lld",&k);
    for (int i=1;i<=k;++i) {
        scanf("%lld",&p);
        for (int j=1;j<=p;++j) {
            scanf("%lld",&pt);
            pts[pt].push_back(i);
        }
        scanf("%lld",&scores[i]);
    }
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&pt);
        for (int j=0;j<pts[i].size();++j) {
            if (!subtask[pts[i][j]]) subtask[pts[i][j]]=pt;
            else if (subtask[pts[i][j]]!=pt) subtask[pts[i][j]]=-1;
        }
    }
    for (int i=1;i<=k;++i) {
        if (subtask[i]==-1) continue;
        if (hs.find(subtask[i])==hs.end()) hs.insert(make_pair(subtask[i],scores[i]));
        else hs[subtask[i]]+=scores[i];
    }
    int maxx=0,ans=0;
    for (auto it=hs.begin();it!=hs.end();++it) {
        if (it->second>maxx) {
            maxx=it->second;
            ans=it->first;
        }
    }
    printf("%lld\n%lld",maxx,ans);
    return 0;
}