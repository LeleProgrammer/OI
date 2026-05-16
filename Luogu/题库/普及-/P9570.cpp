#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;

vector<int> result;
bool nosolution=false;

void dfs(int done,int now) {
	if (nosolution) return ; // already find no solution
	if (now>=s.size()) return ; // index out of bound
	if (s[now]=='N') { // new ice
		if (done==n) { // but all done
			nosolution=true;
			return ;
		} else { // get new ice
			result.push_back(done+1);
			dfs(done+1,now+1); // search forward
		}
	} else { // old ice
		if (done==0) { // but didn't done any ice
			nosolution=true;
			return ;
		}
		// done some ice
		result.push_back(1);
		dfs(done,now+1); // search forward
	}
	return ;
}

int main() {
	scanf("%d %d",&n,&m);
	cin>>s;
	dfs(0,0);
	if (nosolution) {
		printf("No solution");
	} else {
		for (int i=0;i<result.size();++i) {
			printf("%d ",result[i]);
		}
	}
	return 0;
}