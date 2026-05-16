#include <bits/stdc++.h>
using namespace std;

bool is_rn(int year) {
    if (year%100==0) {
        if (year%400==0) {
            return true;
        } else {
            return false;
        }
    } else if (year%4==0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int y,m;
    bool rn;
    scanf("%d %d",&y,&m);
    rn=is_rn(y);
    switch (m) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12: {
            printf("31");
            break;
        }
        case 4: case 6: case 9: case 11: {
            printf("30");
            break;
        }
        case 2: {
            if (rn) {
                printf("29");
            } else {
                printf("28");
            }
            break;
        }
        default: {
            break;
        }
    }
    return 0;
}