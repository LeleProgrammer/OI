#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define EMPTY(arr) for (int i = 0; i <= 2 * n * m + 5; i++) arr[i] = 0
using namespace std;
const int N = 114514, inf = 0x3f3f3f3f, dict[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
struct Edge {int now, nxt, u, w;} e[1919810];
int head[N], _head[N], cur = 1;
void ad(int u, int v, int w) {e[++cur].now = v, e[cur].nxt = head[u], e[cur].w = w, e[cur].u = u, head[u] = cur;}
void add(int u, int v, int w) {ad(u, v, w), ad(v, u, 0);}

int n, m, s, t; char a[105][105];
void chg(char &x) {x = (x == 'B' ? 'W' : x == 'W' ? 'B' : '?');}
bool black(char v) {return v != 'W';}
bool white(char v) {return v != 'B';}
int black(int x, int y) {return (x - 1) * m + y;}
int white(int x, int y) {return (x - 1) * m + y + n * m;}
bool all_black(int x, int y) {return black(a[x][y]) && black(a[x + 1][y]) && black(a[x][y + 1]) && black(a[x + 1][y + 1]);}
bool all_white(int x, int y) {return white(a[x][y]) && white(a[x + 1][y]) && white(a[x][y + 1]) && white(a[x + 1][y + 1]);}
pair <int, int> toxy(int u) {return (u % m == 0 ? (pair <int, int>){u / m, m} : (pair <int, int>){u / m + 1, u % m});}

namespace Flow {
	int dis[N]; bool vis[N];
	bool bfs()
	{
		queue <int> q; EMPTY(vis);
		q.push(s), vis[s] = true, dis[s] = 0, _head[s] = head[s];
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			for (int i = head[u]; i; i = e[i].nxt)
			{
				int v = e[i].now;
				if (vis[v] || !e[i].w) continue;
				vis[v] = true, dis[v] = dis[u] + 1, q.push(v), _head[v] = head[v];
				if (v == t) return true;
			}
		}
		return false;
	}
	int dfs(int u, int maxflow)
	{
		if (u == t) return maxflow;
		int flow = 0;
		for (int i = _head[u]; i && flow < maxflow; i = e[i].nxt)
		{
			_head[u] = i; int v = e[i].now;
			if (dis[v] != dis[u] + 1 || !e[i].w) continue;
			int ww = dfs(v, min(e[i].w, maxflow - flow));
			if (!ww) dis[v] = -inf;
			e[i].w -= ww, e[i ^ 1].w += ww, flow += ww;
		}
		return flow;
	}
	int dinic()
	{
		int ans = 0;
		while (bfs()) ans += dfs(s, inf);
		return ans;
	}
}
bool flow[N];
void dfs(int u)
{
	flow[u] = true;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].now;
		if (!flow[v] && e[i].w) dfs(v);
	}
}
void solve()
{
	cin >> n >> m, s = 0, t = 2 * n * m + 1;
	cur = 1; EMPTY(head); EMPTY(flow);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			{cin >> a[i][j]; if ((i + j) & 1) chg(a[i][j]);}
	int tot = 0;
	for (int x = 1; x < n; x++)
		for (int y = 1; y < m; y++)
		{
			if (all_black(x, y)) add(s, black(x, y), 1), tot++;
			if (all_white(x, y)) add(white(x, y), t, 1), tot++;
			for (int i = 0; i < 9; i++)
			{
				int dx = x + dict[i][0], dy = y + dict[i][1];
				if (1 <= dx && dx < n && 1 <= dy && dy < m) add(black(x, y), white(dx, dy), inf);
			}
		}
	cout << tot - Flow::dinic() << '\n'; //总数-最小割

	dfs(s);
	for (int i = 2; i <= cur; i += 2)
	{
		int u = e[i].u, v = e[i].now;
		if ((!flow[u] && !flow[v]) || (flow[u] && flow[v])) //两者状态相同，说明中间的边没被割掉
		{
			if (u == s) {auto g = toxy(v); auto x=g.first,y=g.second;         a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 'B';}
			if (v == t) {auto g = toxy(u - n * m); auto x=g.first,y=g.second; a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 'W';}
		}
	}
	for (int i = 1; i <= n; i++, cout << '\n')
		for (int j = 1; j <= m; j++)
			{
				a[i][j] = (a[i][j] == '?' ? 'W' : a[i][j]);
				if ((i + j) & 1) chg(a[i][j]);
				cout << a[i][j];
			}
}
int main()
{
    freopen("P9879.in","r",stdin);
    freopen("P9879.ans","w",stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}