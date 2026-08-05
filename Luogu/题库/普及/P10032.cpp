#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1000005;

int t,n,m;
int status;

struct node {
    int pos;
    int val;
    friend bool operator < (const node& a,const node& b) {
        return a.val<b.val;
    }
} arr[N];

int tmp[N];

int getmex() {
    int last=-1;
    for (int i=1;i<=n;++i) {
        if (arr[i].val==last+1) last++;
        else if (arr[i].val==last) continue;
        else return last+1;
    }
    return arr[n].val+1; // be like: 0 1 2 3 4 5 ... n-2 n-1
}

int process() {
    int last=-1,i,mex=getmex();
    bool multiple=false;
    for (i=1;i<=n;++i) {
        if (arr[i].val==last+1) {
            /*
            0 1 2 3 4 5 ...
            nothing happened
            (return status 3)
            */
            last++;
        } else if (arr[i].val==last) {
            /*
            0 1 2 3 4 4 5 6 6 7 8 9 10
            to
            0 1 2 3 11 11 5 11 11 7 8 9 10
            (return status 2)
            */
            arr[i-1].val=arr[i].val=mex;
            multiple=true;
        } else {
            /*
            0 1 2 3 5 6 7 8 8 9 ...
            to
            0 1 2 3 4 4 4 4 4 4 ...
            0 1 2 3 5 5 5 5 5 5 ...
            0 1 2 3 4 4 4 4 4 4 ...
            ...
            loop
            (return status 1)
            (!multiple)
            */
            // ANOTHER CONDITION !!!!!!!!
            /*
            0 1 2 3 4 5 6 6 6 7 8 8 8 9 12 13 14 15 15 16
            to
            0 1 2 3 4 5 10 10 10 7 10 10 10 9 10 10 10 10 10 10
            sort
            0 1 2 3 4 5 7 9 10 10 10 10 10 10 10 10 10 10 10 10
            to
            0 1 2 3 4 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6
            loop start
            multiple==true but here
            (return status 2) (can be solved as status 2)
            */
            while (i<=n) arr[i++].val=mex;
            if (multiple) return 2; // another condition
            return 1; // loop start
        }
    }
    if (multiple) return 2;
    return 3;
}

void output() {
    for (int i=1;i<=n;++i) tmp[arr[i].pos]=arr[i].val;
    for (int i=1;i<=n;++i) printf("%lld ",tmp[i]);
    printf("\n");
}

signed main() {
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld %lld",&n,&m);
        for (int i=1;i<=n;++i) scanf("%lld",&arr[i].val),arr[i].pos=i;
        flag:
        sort(arr+1,arr+1+n);
        status=process(); m--;
        if (!m) {
            output();
            continue;
        }
        if (status==1) {
            if (m%2==0) {
                output();
            } else {
                process();
                output();
            }
        } else if (status==2) {
            goto flag;
            // sort(arr+1,arr+1+n);
            // process(); m--;
            // if (!m) {
            //     output();
            //     continue;
            // }
            // if (m%2==0) {
            //     output();
            // } else {
            //     process();
            //     output();
            // }
        } else { // status==3
            output();
        }
    }
    return 0;
}