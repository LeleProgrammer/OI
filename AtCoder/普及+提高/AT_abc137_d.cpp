#include <bits/stdc++.h>
#define i64 long long
#define i32 int
#define il inline
#define vd void
#define rt return
#define prque priority_queue

const int MAXN=1e5+100;

using namespace std;

i64 n,m;
i64 result=0LL;

struct node {
	i64 a;
	i64 b;
	friend bool operator < (const node& a,const node& b) {
		rt a.a<b.a;
	}
};

node nodes[MAXN];

il vd read() {
	scanf("%lld %lld",&n,&m);
	for (i64 i=1;i<=n;++i) {
		scanf("%lld %lld",&nodes[i].a,&nodes[i].b);
	}
	rt;
}

prque<i32> pq;

i32 main() {
	read();
	sort(nodes+1,nodes+1+n);
	i64 i=1;
	for (i64 now=1;now<=m;++now) {
		while (true) {
			if (i<=n && nodes[i].a<=now) {
				pq.push(nodes[i].b);
				i++;
			} else {
				break;
			}
		}
		if (!pq.empty()) {
			result+=pq.top();
			pq.pop();
		}
	}
	printf("%lld",result);
	return 0;
}

/*

3 4
4 3
4 1
2 2

1 3
3 2
1 1

5 3
1 2
1 3
1 4
2 1
2 3

3 4
2 3
3 3
3 2
2 1

*/