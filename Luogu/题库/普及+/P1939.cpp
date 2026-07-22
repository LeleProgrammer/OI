#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=5;
const int mod=1000000007;

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

int T;
int n;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        if (n<=3) {
            puts("1");
            continue;
        }
        Matrix a(1,3),b(3,3);
        b[1][1]=1,b[1][2]=1,b[1][3]=0;
        b[2][1]=0,b[2][2]=0,b[2][3]=1;
        b[3][1]=1,b[3][2]=0,b[3][3]=0;
        a[1][1]=1,a[1][2]=1,a[1][3]=1;
        b=qpow(b,n-3);
        a=a*b;
        printf("%lld\n",a[1][1]);
    }
    return 0;
}

/*
matrix * | 1 1 0 |
         | 0 0 1 |
         | 1 0 0 |
*/