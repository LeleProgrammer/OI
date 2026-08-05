#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,cow;
int sum=0;

stack<int> stk;

signed main() {
	scanf("%lld",&n);
	for (int i=1;i<=n;++i) {
		scanf("%lld",&cow);
		if (stk.empty()) {
			stk.push(cow);
			continue;
		}
		if (stk.top()>cow) {
			sum+=stk.size();
			stk.push(cow);
			continue;
		} else {
			while (!stk.empty()) {
				if (stk.top()>cow) {
					break;
				}
				stk.pop();
			}
			sum+=stk.size();
			stk.push(cow);
			continue;
		}
	}
	printf("%lld",sum);
	return 0;
}