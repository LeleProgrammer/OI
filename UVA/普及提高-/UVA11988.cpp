#include <bits/stdc++.h>
using namespace std;

deque<char> a,b;
deque<char> *c;

int main() {
    string s;
    while (cin>>s) {
        c=&a;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='[') {
                while (!a.empty()) {
                    b.push_front(a.back());
                    a.pop_back();
                }
                c=&a;
            } else if (s[i]==']') {
                c=&b;
            } else {
                c->push_back(s[i]);
            }
        }
        while (!a.empty()) {
            printf("%c",a.front()); a.pop_front();
        }
        while (!b.empty()) {
            printf("%c",b.front()); b.pop_front();
        }
        putchar(10);
    }
    return 0;
}