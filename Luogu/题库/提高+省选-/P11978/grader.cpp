#include "railroad.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

static const int SEED = 2021;

static void shuffle(std::vector<int> &v) {
	srand(SEED);
	std::random_shuffle(v.begin(), v.end());
}

static void shuffle(std::vector<std::pair<int, int> > &v) {
	srand(SEED);
	std::random_shuffle(v.begin(), v.end());
}

static void print(std::vector<std::pair<int, int> > &v) {
	printf("[");
	for (int i = 0; i < (int)v.size(); i++) {
		printf("(%d, %d)", v[i].first, v[i].second);
		if (i + 1 < (int)v.size()) printf(", ");
	}
	printf("]\n");
}

bool cmp(const pair<int,int>& a,const pair<int,int>& b) {
	if (a.first!=b.first) return a.first<b.first;
	else return a.second<b.second;
}

static void run_test() {
	int N, K;
	scanf("%d %d", &N, &K);

	std::vector<std::pair<int, int> > E;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		E.emplace_back(a, b);
	}
	cout<<"in: "; print(E);
	vector<pair<int,int>> inp=E;

	int X = 0;
	std::vector<std::pair<int, int> > edges = encode_map(N, K, X, E);
	print(edges);

	for (auto &i : edges) E.emplace_back(i);
	shuffle(E);

	std::vector<int> P(N), inv(N);
	for (int i = 0; i < N; i++) P[i] = i;
	shuffle(P);
	for (int i = 0; i < N; i++) inv[P[i]] = i;

	for (auto &i : E) {
		i.first = P[i.first - 1] + 1;
		i.second = P[i.second - 1] + 1;
	}

	edges = decode_map(N, K, P[X - 1] + 1, E);
	for (auto &i : edges) {
		i.first = inv[i.first - 1] + 1;
		i.second = inv[i.second - 1] + 1;
	}
	print(edges);

	vector<pair<int,int>> oup=edges;
	for (int i=0;i<inp.size();++i) if (inp[i].first>inp[i].second) swap(inp[i].first,inp[i].second);
	for (int i=0;i<oup.size();++i) if (oup[i].first>oup[i].second) swap(oup[i].first,oup[i].second);
	sort(inp.begin(),inp.end(),cmp);
	sort(oup.begin(),oup.end(),cmp);
	if (inp==oup) puts("Accepted");
	else puts("Wrong Answer");
}

int main() {
	freopen("test.out","w",stdout);
	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; i++) {
		run_test();
	}
	return 0;
}