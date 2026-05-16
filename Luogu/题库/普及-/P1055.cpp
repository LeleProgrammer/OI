#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int sum=0;
	int j=0;
	for (int i=0;i<9;) {
		if (isdigit(s.c_str()[j])) {
			sum+=(s.c_str()[j]-'0')*(i+1);
			++i;
		}
		++j;
	}
	if (s.c_str()[s.length()-1]-'0'==(sum%11<10?sum%11:'X'-'0')) {
		cout<<"Right";
	} else {
		for (int i=0;i<s.length()-1;++i) {
			cout<<s[i];
		}
		if (sum%11<10) {
			cout<<sum%11;
		} else {
			cout<<"X";
		}
	}
	return 0;
}