#include <bits/stdc++.h>
using namespace std;

struct student {
	string name;
	int y;
	int m;
	int d;
};

student students[100];

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i) {
		cin>>students[i].name;
		scanf("%d %d %d",
			&(students[i].y),
			&(students[i].m),
			&(students[i].d));
	}
	for (int i=0;i<n;++i) {
		for (int j=0;j<n-1;++j) {
			if (students[j].y>students[j+1].y) {
				swap(students[j],students[j+1]);
			} else if (students[j].y==students[j+1].y) {
				if (students[j].m>students[j+1].m) {
					swap(students[j],students[j+1]);
				} else if (students[j].m>students[j+1].m) {
					if (students[j].d>=students[j+1].d) {
						swap(students[j],students[j+1]);
				}
			}
		}
	}
	for (int i=0;i<n;++i) {
		cout<<students[i].name<<endl;
	}
	return 0;
}