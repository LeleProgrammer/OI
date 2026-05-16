#include <bits/stdc++.h> // 万能头文件 
using namespace std;

// 总共有n块冰川，探测器返回了m条数据 
int n,m;

char s[1000005];

int main() {
	// 输入n和m
	scanf("%d %d",&n,&m); // cin>>n>>m也可以
	int ns=0; // 计算n的个数，用来判定是否有解 
	for (int i=1;i<=m;++i) { // 读入m个字符 
		cin>>s[i];
		if (s[i]=='N') { // 读到了N 
			ns++; // N的数量增加 
		} else { // 读到了S 
			if (i==1) { // 一开头就读到了S，那么无解 
				printf("No solution");
				return 0;
			}
		}
	}
	if (ns>n) { // 探测到的冰川多于n块，无解 
		printf("No solution");
		return 0;
	}
	// 接下来就是有解的情况了
	int now_n=1; // 读到N的时候要输出的冰川编号 
	for (int i=1;i<=m;++i) { // 枚举 
		if (s[i]=='N') { // 读到N，输出 
			printf("%d ",now_n);
			++now_n;
		} else { // 读到S，输出1，使字典序最小 
			printf("1 ");
		}
	}
	return 0;
} 