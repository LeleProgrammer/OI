#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=5;

int p,q,a1,a2,n,mod;

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

signed main() {
    scanf("%lld %lld %lld %lld %lld %lld",&p,&q,&a1,&a2,&n,&mod);
    if (n==1) {
        printf("%lld",a1);
        return 0;
    } else if (n==2) {
        printf("%lld",a2);
        return 0;
    }
    n-=2;
    Matrix a(1,2);
    a[1][1]=a2,a[1][2]=a1;
    Matrix b(2,2);
    b[1][1]=p,b[1][2]=1;
    b[2][1]=q,b[2][2]=0;
    b=qpow(b,n);
    a=a*b;
    printf("%lld",a[1][1]);
    return 0;
}