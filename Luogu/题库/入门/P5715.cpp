#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int aaa[3]={a,b,c};
	sort(aaa,aaa+3);
	printf("%d %d %d",aaa[0],aaa[1],aaa[2]);
	return 0;
}