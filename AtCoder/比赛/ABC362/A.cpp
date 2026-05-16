#include <bits/stdc++.h>
using namespace std;

int r,g,b;
string c;

int main() {
    cin>>r>>g>>b>>c;
    if (c=="Red") printf("%d\n",min(g,b));
    else if (c=="Green") printf("%d\n",min(r,b));
    else printf("%d\n",min(r,g));
    return 0;
}