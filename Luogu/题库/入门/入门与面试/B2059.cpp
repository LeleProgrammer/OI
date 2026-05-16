#include <bits/stdc++.h>
using namespace std;

int main() {
	int m,n;
	cin>>m>>n;
	int s=0;
	for (int i=m;i<=n;++i) {
		if (i%2==1) {
			s+=i;
		}
	}
	cout<<s;
	return 0;
}