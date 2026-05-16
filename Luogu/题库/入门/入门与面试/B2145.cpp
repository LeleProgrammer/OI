#include <bits/stdc++.h>
using namespace std;

int n,k;

int digit(int n,int k) {
	int res;
	for (int i=1;i<=k;++i) {
		res=n%10;
		n/=10;
	}
	return res;
}

int main() {
	cin>>n>>k;
	cout<<digit(n,k);
	return 0;
} 