#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s) {
    for (int l=0,r=s.size()-1;l<=r;++l,--r) {
        if (s[l]!=s[r]) return false;
    }
    return true;
}

bool is_mirrored(string s) {
    for (int l=0,r=s.size()-1;l<=r;++l,--r) {
        if (s[l]=='B' || s[r]=='B') return false;
        if (s[l]=='C' || s[r]=='C') return false;
        if (s[l]=='D' || s[r]=='D') return false;
        if (s[l]=='F' || s[r]=='F') return false;
        if (s[l]=='G' || s[r]=='G') return false;
        if (s[l]=='K' || s[r]=='K') return false;
        if (s[l]=='N' || s[r]=='N') return false;
        if (s[l]=='P' || s[r]=='P') return false;
        if (s[l]=='Q' || s[r]=='Q') return false;
        if (s[l]=='R' || s[r]=='R') return false;
        if (s[l]=='4' || s[r]=='4') return false;
        if (s[l]=='6' || s[r]=='6') return false;
        if (s[l]=='7' || s[r]=='7') return false;
        if (s[l]=='9' || s[r]=='9') return false;
        if (s[l]=='E' && s[r]!='3') return false;
        if (s[l]=='3' && s[r]!='E') return false;
        if (s[l]=='2' && s[r]!='S') return false;
        if (s[l]=='S' && s[r]!='2') return false;
        if (s[l]=='Z' && s[r]!='5') return false;
        if (s[l]=='5' && s[r]!='Z') return false;
        if (s[l]=='J' && s[r]!='L') return false;
        if (s[l]=='L' && s[r]!='J') return false;
        if (s[l]!='E' && s[l]!='3' && s[l]!='2' && s[l]!='S' &&
        s[l]!='Z' && s[l]!='5' && s[l]!='J' && s[l]!='L' && s[l]!=s[r]) return false;
    }
    return true;
}

int main() {
    string s;
    while (getline(cin,s)) {
        bool pal,mir;
        pal=is_palindrome(s);
        mir=is_mirrored(s);
        string explanation;
        if (!pal && !mir) explanation=" -- is not a palindrome.";
        else if (pal && !mir) explanation=" -- is a regular palindrome.";
        else if (!pal && mir) explanation=" -- is a mirrored string.";
        else if (pal && mir) explanation=" -- is a mirrored palindrome.";
        cout<<s<<explanation<<endl<<endl;
    }
    return 0;
}