#include <bits/stdc++.h>
using namespace std;

int n;
bool have=false;
int visit[21],circle[21];

bool check(int n) {
    for (int i=2;i<=sqrt(n);++i) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

void print() {
    for (int i=0;i<n-1;++i) {
        printf("%d ",circle[i]);
    }
    printf("%d\n",circle[n-1]);
}

void search(int i) {
    if (i==n-1) {
        if (check(circle[i]+1)) {
            have=true;
            print();
        }
    } else {
        for (int j=2;j<=n;++j) {
            if (visit[j] && check(circle[i]+j)) {
                visit[j]=0;
                circle[i+1]=j;
                search(i+1);
                visit[j]=1;
                circle[i+1]=0;
            }
        }
    }
}

int main() {
    int _case=1;
    while (scanf("%d",&n)!=EOF) {
        if (_case!=1) printf("\n");
        printf("Case %d:\n",_case);
        memset(circle,0,sizeof(circle));
        memset(visit,0,sizeof(visit));
        circle[0]=1;
        for (int i=1;i<=n;++i) {
            visit[i]=1;
        }
        search(0);
        ++_case;
    }
    return 0;
}