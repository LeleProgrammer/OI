#include <bits/stdc++.h>
using namespace std;

int main() {
	double m,h;
	cin>>m>>h;
	double res=m/(h*h);
	if (res<18.5) printf("Underweight");
	else if (res>=18.5 && res<24) printf("Normal");
	else cout<<res<<endl<<"Overweight";
	return 0;
} 