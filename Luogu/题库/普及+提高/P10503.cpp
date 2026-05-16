#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=15;
const int mod=10000007;

int n,m;

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

signed main() {
    while (~scanf("%lld %lld",&n,&m)) {
        n+=2;
        Matrix a(1,n);
        a[1][1]=3;
        a[1][2]=23;
        for (int i=3;i<=n;++i) {
            scanf("%lld",&a[1][i]);
        }
        Matrix b(n,n);
        for (int i=1;i<=n;++i) {
            int val;
            if (i==2) val=10;
            else val=1;
            for (int j=i;j<=n;++j) {
                b[i][j]=val;
            }
        }
        b=qpow(b,m);
        a=a*b;
        printf("%lld\n",a[1][n]);
    }
    return 0;
}