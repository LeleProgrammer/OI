#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10, inf = 2e18;

int n, m, k;

void sol()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	int t = 0;
	if (n < m) swap(n, m), t = 1;
	if (n < k)
	{
		puts("-1");
		return;
	} 
	if ((n + k - 1) / k > (m + k - 1) / k + 1 || (n + k - 1) / k < (m + k - 1) / k)
	{
		puts("-1");
		return;
	}
	if ((n + k - 1) / k == (m + k - 1) / k + 1)
	{
		int a = n % k, b = m % k;
		if (!a) a = k;
		if (!b) b = k;
		if (a > b)
		{
			puts("-1");
			return;
		}
	}
	while (n || m)
	{
		if (n > 0) for (int i = 0; i < k && n; i++, n--) putchar('0' ^ t);
		if (m > 0) for (int i = 0; i < k && m; i++, m--) putchar('0' ^ t ^ 1);
	}
	puts("");
}

signed main()
{
	int T = 1;
	scanf("%lld", &T);
	while (T--) sol(); 
	return 0;
}