#include <bits/stdc++.h>
using namespace std;

#ifndef record_num
#define record_num num=num*10+c-'0';
#endif

#ifndef _top
#define _top s.top()
#endif

#ifndef _pop
#define _pop s.pop()
#endif

stack<int> s;

int main() {
    char c;
    int num=0;
    int a,b;
    while (true) {
        c=getchar();
        if (isdigit(c)) {
            record_num;
        } else if (c=='.') {
            s.push(num);
            num=0;
        } else if (c=='@') {
            break;
        } else if (c=='+') {
            b=_top;
            _pop;
            a=_top;
            _pop;
            s.push(a+b);
        } else if (c=='-') {
            b=_top;
            _pop;
            a=_top;
            _pop;
            s.push(a-b);
        } else if (c=='*') {
            b=_top;
            _pop;
            a=_top;
            _pop;
            s.push(a*b);
        } else if (c=='/') {
            b=_top;
            _pop;
            a=_top;
            _pop;
            s.push(a/b);
        }
    }
    printf("%d",_top);
    return 0;
}