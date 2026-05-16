#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	int a,b,c;
	a=b=c=0;
	for (int i=1;i<=k;++i) {
		int v;
		cin>>v;
		if (v==1) a++;
		if (v==5) b++;
		if (v==10) c++;
	}
	cout<<a<<endl<<b<<endl<<c<<endl;
	return 0;
}