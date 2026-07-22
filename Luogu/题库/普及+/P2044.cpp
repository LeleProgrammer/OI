#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=5;

int mod,a,c,x0,n,g;

int mul(int a,int b) {
    if (b==0) return 0;
    else if (b==1) return a%mod;
    else if (b%2) {
        int t=mul(a,b/2);
        return (((t+t)%mod)+a)%mod;
    } else {
        int t=mul(a,b/2);
        return (t+t)%mod;
    }
}

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
                    mat[i][j]+=mul(a[i][k],b[k][j]);
                    // mat[i][j]+=a[i][k]*b[k][j];
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

Matrix A,B;

signed main() {
    scanf("%lld %lld %lld %lld %lld %lld",&mod,&a,&c,&x0,&n,&g);
    A.n=1,A.m=2;
    B.n=2,B.m=2;
    A[1][1]=(a*x0+c)%mod,A[1][2]=c;
    if (n==1) {
        printf("%lld",A[1][1]);
        return 0;
    }
    B[1][1]=a,B[1][2]=0;
    B[2][1]=1,B[2][2]=1;
    B=qpow(B,n-1);
    // cout<<B[1][1]<<" "<<B[1][2]<<endl;
    // cout<<B[2][1]<<" "<<B[2][2]<<endl;
    A=A*B;
    A[1][1]%=g;
    printf("%lld",A[1][1]);
    return 0;
}