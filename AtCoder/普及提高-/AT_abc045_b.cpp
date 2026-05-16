#include <bits/stdc++.h>
using namespace std;

string ina,inb,inc;
queue<char> a,b,c;

int main() {
    cin>>ina>>inb>>inc;
    for (char ch:ina) a.push(ch);
    for (char ch:inb) b.push(ch);
    for (char ch:inc) c.push(ch);
    int now=0;
    while (true) {
        queue<char>& d=now==0?a:(now==1?b:c);
        if (d.empty()) break;
        char t=d.front(); d.pop();
        now=t-'a';
    }
    printf("%c\n",now+'A');
    return 0;
}