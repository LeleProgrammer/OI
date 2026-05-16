#include <bits/stdc++.h>
using namespace std; // abbaaab

string s;

int result=0;

int main() {
    cin>>s; // 输入
    int a,b; // 统计a和b的数量
    for (int i=0;i<s.size();++i) {
        if (s[i]=='a') {
            a++;
        } else {
            b++;
        }
    }
    // 检查是否有可行解
    if (!(a%2==0 || b%2==0)) {
        // 没有可行解，输出-1结束
        printf("-1");
    } else {
        if (a%2==1) {
            // a的个数是奇数
            // b的个数就一定是偶数了
            // a一定要放在中间
            int center=s.size()/2; // 中心的下标
            if (s[center]!='a') {
                // 中心不正确
                int l=center-1;
                int r=center+1;
                // 分成两半看看哪一块a离中心近
                // 就选离中心近的那块交换到中间
                while (l>=0 && r<s.size()) {
                    cout<<"1 "<<s<<endl;
                    if (s[l]=='a') {
                        // 左边找到a了
                        // 先交换到中心的左边
                        while (l+1<=center-1) {
                            cout<<"2 "<<s<<" "<<l<<" "<<center<<endl;
                            swap(s[l],s[l+1]);
                            ++l;
                            ++result;
                        }
                        // 然后和中心交换
                        swap(s[l],s[center]);
                        ++result;
                        // 交换完成了
                        // 退出while
                        break;
                    } else if (s[r]=='a') {
                        // 右边找到a了
                        // 先交换到中心的右边
                        while (r-1>=center+1) {
                            cout<<"3 "<<s<<" "<<l<<" "<<center<<endl;
                            swap(s[r],s[r-1]);
                            --r;
                            ++result;
                        }
                        // 然后和中心交换
                        swap(s[r],s[center]);
                        ++result;
                        // 交换完成了
                        // 退出while
                        break;
                    }
                    --l;++r; // 两边的“指针”往外扩散一格
                }
            }
            // 现在，中心是正确的
            // 然后就要处理两旁的了
            // 两端的“指针”从外到内搜索
            int l=0;
            int r=s.size()-1;
            // 需要检查的个数
            int need_to_do=s.size()/2;
            // 已经正确的个数
            int ok=0;
            while (true) {
                cout<<"4 "<<s<<" "<<ok<<" "<<need_to_do<<endl;
                if (s[l]!=s[r]) {
                    // 两端不匹配
                    // 这时候不能盲目与里面的交换
                    // 就像aabb a aabb这个例子，两个b交换完还是一样
                    if (l+1!=center) { // 不能超出范围
                        // 先看看再里面的那个可不可以交换
                        if (s[l+1]==s[r]) {
                            // 左边可以换
                            swap(s[l+1],s[l]);
                            ++result;
                            ok++;
                        } else if (s[r-1]==s[l]) {
                            // 右边可以换
                            swap(s[r-1],s[r]);
                            ++result;
                            ok++;
                        }
                        // 不能换就和aabb a aabb一样，先暂时不要
                    }
                } else {
                    // 两端匹配了
                    // 那就不管它咯~~
                    ok++;
                }
                ++l;--r; // 两边的“指针”往里面移动一格
                if (l==center) {
                    // 移动到中心了
                    // 也就是出界了
                    // 检查一下完成数量
                    if (ok==need_to_do) {
                        // 完成了！
                        printf("%d",result);
                        return 0;
                    } else {
                        // 还没有完成
                        // 归零重置一下
                        ok=0;
                        l=0;
                        r=s.size()-1;
                    }
                }
            }
        } else if (b%2==1) {
            // b的个数是奇数
            // a的个数就一定是偶数了
            // b一定要放在中间
            int center=s.size()/2; // 中心的下标
            if (s[center]!='b') {
                // 中心不正确
                int l=center-1;
                int r=center+1;
                // 分成两半看看哪一块b离中心近
                // 就选离中心近的那块交换到中间
                while (l>=0 && r<s.size()) {
                    if (s[l]=='b') {
                        // 左边找到b了
                        // 先交换到中心的左边
                        while (l+1<=center-1) {
                            swap(s[l],s[l+1]);
                            ++l;
                            ++result;
                        }
                        // 然后和中心交换
                        swap(s[l],s[center]);
                        ++result;
                        // 交换完成了
                        // 退出while
                        break;
                    } else if (s[r]=='b') {
                        // 右边找到b了
                        // 先交换到中心的右边
                        while (r-1>=center+1) {
                            swap(s[r],s[r-1]);
                            --r;
                            ++result;
                        }
                        // 然后和中心交换
                        swap(s[r],s[center]);
                        ++result;
                        // 交换完成了
                        // 退出while
                        break;
                    }
                    --l;++r; // 两边的“指针”往外扩散一格
                }
            }
            // 现在，中心是正确的
            // 然后就要处理两旁的了
            // 两端的“指针”从外到内搜索
            int l=0;
            int r=s.size()-1;
            // 需要检查的个数
            int need_to_do=s.size()/2;
            // 已经正确的个数
            int ok=0;
            while (true) {
                cout<<"4 "<<s<<" "<<ok<<" "<<need_to_do<<endl;
                if (s[l]!=s[r]) {
                    // 两端不匹配
                    // 这时候不能盲目与里面的交换
                    // 就像aabb b aabb这个例子，两个b交换完还是一样
                    if (l+1!=center) { // 不能超出范围
                        // 先看看再里面的那个可不可以交换
                        if (s[l+1]==s[r]) {
                            // 左边可以换
                            swap(s[l+1],s[l]);
                            ++result;
                            ok++;
                        } else if (s[r-1]==s[l]) {
                            // 右边可以换
                            swap(s[r-1],s[r]);
                            ++result;
                            ok++;
                        }
                        // 不能换就和aabb b aabb一样，先暂时不要
                    }
                } else {
                    // 两端匹配了
                    // 那就不管它咯~~
                    ok++;
                }
                ++l;--r; // 两边的“指针”往里面移动一格
                if (l==center) {
                    // 移动到中心了
                    // 也就是出界了
                    // 检查一下完成数量
                    if (ok==need_to_do) {
                        // 完成了！
                        printf("%d",result);
                        return 0;
                    } else {
                        // 还没有完成
                        // 归零重置一下
                        ok=0;
                        l=0;
                        r=s.size()-1;
                    }
                }
            }
        } else {
            // 最后一种情况，a和b都是偶数个
            // 也差不多，只不过不需要进行中心的确认了
            // 那center怎么确定呢？
            // 用小数啊！！！
            // 这样写，下面循环中的判断语句就要稍加修改了
            double center=(double)(s.size())/2.0;
            // 直接交换两边就好
            // 两端的“指针”从外到内搜索
            int l=0;
            int r=s.size()-1;
            // 需要检查的个数
            int need_to_do=s.size()/2;
            // 已经正确的个数
            int ok=0;
            while (true) {
                if (l!=r) {
                    // 两端不匹配
                    // 这时候不能盲目与里面的交换
                    // 就像aabb b aabb这个例子，两个b交换完还是一样
                    if (l+1<center) { // 不能超出范围
                        // 先看看再里面的那个可不可以交换
                        if (s[l+1]==s[r]) {
                            // 左边可以换
                            swap(s[l+1],s[l]);
                            ++result;
                            ok++;
                        } else if (s[r-1]==s[l]) {
                            // 右边可以换
                            swap(s[r-1],s[r]);
                            ++result;
                            ok++;
                        }
                        // 不能换就和aabb b aabb一样，先暂时不要
                    }
                } else {
                    // 两端匹配了
                    // 那就不管它咯~~
                    ok++;
                }
                ++l;--r; // 两边的“指针”往里面移动一格
                if (l==floor(center)) {
                    // 移动到中心了
                    // 也就是出界了
                    // 检查一下完成数量
                    if (ok==need_to_do) {
                        // 完成了！
                        printf("%d",result);
                        return 0;
                    } else {
                        // 还没有完成
                        // 归零重置一下
                        ok=0;
                        l=0;
                        r=s.size()-1;
                    }
                }
            }
        }
    }
    return 0;
}

/*
abb a aab
aba b baa
1 22 3 11
center: 4

aabb a aabb
|         |
aabb a abab
 |       |
aabb a abab
  |     |
aabb a abab
|         |
aabb a abba
*/