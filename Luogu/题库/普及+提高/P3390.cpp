#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=105;
const int mod=1000000007;

int n,k;

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

// Matrix qpow(Matrix base,int ts) {
//     if (ts==1) return base;
//     else if (ts%2) {
//         Matrix a=qpow(base,ts/2);
//         return a*a*base;
//     } else {
//         Matrix a=qpow(base,ts/2);
//         return a*a;
//     }
// }

Matrix qpow(Matrix base,int ts) {
    Matrix ans(n,n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i==j) ans[i][j]=1;
        }
    }
    while (ts) {
        if (ts&1) ans=ans*base;
        base=base*base;
        ts>>=1;
    }
    return ans;
}

Matrix a;

signed main() {
    scanf("%lld %lld",&n,&k);
    a.n=a.m=n;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%lld",&a[i][j]);
        }
    }
    a=qpow(a,k);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            printf("%lld ",a[i][j]);
        }
        putchar(10);
    }
    return 0;
}

/*
5 1000000000000
114 514 191 919 810
523 152 395 205 392
5 1 5 2 5
350 205 235 253 186
206 239 493 295 406
*/