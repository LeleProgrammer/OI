#include <bits/stdc++.h>
using namespace std;

vector<int> result;

int main() {
	int x,y;
	cin>>x>>y;
	for (int i=x;i<=y;++i) {
		if (i%100==0 && i%400==0 || i%4==0 && i%100!=0) {
			result.push_back(i);
		}
	}
	printf("%d\n",result.size());
	for (int i=0;i<result.size();++i) {
		printf("%d ",result[i]);
	}
	return 0;
} 