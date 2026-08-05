#include <bits/stdc++.h>
using namespace std;

struct ant {
    int pos;
    int face; // -1 and 1, left and right;
};

int n;
ant ants;

int main() {
    scanf("%d",&n);
    int input;
    for (int i=0;i<n;++i) {
        scanf("%d",&input);
        ant new_ant;
        new_ant.pos=abs(input);
        new_ant.face=input>0?1:-1;
    }
}