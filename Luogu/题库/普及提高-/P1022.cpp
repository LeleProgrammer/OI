#include <bits/stdc++.h>
using namespace std;

string s;

int unknown_factor[2]={0,0}; // left,right
int known[2]={0,0};
char unknown_char;

void divide() {
    bool pos_neg=true; // true: positive; false: negative;
    bool read_pos_neg=false;
    bool now=false; // false: left; true: right;
    bool belong=false; // false: known; true: unknown;
    bool _read_factor=false;
    bool read_unknown_char=false;
    bool read_zero=false;
    int read_factor=0;
    for (int i=0;i<s.length();) {
        pos_neg=true;
        read_pos_neg=false;
        read_factor=0;
        _read_factor=false;
        read_unknown_char=false;
        read_zero=false;
        belong=false;
        while (true) {
            if (i>=s.length()) {
                if ((!read_factor) && (!read_zero)) ++read_factor;
                if (!now) {
                    if (!pos_neg) {
                        read_factor*=-1;
                    }
                    if (!belong) {
                        known[0]+=read_factor;
                    } else {
                        unknown_factor[0]+=read_factor;
                    }
                } else {
                    if (!pos_neg) {
                        read_factor*=-1;
                    }
                    if (!belong) {
                        known[1]+=read_factor;
                    } else {
                        unknown_factor[1]+=read_factor;
                    }
                }
                break;
            }
            if (s.c_str()[i]=='-' && (!read_pos_neg) && (!_read_factor) && (!read_unknown_char)) {
                read_pos_neg=true;
                pos_neg=false;
            } else if (s.c_str()[i]=='+' && (!read_pos_neg) && (!_read_factor) && (!read_unknown_char)) {
                read_pos_neg=true;
                pos_neg=true;
            } else if ((s.c_str()[i]=='-' || s.c_str()[i]=='+') && (read_pos_neg || _read_factor || read_unknown_char)) {
                if ((!read_factor) && (!read_zero)) ++read_factor;
                if (!now) {
                    if (!pos_neg) {
                        read_factor*=-1;
                    }
                    if (!belong) {
                        known[0]+=read_factor;
                    } else {
                        unknown_factor[0]+=read_factor;
                    }
                } else {
                    if (!pos_neg) {
                        read_factor*=-1;
                    }
                    if (!belong) {
                        known[1]+=read_factor;
                    } else {
                        unknown_factor[1]+=read_factor;
                    }
                }
                break;
            } else if (s.c_str()[i]=='=') { // equal
                if ((!read_factor) && (!read_zero)) ++read_factor;
                if (!now) {
                    if (!pos_neg) {
                        read_factor*=-1;
                    }
                    if (!belong) {
                        known[0]+=read_factor;
                    } else {
                        unknown_factor[0]+=read_factor;
                    }
                } else {
                    if (!pos_neg) {
                        read_factor*=-1;
                    }
                    if (!belong) {
                        known[1]+=read_factor;
                    } else {
                        unknown_factor[1]+=read_factor;
                    }
                }
                now=true; // turn to right
                ++i;
                break;
            } else if (isdigit(s.c_str()[i])) { // a number
                _read_factor=true;
                read_factor=read_factor*10+s.c_str()[i]-'0';
                if (s.c_str()[i]-'0'==0) {
                    read_zero=true;
                }
            } else { // a char
                belong=true;
                read_unknown_char=true;
                unknown_char=s.c_str()[i];
            }
            ++i;
        }
    }
}

float calculate() {
    float _unknown_factor=unknown_factor[0]-unknown_factor[1]; // move the unknown to the left;
    float _known=known[1]-known[0]; // move the known to the right;
    float result=_known/_unknown_factor; // calculate;
    return result;
}

int main() {
    cin>>s;
    divide();
    float result=calculate();
    if (result==0) result=0;
    printf("%c=%.3f",unknown_char,result);
    return 0;
}