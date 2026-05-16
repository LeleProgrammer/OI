#include <bits/stdc++.h>
using namespace std;

unordered_set<string> words;
vector<string> sorted;

char c;
string word="";

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    while (scanf("%c",&c)!=EOF) {
        if (isalpha(c)) {
            if (c>='A' && c<='Z') c=c-'A'+'a';
            word.push_back(c);
        } else {
            if (!word.size()) continue;
            words.insert(word);
            word="";
        }
    }
    for (unordered_set<string>::iterator iter=words.begin();iter!=words.end();++iter) {
        sorted.push_back(*iter);
    }
    sort(sorted.begin(),sorted.end());
    for (int i=0;i<sorted.size();++i) {
        cout<<sorted[i]<<endl;
    }
    return 0;
}