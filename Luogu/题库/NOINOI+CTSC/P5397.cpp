#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define rint register int

using namespace std;

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
        }
        c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using IO::read;
using IO::write;

const int N=100001;
const int M=440;
const int K=440;
const int inf=1e6;
const short shortinf=32000;

int n,m,len,bk;
int arr[N];
short to[N][M];
short dis[M][K][K];
int fir[M][K];
int las[M][K];
int L[M],R[M],B[N];
int last;
vector<int> lsh[M];
int sz[M];

inline int get(int x) {
	return (x-1)/len;
}

inline int getl(int x) {
	return x*len+1;
}

inline int getr(int x) {
	return min(getl(x+1)-1,n);
}

inline bool cmp(const int& a,const int& b) {
    return a<b;
}

inline void initLR() {
	for (int i=1;i<=n;++i) {
		B[i]=get(i);
	}
	for (rint i=0;i<bk;++i) {
		L[i]=getl(i);
		R[i]=getr(i);
	}
}

int toxi,toyi,maxx,maxy,ans;

inline void init() {
    memset(to,-1,sizeof(to));
	// for (rint i=0;i<M;++i) {
	// 	for (rint j=0;j<K;++j) {
	// 		for (rint k=0;k<K;++k) {
	// 			dis[i][j][k]=shortinf;
	// 		}
	// 		fir[i][j]=inf;
	// 		las[i][j]=-inf;
	// 	}
	// }
	memset(dis,0x7f,sizeof(dis));
	memset(fir,0x7f,sizeof(fir));
	memset(las,-0x7f,sizeof(las));
    for (rint i=0;i<bk;++i) {
        for (rint j=L[i];j<=R[i];++j) {
            lsh[i].push_back(arr[j]);
        }
        sort(lsh[i].begin(),lsh[i].end(),cmp);
        lsh[i].erase(unique(lsh[i].begin(),lsh[i].end()),lsh[i].end());
        for (rint j=L[i];j<=R[i];++j) {
            rint tmp=lower_bound(lsh[i].begin(),lsh[i].end(),arr[j])-lsh[i].begin();
            to[arr[j]][i]=tmp;
            fir[i][tmp]=min(fir[i][tmp],j);
            las[i][tmp]=max(las[i][tmp],j);
        }
		sz[i]=lsh[i].size();
    }
	for (rint i=0;i<bk;++i) {
		for (rint j=L[i];j<=R[i];++j) {
			for (rint k=j;k<=R[i];++k) {
				dis[i][to[arr[j]][i]][to[arr[k]][i]]=min(dis[i][to[arr[j]][i]][to[arr[k]][i]],(short)abs(k-j));
				dis[i][to[arr[k]][i]][to[arr[j]][i]]=dis[i][to[arr[j]][i]][to[arr[k]][i]];
			}
		}
	}
}

inline void modify(int x,int y) {
	if (x==y) return;
	for (rint i=0;i<bk;++i) {
		toxi=to[x][i];
		toyi=to[y][i];
		if (!~toxi) continue;
		if (!~toyi) {
			to[y][i]=toxi,to[x][i]=-1;
		} else {
			fir[i][toyi]=min(fir[i][toyi],fir[i][toxi]);
			las[i][toyi]=max(las[i][toyi],las[i][toxi]);
			fir[i][toxi]=inf,las[i][toxi]=-inf;
			for (rint j=0;j<sz[i];++j) {
				rint k=j;
				if (!~k) continue;
				if (toxi==k) continue;
				dis[i][toyi][k]=min(dis[i][toyi][k],dis[i][toxi][k]);
                dis[i][k][toyi]=dis[i][toyi][k];
			}
			to[x][i]=-1;
		}
	}
}

inline int query(int x,int y) {
	maxx=-1;
	maxy=-1;
	ans=inf;
	for (rint i=0;i<bk;++i) {
		toxi=to[x][i];
		toyi=to[y][i];
		if (~toxi) {
			if (~maxy && fir[i][toxi]!=inf && fir[i][toxi]>=maxy) ans=min(ans,fir[i][toxi]-maxy);
		}
		if (~toyi) {
			if (~maxx && fir[i][toyi]!=inf && fir[i][toyi]>=maxx) ans=min(ans,fir[i][toyi]-maxx);
		}
		maxx=max(maxx,~toxi?las[i][toxi]:-inf);
		maxy=max(maxy,~toyi?las[i][toyi]:-inf);
        if (~toxi && ~toyi) {
            if (dis[i][toxi][toyi]<=len) ans=min(ans,(int)dis[i][toxi][toyi]);
		    if (dis[i][toyi][toxi]<=len) ans=min(ans,(int)dis[i][toyi][toxi]);
        }
        if (ans<=1) break;
	}
	return (!~maxx || !~maxy || ans==inf)?-1:ans;
}

int main() {
	read(n); read(m);
	len=229; bk=n/len; if (n%len) bk++;
	for (rint i=1;i<=n;++i) {
		read(arr[i]);
	}
	initLR();
	init();
	while (m--) {
		rint op,x,y;
		read(op); read(x); read(y);
		x^=last;
		y^=last;
		if (op==1) {
			if (x==y) continue;
			modify(x,y);
		} else {
			rint ans=query(x,y);
			if (!~ans) {
				last=0;
				puts("Ikaros");
			} else {
				printf("%d\n",last=ans);
			}
		}
	}
	return 0;
}

/*
5 5
1 2 2 4 4
2 3 3
x=3, y=3, Ikaros, last=0
2 2 4
x=2, y=4, 1, last=1
1 3 2
x=2, y=3, none, last=1
array: 1 3 3 4 4
1 5 5
x=4, y=4, none, last=1
array: 1 3 3 4 4
2 2 5
x=3, y=4, 1, last=1
*/