/* TEST */
#include <bits/stdc++.h>
using namespace std;

int maxx=10;
int i;

void a() {
    i=0;
    printf("a\n");
}

bool b() {
    printf("b\n");
    return i<maxx;
}

void c() {
    printf("c\n");
    ++i;
}

int main() {
    for (a();b();c()) {
        printf("main\n");
    }
    return 0;
}