#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if ((a>=60)+(b>=60)+(c>=60)>=2) cout<<"PASS"<<endl;
    else cout<<"FAIL"<<endl;
    if ((a*d+b*e+c*f)/(d+e+f)>=60) cout<<"PASS"<<endl;
    else cout<<"FAIL"<<endl;
    return 0;
}