#include <bits/stdc++.h>
using namespace std;

priority_queue< int,vector<int>,less<int> > q;

int main() {
	int n;
	scanf("%d",&n);
	long long b;
	scanf("%lld",&b);
	for (int i=1;i<=n;++i) {
		long long v;
		scanf("%lld",&v);
		q.push(v);
	}
	int count=0;
	long long height=0;
	while (true) {
		height+=q.top();
		q.pop();
		count++;
		if (height>b) {
			printf("%d",count);
			return 0;
		}
	}
	return 0;
}