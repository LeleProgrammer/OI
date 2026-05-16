#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,m,s;
	cin>>m>>t>>s;
	if (t==0) {cout<<0;return 0;}
	int res=m-s/t-((s%t)?1:0);
	if (res<0) res=0;
	cout<<res;
	return 0;
}