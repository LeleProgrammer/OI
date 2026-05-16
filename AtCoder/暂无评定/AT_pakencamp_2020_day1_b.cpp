#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
	scanf("%1d %1d %1d %1d",&a,&b,&c,&d);
	printf("%d\n",max(max(max(a,b),c),d));
	return 0;
}