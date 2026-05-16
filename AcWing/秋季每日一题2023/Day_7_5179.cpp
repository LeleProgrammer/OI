#include <bits/stdc++.h>

using namespace std;

int x,y,g;

unordered_map<string,int> gp; // name,group
vector< pair<string,string> > yes; // want together: name1,name2
vector< pair<string,string> > no; // don't want together: name1,name2

string a,b;

int ans=0;

void IOSinit() {
    cin.tie(0);
    cout.tie(0);
}

int main() {
    IOSinit();
    scanf("%d",&x);
    while (x--) {
        cin>>a>>b;
        yes.push_back(make_pair(a,b));
    }
    scanf("%d",&y);
    while (y--) {
        cin>>a>>b;
        no.push_back(make_pair(a,b));
    }
    scanf("%d",&g);
    for (int i=1;i<=g;++i) {
        for (int j=1;j<=3;++j) {
            cin>>a;
            gp.insert(make_pair(a,i));
        }
    }
    for (pair<string,string> iter:yes) {
        if (gp[iter.first]!=gp[iter.second]) ans++;
    }
    for (pair<string,string> iter:no) {
        if (gp[iter.first]==gp[iter.second]) ans++;
    }
    printf("%d",ans);
    return 0;
}