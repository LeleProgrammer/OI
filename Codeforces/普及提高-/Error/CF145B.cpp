#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;
string ans;

int main() {
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (abs(c-d)>=2 || min(a,b)<max(c,d)) puts("-1");
    else {
        char ca,cb;
        if (c>d) ca='4',cb='7';
        else if (c<d) ca='7',cb='4',swap(a,b),swap(c,d);
        else {
            a--;
            a-=c,b-=c;
            if (a<0 || b<0) {
                puts("-1");
                return 0;
            }
            while (a--) ans.push_back('4');
            for (int i=1;i<=c;++i) {
                ans.push_back('4');
                ans.push_back('7');
            }
            while (b--) ans.push_back('7');
            ans.push_back('4');
            cout<<ans;
            return 0;
        }
        a-=c,b-=c;
        if (a<0 || b<0) {
            puts("-1");
            return 0;
        }
        while (a--) ans.push_back(ca);
        while (c--) ans.push_back(ca),ans.push_back(cb);
        while (b--) ans.push_back(cb);
        cout<<ans;
    }
    return 0;
}

/*
4 7 3 2
44747477777

7474

447774

74474
*/