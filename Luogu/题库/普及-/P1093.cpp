#include <bits/stdc++.h>
using namespace std;

struct stu {
	int score;
	int number;
	int chi,mat,eng;
	friend bool operator < (const stu& a,const stu& b) {
		if (a.score!=b.score) return a.score>b.score;
		if (a.chi!=b.chi) return a.chi>b.chi;
		return a.number<b.number;
	}
} stus[305];

int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		stus[i].chi=a;
		stus[i].mat=b;
		stus[i].eng=c;
		stus[i].number=i;
		stus[i].score=a+b+c;
	}
	sort(stus+1,stus+1+n);
	for (int i=1;i<=5;++i) {
		printf("%d %d\n",stus[i].number,stus[i].score);
	}
	return 0;
}