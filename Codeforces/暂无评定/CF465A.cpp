#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int sum=0;
	cin>>n;
	for (int i=1;i<=n;++i) {
		int digit;
		scanf("%1d",&digit);
		if (digit==1) {
			sum++;
		} else {
			sum++;
			break;
		}
	}
	printf("%d",sum);
	return 0;
}