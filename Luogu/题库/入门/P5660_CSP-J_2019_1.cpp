#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int c=0;
	for (int i=0;i<s.length();++i) {
		if (s.c_str()[i]-'0'==1) {
			++c;
		}
	}
	cout<<c;
	return 0;
}