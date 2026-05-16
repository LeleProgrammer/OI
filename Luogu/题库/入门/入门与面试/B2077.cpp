#include <bits/stdc++.h>
using namespace std;

signed main() {
	unsigned long long n;
	cin>>n;
	while (n!=1) {
		if (n%2==1) {
			printf("%llu*%llu+%llu=%llu\n",n,3,1,n*3+1);
			n=n*3+1;
		} else {
			printf("%llu/%llu=%llu\n",n,2,n/2);
			n/=2;
		}
	}
	printf("End");
	return 0;
} 