#include <bits/stdc++.h>
using namespace std;

char s[500005];
int n,q,op,x,c;

vector< pair< int,char > > operations;
int flag=0;

int main() {
	scanf("%d",&n);
	cin>>s+1;
	scanf("%d",&q);
	for (int i=1;i<=q;++i) {
		scanf("%d %d %c",&op,&x,&c);
		if (op==1) {
			s[x]=c;
			operations.push_back(make_pair(x,c));
		} else {
			operations.clear();
			flag=op;
		}
	}
	if (flag==2) {
		for (int i=1;i<=n;++i) {
			if (isupper(s[i])) {
				s[i]=s[i]-'A'+'a';
			}
		}
	} else if (flag==3) {
		for (int i=1;i<=n;++i) {
			if (islower(s[i])) {
				s[i]=s[i]-'a'+'A';
			}
		}
	} else {
		for (int i=1;i<=n;++i) printf("%c",s[i]);
		return 0;
	}
	for (int i=0;i<operations.size();++i) {
		s[operations[i].first]=operations[i].second;
	}
	for (int i=1;i<=n;++i) printf("%c",s[i]);
	return 0;
}