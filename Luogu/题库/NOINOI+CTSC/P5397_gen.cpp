#include<bits/stdc++.h>
#define P pair<int,int>
#define fi first
#define se second
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=1e5+5;
mt19937 rnd(time(0));
int n=20;
int main()
{
	freopen("1.in","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<n<<" "<<n<<"\n";
	for(int i=1;i<=n;i++) cout<<(rnd()%n+1)<<" ";cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		int o=(rnd()&1)+1,x=rnd()%n+1,y=rnd()%n+1;
//		if(rnd()%10==0) y=x;
		cout<<o<<" "<<x<<" "<<y<<"\n";
	}
	return 0;
}