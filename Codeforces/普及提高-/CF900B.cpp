#include <bits/stdc++.h>
using namespace std;

string ina;
int b,c;
int a[100005]={0};
bool mods[100005]={0};
int ys,r;

int main() {
    cin>>ina>>b>>c;
    for (int i=0;i<ina.size();++i) a[i+1]=ina[i]-'0';
    r=0; ys=0;
    for (int i=1;i<100000;++i,r%=b) {
        r=r*10+a[i];
        ys=r%b;
        if (i<=ina.size()) continue;
        if (r/b==c) {
            printf("%d",i-ina.size());
            return 0;
        }
        if (mods[ys]) {
            printf("-1");
            return 0;
        } else mods[ys]=true;
    }
    printf("-1");
    return 0;
}