#include <bits/stdc++.h>
using namespace std;

int q;

// deque->MLE!!!
// list->AC!!!
list<int> dqs[1000005];

string op;
int a,x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>q;
	for (int i=1;i<=q;++i) {
		cin>>op>>a;
		if (op=="push_back") {
			cin>>x;
			dqs[a].push_back(x);
		} else if (op=="pop_back") {
			if (dqs[a].empty()) continue;
			dqs[a].pop_back();
		} else if (op=="push_front") {
			cin>>x;
			dqs[a].push_front(x);
		} else if (op=="pop_front") {
			if (dqs[a].empty()) continue;
			dqs[a].pop_front();
		} else if (op=="size") {
			cout<<dqs[a].size()<<endl;
		} else if (op=="front") {
			if (dqs[a].empty()) continue;
			cout<<dqs[a].front()<<endl;
		} else if (op=="back") {
			if (dqs[a].empty()) continue;
			cout<<dqs[a].back()<<endl;
		}
	}
	return 0;
}