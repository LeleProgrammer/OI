#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int maxx=-0x7fffffff;
	for (int i=1;i<=n;++i) {
		int v;
		cin>>v;
		maxx=max(maxx,v);
	}
	cout<<maxx;
	return 0;
}