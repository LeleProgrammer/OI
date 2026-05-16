#include <bits/stdc++.h>
using namespace std;

int fibbonacci[31];

int main() {
	fibbonacci[1]=fibbonacci[2]=1;
	for (int i=3;i<=30;++i) {
		fibbonacci[i]=fibbonacci[i-2]+fibbonacci[i-1];
	}
	int n;
	cin>>n;
	for (int i=1;i<=n;++i) {
		int v;
		cin>>v;
		cout<<fibbonacci[v]<<endl;
	}
	return 0;
}