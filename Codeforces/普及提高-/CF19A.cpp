#include <bits/stdc++.h>
using namespace std;

int n;

struct team {
    string name;
    int score;
    int goal;
    int clear_goal;
    friend bool operator < (const team& a,const team& b) {
        if (a.score==b.score) {
            if (a.clear_goal==b.clear_goal) {
                return a.goal>b.goal;
            } else {
                return a.clear_goal>b.clear_goal;
            }
        } else {
            return a.score>b.score;
        }
    }
};

bool cmp(const team& a,const team& b) {
    return a.name<b.name;
}

unordered_map<string,team> tms;

vector<team> res;

vector<team> ans;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        team t;
        t.name=s;
        t.goal=t.clear_goal=t.score=0;
        tms.insert(make_pair(s,t));
    }
    for (int i=1;i<=n*(n-1)/2;++i) {
        string s1="",s2="";
        char c;
        bool start=false;
        while (true) {
            c=getchar();
            if (!start && !isalpha(c)) continue;
            if (isalpha(c)) start=true;
            if (!isalpha(c)) break;
            else s1+=c;
        }
        start=false;
        while (true) {
            c=getchar();
            if (!start && !isalpha(c)) continue;
            if (isalpha(c)) start=true;
            if (!isalpha(c)) break;
            else s2+=c;
        }
        int i1=0,i2=0;
        start=false;
        while (true) {
            c=getchar();
            if (!start && !isdigit(c)) continue;
            if (isdigit(c)) start=true;
            if (!isdigit(c)) break;
            else i1=i1*10+(c-'0');
        }
        start=false;
        while (true) {
            c=getchar();
            if (!start && !isdigit(c)) continue;
            if (isdigit(c)) start=true;
            if (!isdigit(c)) break;
            else i2=i2*10+(c-'0');
        }
        tms[s1].clear_goal+=i1-i2;
        tms[s1].goal+=i1;
        tms[s2].clear_goal+=i2-i1;
        tms[s2].goal+=i2;
        if (i1>i2) tms[s1].score+=3;
        else if (i2>i1) tms[s2].score+=3;
        else tms[s1].score++,tms[s2].score++;
    }
    for (unordered_map<string,team>::iterator iter=tms.begin();iter!=tms.end();++iter) {
        res.push_back(iter->second);
    }
    sort(res.begin(),res.end());
    for (int i=0;i<=n/2-1;++i) {
        ans.push_back(res[i]);
    }
    sort(ans.begin(),ans.end(),cmp);
    for (int i=0;i<ans.size();++i) {
        cout<<ans[i].name<<endl;
    }
    return 0;
}

/*
4
A
B
C
D
A-B 1:1
A-C 2:2
A-D 1:0
B-C 1:0
B-D 0:3
C-D 0:3

A 5
B 4
C 1
D 6
*/