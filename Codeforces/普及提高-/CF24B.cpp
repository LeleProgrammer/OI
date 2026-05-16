#include <bits/stdc++.h>
using namespace std;

int ss[55]={25,18,15,12,10,8,6,4,2,1,0};

int n,m;
string driver;

struct f1 {
    string name;
    int score;
    int ranks[55];
};

bool cmp_solution_1(const f1& a,const f1& b) {
    if (a.score==b.score) {
        for (int i=0;i<50;++i) {
            if (a.ranks[i]!=b.ranks[i]) {
                return a.ranks[i]>b.ranks[i];
            }
        }
    } else {
        return a.score>b.score;
    }
}

bool cmp_solution_2(const f1& a,const f1& b) {
    if (a.ranks[0]==b.ranks[0]) {
        if (a.score==b.score) {
            for (int i=1;i<50;++i) {
                if (a.ranks[i]!=b.ranks[i]) {
                    return a.ranks[i]>b.ranks[i];
                }
            }
        } else {
            return a.score>b.score;
        }
    } else {
        return a.ranks[0]>b.ranks[0];
    }
}

unordered_map<string,f1> scores;

vector<f1> res;

void IOSinit() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    IOSinit();
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>m;
        for (int j=0;j<m;++j) {
            cin>>driver;
            unordered_map<string,f1>::iterator iter=scores.find(driver);
            if (iter==scores.end()) {
                f1 f;
                f.name=driver;
                f.score=ss[j];
                memset(f.ranks,0,sizeof(f.ranks));
                f.ranks[j]++;
                scores.insert(make_pair(driver,f));
            } else {
                scores[driver].score+=ss[j];
                scores[driver].ranks[j]++;
            }
        }
    }
    for (unordered_map<string,f1>::iterator iter=scores.begin();iter!=scores.end();++iter) {
        res.push_back(iter->second);
    }
    sort(res.begin(),res.end(),cmp_solution_1);
    cout<<res[0].name<<endl;
    sort(res.begin(),res.end(),cmp_solution_2);
    cout<<res[0].name<<endl;
    return 0;
}