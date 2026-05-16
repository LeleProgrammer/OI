#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int arr[3]={a,b,c};
	sort(arr,arr+3);
	string s;
	cin>>s;
	for (int i=0;i<3;++i) {
		if (s[i]=='A') cout<<arr[0]<<" ";
		else if (s[i]=='B') cout<<arr[1]<<" ";
		else if (s[i]=='C') cout<<arr[2]<<" ";
	}
	return 0;
} 