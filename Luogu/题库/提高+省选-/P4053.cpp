#include <bits/stdc++.h>
#define i64 long long
#define i32 int
#define il inline
#define vd void
#define rt return

using namespace std;

struct node {
	i64 t1;
	i64 t2;
	friend bool operator < (const node& a,const node& b) {
		return a.t2<b.t2;
	}
};
node nodes[150005];

i32 n;

priority_queue<i64> pq;

il vd read() {
	scanf("%d",&n);
	for (i32 i=1;i<=n;++i) {
		scanf("%lld %lld",&nodes[i].t1,&nodes[i].t2);
	}
	rt;
}

i32 main() {
	read();
	sort(nodes+1,nodes+1+n);
	i64 nowtime=0LL;
	i64 result=0LL;
	for (int i=1;i<=n;++i) {
		nowtime+=nodes[i].t1;
		pq.push(nodes[i].t1);
		result++;
		if (nowtime>nodes[i].t2) {
			nowtime-=pq.top();
			pq.pop();
			result--;
		}
	}
	printf("%lld",result);
	rt 0;
}

/*
4
100 200       100,100
200 1300     1100,200
1000 1250     250,1000
2000 3200    1200,2000
*/