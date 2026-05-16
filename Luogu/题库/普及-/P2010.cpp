#include <bits/stdc++.h>
using namespace std;

bool is_reversed(int y,int m,int d) {
    string s;
    s+=to_string(y);
    s+=m>=10?to_string(m):("0"+to_string(m));
    s+=d>=10?to_string(d):("0"+to_string(d));
    if (s.size()%2==0) {
        // 偶数长度
        int mid=s.size()/2;
        int l=0,r=s.size()-1;
        while (true) {
            if (s[l]!=s[r]) {
                return false;
            }
            ++l;--r;
            if (l==mid) {
                break;
            }
        }
        return true;
    } else {
        // 奇数长度
        int mid=s.size()/2;
        int l=0,r=s.size()-1;
        while (true) {
            if (s[l]!=s[r]) {
                return false;
            }
            ++l;--r;
            if (l>mid) {
                break;
            }
        }
        return true;
    }
}

bool is_rn(int y) {
    if (y%100==0) {
        if (y%400==0) {
            return true;
        } else {
            return false;
        }
    } else {
        if (y%4==0) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int from_year,from_month,from_day;
    int to_year,to_month,to_day;
    scanf("%4d",&from_year);
    scanf("%2d",&from_month);
    scanf("%2d",&from_day);
    scanf("%4d",&to_year);
    scanf("%2d",&to_month);
    scanf("%2d",&to_day);
    int y,m,d,ans=0;
    y=from_year;
    m=from_month;
    d=from_day;
    while (true) {
        if (is_reversed(y,m,d)) {
            ++ans;
        }
        if (y==to_year && m==to_month && d==to_day) {
            break;
        }
        ++d;
        if (d==31) {
            if (m==4 || m==6 || m==9 || m==11) {
                d=1;
                ++m;
                if (m==13) {
                    m=1;
                    ++y;
                }
            }
        } else if (d==32) {
            d=1;
            ++m;
            if (m==13) {
                m=1;
                ++y;
            }
        } else if (m==2) {
            if (is_rn(y)) {
                if (d==30) {
                    d=1;
                    ++m;
                }
            } else {
                if (d==29) {
                    d=1;
                    ++m;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}

/*
p.s. 开O2才过...，不开#10 TLE 90pts
*/