#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ans=0;
    for (int one=1;one<=3;++one) {
    for (int two=1;two<=3;++two) {
    for (int three=1;three<=3;++three) {
    for (int four=1;four<=3;++four) {
    for (int five=1;five<=3;++five) {
    for (int six=1;six<=3;++six) {
    for (int seven=1;seven<=3;++seven) {
    for (int eight=1;eight<=3;++eight) {
    for (int nine=1;nine<=3;++nine) {
    for (int ten=1;ten<=3;++ten) {
    if (one+two+three+four+five+six+seven+eight+nine+ten==n) {
        ++ans;
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    printf("%d\n",ans);
    for (int one=1;one<=3;++one) {
    for (int two=1;two<=3;++two) {
    for (int three=1;three<=3;++three) {
    for (int four=1;four<=3;++four) {
    for (int five=1;five<=3;++five) {
    for (int six=1;six<=3;++six) {
    for (int seven=1;seven<=3;++seven) {
    for (int eight=1;eight<=3;++eight) {
    for (int nine=1;nine<=3;++nine) {
    for (int ten=1;ten<=3;++ten) {
    if (one+two+three+four+five+six+seven+eight+nine+ten==n) {
        printf("%d %d %d %d %d %d %d %d %d %d\n",
        one,two,three,four,five,six,seven,eight,nine,ten);
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    return 0;
}