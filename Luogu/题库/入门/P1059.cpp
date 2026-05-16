#include <bits/stdc++.h>
using namespace std;

bool bucket[1001];
vector<int> v;

int main() {
	int n;
	scanf("%d",&n);
	memset(bucket,false,sizeof bucket);
	for (int i=1;i<=n;++i) {
		int val;
		scanf("%d",&val);
		if (!bucket[val]) {
			v.push_back(val);
			bucket[val]=true;
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for (int i=0;i<v.size();++i) {
		printf("%d ",v[i]);
	}
	return 0;
}