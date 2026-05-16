#include <bits/stdc++.h>
using namespace std;

int main() {
    double dis;
    cin>>dis;
    double bike=50+dis/3.0,walk=dis/1.2;
    if (bike>walk) cout<<"Walk";
    else if (bike<walk) cout<<"Bike";
    else cout<<"All";
    return 0;
}