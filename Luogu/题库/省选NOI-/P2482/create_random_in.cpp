#include <bits/stdc++.h>
using namespace std;

const int N = 3,M = 2000,ROLE = 2,CARD = 8; //N为人数，M为卡牌，ROLE为角色种类，CARD为牌种类 
char card[] = {'K','D','P','Z','F','N','W','J'};
char role[] = {'Z','F'};
default_random_engine rander;
uniform_int_distribution <int> rander_card(0,CARD - 1);
uniform_int_distribution <int> rander_role(0,ROLE - 1);
int n = N,m = M;

int main()
{
	freopen("in.in","w",stdout);
	rander.seed(time(0));
	cout << n << ' ' << m << endl;
	cout << "MP ";
	for(int i = 1;i <= 4;i ++) cout << card[rander_card(rander)] << ' ';
	cout << endl;
	cout << "FP ";
	for(int i = 1;i <= 4;i ++) cout << card[rander_card(rander)] << ' ';
	cout << endl;
	n -= 2;
	while (n --)
	{
		char choose_role = rander_role(rander);
		cout << role[choose_role] << "P ";
		for(int i = 1;i <= 4;i ++) cout << card[rander_card(rander)] << ' ';
		cout << endl;
	}
//	*/ 
	m --;
	while (m --) cout << card[rander_card(rander)] << ' ';
	cout << 'F';
	return 0;
}
