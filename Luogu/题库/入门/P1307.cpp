#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
	int n;
	cin>>n;
	bool neg;
	if (n<0) neg=true,n*=-1;
	else neg=false;
	int res=0;
	while (n) {
		res=res*10+(n%10);
		n/=10;
	}
	if (neg) res*=-1;
	cout<<res;
	return 0;
}