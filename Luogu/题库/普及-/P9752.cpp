#include <bits/stdc++.h>
using namespace std;

const int N=15;

int n;
int arr[N][6];
int sta[6];
int ans;

bool check(int* a,int* b) {
    int cnt=0;
    for (int i=1;i<=5;++i) {
        if (a[i]!=b[i]) cnt++;
    }
    if (cnt==1) return true;
    else if (cnt==2) {
        vector<int> c;
        for (int i=1;i<=4;++i) {
            if (a[i]!=b[i] && a[i+1]!=b[i+1]) {
                c.push_back((a[i]-b[i]+10)%10);
                c.push_back((a[i+1]-b[i+1]+10)%10);
                break;
            }
        }
        if (c.size()==0) return false;
        if (c[0]==c[1]) return true;
        else return false;
    } else return false;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=5;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (sta[1]=0;sta[1]<=9;++sta[1]) {
        for (sta[2]=0;sta[2]<=9;++sta[2]) {
            for (sta[3]=0;sta[3]<=9;++sta[3]) {
                for (sta[4]=0;sta[4]<=9;++sta[4]) {
                    for (sta[5]=0;sta[5]<=9;++sta[5]) {
                        int cnt=0;
                        for (int i=1;i<=n;++i) {
                            if (check(sta,arr[i])) {
                                cnt++;
                            }
                        }
                        if (cnt==n) ans++;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}