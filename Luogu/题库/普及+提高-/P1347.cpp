#include <bits/stdc++.h>
using namespace std;

const int N=35;
const int M=605;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],h[N],tot;
vector<pii> readin;
int in[N];
bool unsure;
bool nosolution;
vector<int> topsort;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topo() {
    unsure=false;
    topsort.clear();
    queue<int> q;
    int cnt=0;
    for (int i=0;i<n;++i) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        if (q.size()>=2) unsure=true;
        int u=q.front(); q.pop(); cnt++;
        topsort.push_back(u);
        for (int i=h[u];~i;i=ne[i]) {
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
    nosolution=false;
    for (int i=0;i<n;++i) {
        if (in[i]) {
            nosolution=true;
            break;
        }
    }
    unsure=unsure?unsure:cnt!=n;
}

int main() {
    scanf("%d %d",&n,&m);
    readin.push_back({114514,1919810});
    for (int i=1;i<=m;++i) {
        char a[3];
        scanf("%s",a);
        readin.push_back({a[0]-'A',a[2]-'A'});
    }
    for (int i=1;i<=m;++i) {
        memset(in,0,sizeof(in));
        memset(h,-1,sizeof(h));
        tot=0;
        for (int j=1;j<=i;++j) {
            add(readin[j].first,readin[j].second);
            in[readin[j].second]++;
        }
        topo();
        if (nosolution) {
            printf("Inconsistency found after %d relations.",i);
            break;
        } else if (!unsure) {
            printf("Sorted sequence determined after %d relations: ",i);
            for (int j=0;j<topsort.size();++j) {
                printf("%c",char(topsort[j]+'A'));
            }
            printf(".");
            break;
        } else if (i==m) {
            printf("Sorted sequence cannot be determined.");
            break;
        }
    }
    return 0;
}