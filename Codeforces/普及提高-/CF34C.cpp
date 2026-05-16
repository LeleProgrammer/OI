#include <bits/stdc++.h>
using namespace std;

set<int> tmp;
vector<int> arr;
string in;
int readin,last,from;
bool have_comma;

int main() {
    cin>>in;
    readin=0;
    for (int i=0;i<in.size();++i) {
        if (isdigit(in[i])) {
            readin=readin*10+in[i]-'0';
        } else {
            tmp.insert(readin);
            readin=0;
        }
    }
    if (readin) {
        tmp.insert(readin);
        readin=0;
    }
    for (set<int>::iterator iter=tmp.begin();iter!=tmp.end();++iter) {
        arr.push_back(*iter);
    }
    sort(arr.begin(),arr.end(),less<int>());
    last=arr[0];
    from=last;
    have_comma=false;
    for (int i=1;i<arr.size();++i) {
        if (last+1==arr[i]) {
            last++;
        } else {
            if (have_comma) printf(",");
            if (from==last) {
                printf("%d",last);
            } else {
                printf("%d-%d",from,last);
            }
            last=arr[i];
            from=last;
            have_comma=true;
        }
    }
    if (have_comma) printf(",");
    if (from==last) {
        printf("%d",last);
    } else {
        printf("%d-%d",from,last);
    }
    return 0;
}