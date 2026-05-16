#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

// f[i][j][k] i位数，最高位为j，数字的出现情况为k
int f[21][10][59049];

int n,l,r;
int ansl,ansr;

int pw(int base,int power) {
    int res=1;
    for (int i=1;i<=power;++i) {
        res*=base;
    }
    return res;
}

const int MAXK=pw(3,10)-1;

// 求三进制数k从右开始数从0开始数的第d位数
int kd(int k,int d) {
    return (k/pw(3,d))%3;
}

// 将三进制数k从右开始数从0开始数的第d位数加上p并返回
int ckd(int k,int d,int p) {
    return k+(pw(3,d)*p);
}

// 预处理，构建f数组
void init() {
    memset(f,0,sizeof(f));
    for (int i=0;i<=9;++i) {
        f[1][i][1*pw(3,i)]=1;
    }
    for (int i=2;i<=19;++i) { // i位数
        for (int j=0;j<=9;++j) { // 最高位为j
            for (int g=0;g<=9;++g) { // 次高位为g
                for (int k=0;k<=MAXK;++k) { // 数字出现情况k
                    // g在k中的对应位必须不为0
                    if (kd(k,g)==0) continue;
                    // 第j位奇偶互换，未出现则改为1
                    if (kd(k,j)<=1) { // 0 or 1
                        f[i][j][ckd(k,j,1)]+=f[i-1][g][k];
                    } else { // 2
                        f[i][j][ckd(k,j,-1)]+=f[i-1][g][k];
                    }
                }
            }
        }
    }
}

// 求是否符合条件
bool check(int k) {
    for (int i=0;i<=9;++i,k/=3) {
        if (k%3==0) continue;
        else if (i%2==0) {
            if (k%3==2) return false;
        } else {
            if (k%3==1) return false;
        }
    }
    return true;
}

// 从f数组中筛选符合条件的数
int solve(int n) {
    int ans=0;
    // 分离数位
    vector<int> nums;
    // 下标从1开始，0的位置添加占位
    nums.push_back(-0x3f);
    while (n) {
        nums.push_back(n%10);
        n/=10;
    }
    // 获取长度
    int len=nums.size()-1;
    // 位数不到len位
    for (int i=1;i<=len-1;++i) {
        for (int j=1;j<=9;++j) { // 不含前导0
            for (int k=1;k<=MAXK;++k) { // 数字的出现情况
                if (check(k)) {
                    ans+=f[i][j][k];
                }
            }
        }
    }
    // 位数长len位
    for (int i=1;i<=nums[len]-1;++i) { // 不含前导0
        for (int k=1;k<=MAXK;++k) {
            if (check(k)) {
                ans+=f[len][i][k];
            }
        }
    }
    // 有最高位限制的情况
    int before=0;
    for (int i=len;i>=2;--i) { // 第i位及更高位均填入最大值
        if (kd(before,nums[i])==2) ckd(before,nums[i],-1);
        else ckd(before,nums[i],1);
        // 枚举下一位，不能达到最大值，可包含0，因为已经不是前导0了
        for (int j=0;j<=nums[i-1]-1;++j) {
            for (int k=1;MAXK;++k) {
                int tmp_k=0;
                for (int p=0;p<=9;++p) {
                    if (kd(before,p)==0) ckd(tmp_k,p,kd(k,p));
                    else if (kd(k,p)==0) ckd(tmp_k,p,kd(before,p));
                    else if (kd(before,p)+kd(k,p)==3) ckd(tmp_k,p,1);
                    else ckd(tmp_k,p,2);
                }
                if (check(tmp_k)) {
                    ans+=f[i-1][j][k];
                }
            }
        }
    }
    return ans;
}

signed main() {
    init();
    scanf("%llu",&n);
    for (int i=1;i<=n;++i) {
        scanf("%llu %llu",&l,&r);
        ansl=solve(l);
        ansr=solve(r+1);
        printf("%llu\n",ansr-ansl);
    }
    return 0;
}