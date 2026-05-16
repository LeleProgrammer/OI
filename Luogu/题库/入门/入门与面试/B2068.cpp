#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int sum=0;
	cin>>n;
	for (int i=1;i<=n;++i) {
		int num;
		cin>>num;
		int a,b,c,d;
		a=num/1000;
		b=num%1000/100;
		c=num%1000%100/10;
		d=num%10;
		if (d-a-b-c>0) {
			sum++;
		}
	}
	cout<<sum;
	return 0;
}