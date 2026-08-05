#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap(int k) {
    if (k%100==0) {
        if (k%400==0) return true;
        return false;
    } else if (k%4==0) return true;
    return false;
}

signed main() {
    scanf("%lld",&n);
    while (n--) {
        int r;
        scanf("%lld",&r);
        int y=-4713,m=1,d=1;
        if (r<1721424) {
            while (true) {
                if ((y+1)%4==0 && r>=366) {
                    r-=366,y++;
                } else if ((y+1)%4!=0 && r>=365) {
                    r-=365,y++;
                } else {
                    break;
                }
            }
            while (true) {
                if (m!=2) {
                    if (r>=mon[m]) {
                        r-=mon[m];
                        m++;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    if ((y+1)%4==0) {
                        if (r>=29) {
                            r-=29;
                            m++;
                        } else {
                            break;
                        }
                    } else {
                        if (r>=28) {
                            r-=28;
                            m++;
                        } else {
                            break;
                        }
                    }
                }
            }
            d+=r;
            printf("%lld %lld %lld BC\n",d,m,-y);
        } else {
            r-=1721424;
            y=1,m=1,d=1;
            if (r<=577736) {
                while (true) {
                    if (y%4==0 && r>=366) {
                        r-=366,y++;
                    } else if (y%4!=0 && r>=365) {
                        r-=365,y++;
                    } else {
                        break;
                    }
                }
                while (true) {
                    if (m!=2) {
                        if (r>=mon[m]) {
                            r-=mon[m];
                            m++;
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        if (y%4==0) {
                            if (r>=29) {
                                r-=29;
                                m++;
                            } else {
                                break;
                            }
                        } else {
                            if (r>=28) {
                                r-=28;
                                m++;
                            } else {
                                break;
                            }
                        }
                    }
                }
                d+=r;
                printf("%lld %lld %lld\n",d,m,y);
            } else {
                r-=577736;
                y=1582,m=10,d=4;
                if (!r) {
                    printf("%lld %lld %lld\n",d,m,y);
                    continue;
                }
                r--;
                d=15; // 1582.10.15
                while (r) {
                    r--,d++;
                    if (d>mon[m]) {
                        d=1,m++;
                    }
                    if (m==13 && d==1) {
                        m=1,d=1,y++;
                        break;
                    }
                }
                if (m!=1 && d!=1) {
                    printf("%lld %lld %lld\n",d,m,y);
                    continue;
                }
                while (true) {
                    int dec=365+is_leap(y);
                    if (r<dec) break;
                    r-=dec;
                    y++;
                    if (y==2000) break;
                }
                if (!r) {
                    printf("%lld %lld %lld\n",d,m,y);
                    continue;
                }
                // 2000.1.1
                int cnt=r/146097;
                r%=146097;
                y+=cnt*400;
                if (r>=36525) {
                    r-=36525,y+=100;
                    cnt=r/36524;
                    r%=36524;
                    y+=cnt*100;
                }
                // cnt=r/1460;
                // r%=1460;
                // y+=cnt*4;
                while (true) {
                    int dec=365+is_leap(y);
                    if (r<dec) break;
                    r-=dec;
                    y++;
                }
                if (!r) {
                    printf("%lld %lld %lld\n",d,m,y);
                    continue;
                }
                // while (true) {
                //     if (is_leap(y) && r>=366) {
                //         r-=366,y++;
                //     } else if ((!is_leap(y)) && r>=365) {
                //         r-=365,y++;
                //     } else {
                //         break;
                //     }
                // }
                while (true) {
                    if (m!=2) {
                        if (r>=mon[m]) {
                            r-=mon[m];
                            m++;
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        if (is_leap(y)) {
                            if (r>=29) {
                                r-=29;
                                m++;
                            } else {
                                break;
                            }
                        } else {
                            if (r>=28) {
                                r-=28;
                                m++;
                            } else {
                                break;
                            }
                        }
                    }
                }
                d+=r;
                printf("%lld %lld %lld\n",d,m,y);
            }
        }
    }
}

/*
1.1.1 1721424
plus 577736
1582.10.14 2299160

1582.10.15 2299161
*/