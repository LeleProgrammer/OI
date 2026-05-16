#include <bits/stdc++.h>
using namespace std;

long double n;

int main() {
    cin>>n;
    if (n>=-128 && n<=127) cout<<"byte";
    else if (n>=-32768 && n<=32767) cout<<"short";
    else if (n>=-2147483648 && n<=2147483647) cout<<"int";
    else if (n>=-(9223372036854775808) && n<=9223372036854775807) cout<<"long";
    else cout<<"BigInteger";
    return 0;
}