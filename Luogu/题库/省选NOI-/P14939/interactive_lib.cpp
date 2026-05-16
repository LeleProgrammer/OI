#include<bits/stdc++.h>
using namespace std;

extern "C" {
	int work(long long n,long long x,long long y);
}

int main() {
    int q;
    long long n,x,y;
    cin>>q;
    while(q--){
        cin>>n>>x>>y;
        cout<<work(n,x,y)<<endl;
    }
	return 0;
}