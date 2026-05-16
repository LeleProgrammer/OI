#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b,p,s;

int qpow(int power,int base) {
	if (power==1) {
		return base%p;
	}
	if (power%2==0) {
		int a=qpow(power/2,base)%p;
		return a*a%p;
	} else {
		return qpow(power-1,base)*base%p;
	}
}

signed main() {
	cin>>a>>b>>p;
	s=qpow(b,a)%p;
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<s;
	return 0;
}