#include<bits/stdc++.h>

using namespace std;
//P1114 
/*
boy:1
girl:-1
利用一个前缀和数组，sum[i]存储1-i男生和女生的数值和，sum[i]=0&&i%2==0说明1-i男女均等
所以我们要找区间i-j范围，sum[i]=sum[j],max(i,j)
在存储sum[i]值的同时记录第一次出现这个值的位置，再次遇到的话说明result=max(result,(i,j)); 

*/ 
int sum[100001];
int a[100001];
int tp[200010][2];//记录是否出现以及出现时候的区间。 
int n;
int ans=0;
inline int maxs(int a,int b)
{
	return a>b?a:b;
} 
int main()
{
	scanf("%d",&n);
	tp[n][0]=1; 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0){
			a[i]=-1;
		} 
		
		sum[i]=sum[i-1]+a[i];//计算前缀和 
		
		if(tp[sum[i]+n][0]==0)
		{
			tp[sum[i]+n][0]=1;
			tp[sum[i]+n][1]=i;
		}
		else	
		ans=maxs(ans,i-tp[sum[i]+n][1]);
		} 
	printf("%d",ans);
	return 0;
} 