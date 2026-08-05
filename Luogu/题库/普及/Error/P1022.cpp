#include <bits/stdc++.h>
using namespace std;

string s;
char unknown_char;
int unknown_factor_left=0;
int unknown_factor_right=0;
int known_left=0;
int known_right=0;

void divide() {
    int len_s=s.length();
    bool known_positive;
    bool positive;
    bool finish_read_one_num;
    bool now=false; // false: left; true: right;
    bool is_factor_belongs_to_unknown;
    bool read_equal;
    bool finish_all=false;
    int i=0;
    int read_factor;
    while (true) {
        if (finish_all) {
            break;
        }
        known_positive=false;
        positive=true;
        finish_read_one_num=false;
        is_factor_belongs_to_unknown=false;
        read_equal=false;
        read_factor=0;
        while (true) { // read one number;
            if (i<len_s) {
                if (s.c_str()[i]=='-') {
                    if (!known_positive) {
                        positive=false;
                    } else {
                        finish_read_one_num=true;
                    }
                } else if (s.c_str()[i]=='+') {
                    if (!known_positive) {
                        positive=true;
                    } else {
                        finish_read_one_num=true;
                    }
                } else if (!finish_read_one_num) {
                    if (isdigit(s.c_str()[i])) {
                        read_factor=(s.c_str()[i]-'0')+read_factor*10;
                    } else if (isalpha(s.c_str()[i])) {
                        is_factor_belongs_to_unknown=true;
                        unknown_char=s.c_str()[i];
                    } else {
                        finish_read_one_num=true;
                        read_equal=true;
                    }
                }
            } else {
                finish_all=true;
                finish_read_one_num=true;
            }
            if (finish_read_one_num) {
                if (!positive) {
                    read_factor*=-1;
                }
                if (!now) { // left
                    if (is_factor_belongs_to_unknown) {
                        if (read_factor==0) {
                            read_factor=1;
                        }
                        unknown_factor_left+=read_factor;
                    } else {
                        known_left+=read_factor;
                    }
                } else { // right
                    if (is_factor_belongs_to_unknown) {
                        if (read_factor==0) {
                            read_factor=1;
                        }
                        unknown_factor_right+=read_factor;
                    } else {
                        known_right+=read_factor;
                    }
                }
                if (read_equal) {
                    ++i;
                    now=true;
                } else {
                    --i;
                }
                break;
            }
            ++i;
        }
    }
}

int main() {
    cin>>s;
    divide();
    cout<<unknown_factor_left<<endl;
    cout<<unknown_factor_right<<endl;
    cout<<known_left<<endl;
    cout<<known_right<<endl;
    return 0;
}