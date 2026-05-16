#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=5;

int T,n,m,mod;
int pw[25];

struct Matrix {
    int n,m;
    int mat[N][N];
    Matrix() {
        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                mat[i][j]=0;
            }
        }
    }
    Matrix(int n,int m) {
        this->n=n;
        this->m=m;
        for (int i=0;i<=n;++i) {
            for (int j=0;j<=m;++j) {
                mat[i][j]=0;
            }
        }
    }
    int* operator [] (signed i) {
        return mat[i];
    }
    friend Matrix operator * (Matrix a,Matrix b) {
        int n,m,p;
        n=a.n,m=a.m,p=b.m;
        Matrix mat(n,p);
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=p;++j) {
                for (int k=1;k<=m;++k) {
                    mat[i][j]+=a[i][k]*b[k][j];
                    mat[i][j]%=mod;
                }
            }
        }
        return mat;
    }
};

Matrix qpow(Matrix base,int ts) {
    if (ts==1) return base;
    else if (ts%2) {
        Matrix a=qpow(base,ts/2);
        return a*a*base;
    } else {
        Matrix a=qpow(base,ts/2);
        return a*a;
    }
}

void init() {
    pw[0]=1;
    for (int i=1;i<=20;++i) pw[i]=pw[i-1]<<1;
}

signed main() {
    init();
    scanf("%lld",&T);
    while (T--) {
        int n,m;
        scanf("%lld %lld",&n,&m);
        if (n<=1) {
            puts("1");
            continue;
        }
        mod=pw[m];
        Matrix a(1,2),b(2,2);
        a[1][1]=1,a[1][2]=1;
        b[1][1]=b[1][2]=b[2][1]=1,b[2][2]=0;
        b=qpow(b,n-1);
        a=a*b;
        printf("%lld\n",a[1][1]%mod);
    }
    return 0;
}