#include <bits/stdc++.h>
using namespace std;

int n[200];
int start[200];
int tmp[200];
string s;
int k;
int times[105];
int maximum_times[105];

bool is_loop() {
    for (int i=0;i<k;++i) {
        if (n[i]!=start[i]) {
            return false;
        }
    }
    return true;
}

void mul() {
    memset(tmp,0,sizeof(tmp));
    int jw=0;
    for (int i=0;i<=k;++i) {
        for (int j=0;j<=k;++j) {
            tmp[i+j]=tmp[i+j]+n[i]*start[j]+jw;
            jw=tmp[i+j]/10;
            tmp[i+j]%=10;
        }
    }
    swap(tmp,n);
}

void init() {
    memset(times,0,sizeof(times));
    memset(start,0,sizeof(start));
    memset(n,0,sizeof(n));
    cin>>s>>k;
    for (int i=0;i<s.length();++i) {
        n[s.length()-i-1]=s.c_str()[i]-'0';
    }
    for (int i=0;i<s.length();++i) {
        start[s.length()-i-1]=s.c_str()[i]-'0';
    }
    memset(maximum_times,0,sizeof(maximum_times));
    maximum_times[k]=1;
}

void add_one() {
    int jw=0;
    int i=0;
    while (true) {
        times[i]+=1+jw;
        jw=times[i]/10;
        times[i]%=10;
        if (jw==0) break;
        ++i;
    }
}

bool do_loop() {
    mul();
    if (is_loop()) {
        int length=100;
        add_one();
        while (times[length]==0) --length;
        for (int i=length;i>=0;--i) {
            printf("%d",times[i]);
            return true;
        }
    }
    return false;
}

int compare() {
    int len_t=100,len_m_t=100;
    while (times[len_t]==0) --len_t;
    while (maximum_times[len_m_t]==0) --len_m_t;
    if (len_t<len_m_t) return -1;
    else if (len_t>len_m_t) return 1;
    else {
        for (int i=len_t;i>=0;--i) {
            if (times[i]>maximum_times[i]) return 1;
            else if (times[i]<maximum_times[i]) return -1;
        }
        return 0;
    }
}

int main() {
    for (init();compare()<=0;add_one()) {
        if (do_loop()) {
            return 0;
        }
    }
    printf("-1");
    return 0;
}