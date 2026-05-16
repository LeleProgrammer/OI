#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a,b,c,s;
	a=b=c=s=0;
	for (int i=1;i<=n;++i) {
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		a+=aa;b+=bb;c+=cc;s+=aa+bb+cc;
	}
	printf("%d %d %d %d",a,b,c,s);
	return 0;
}