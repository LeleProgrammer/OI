#include <bits/stdc++.h>
using namespace std;

int n,m;
int v[65];
int w[65];
vector<int> sub[65];
bool flag[65];
int f[32005];

int main() {
    scanf("%d %d",&n,&m);
    int getsub;
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",v+i,w+i,&getsub);
        if (getsub) sub[getsub].push_back(i),flag[i]=false;
        else flag[i]=true;
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=m;++i) {
        for (int j=n;j>=0;--j) {
            if (!flag[i]) continue;
            if (j-v[i]>=0) f[j]=max(f[j],f[j-v[i]]+v[i]*w[i]);
            if (sub[i].size()==1 && j-v[i]-v[sub[i][0]]>=0) f[j]=max(f[j],f[j-v[i]-v[sub[i][0]]]+v[i]*w[i]+v[sub[i][0]]*w[sub[i][0]]);
            if (sub[i].size()==2 && j-v[i]-v[sub[i][0]]>=0) f[j]=max(f[j],f[j-v[i]-v[sub[i][0]]]+v[i]*w[i]+v[sub[i][0]]*w[sub[i][0]]);
            if (sub[i].size()==2 && j-v[i]-v[sub[i][1]]>=0) f[j]=max(f[j],f[j-v[i]-v[sub[i][1]]]+v[i]*w[i]+v[sub[i][1]]*w[sub[i][1]]);
            if (sub[i].size()==2 && j-v[i]-v[sub[i][0]]-v[sub[i][1]]>=0) f[j]=max(f[j],f[j-v[i]-v[sub[i][0]]-v[sub[i][1]]]+v[i]*w[i]+v[sub[i][0]]*w[sub[i][0]]+v[sub[i][1]]*w[sub[i][1]]);
        }
    }
    printf("%d",f[n]);
    return 0;
}