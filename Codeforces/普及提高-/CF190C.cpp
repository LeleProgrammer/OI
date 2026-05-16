#include <bits/stdc++.h>
using namespace std;

int tmp;
stringstream ss;
bool bad=false;

void dfs() {
    if (bad) return;
    string text;
    if (!(cin>>text)) {
        bad=true;
        cout<<"Error occurred";
        return;
    }
    if (text=="int") ss<<text;
    else {
        ss<<text<<"<";
        dfs();
        if (bad) return;
        ss<<",";
        dfs();
        if (bad) return;
        ss<<">";
    }
    return;
}

int main() {
    scanf("%d",&tmp);
    dfs();
    string check;
    if (cin>>check) {
        bad=true;
        cout<<"Error occurred";
    }
    if (!bad) {
        string out;
        ss>>out;
        cout<<out;
    }
    return 0;
}