#include <bits/stdc++.h>
using namespace std;

int n;

bool col[15],tl_br[205],tr_bl[205];

int calc=0;

string result="";

void dfs(int howmany) {
    if (howmany<n) {
        ++howmany;
        string past=result;
        for (int c=1;c<=n;++c) {
            if (col[c]==false && tl_br[howmany-c+n-1]==false && 
            tr_bl[howmany+c-2]==false) {
                col[c]=true;
                tl_br[howmany-c+n-1]=true;
                tr_bl[howmany+c-2]=true;
                result=result+to_string(c)+" ";
                dfs(howmany);
                col[c]=false;
                tl_br[howmany-c+n-1]=false;
                tr_bl[howmany+c-2]=false;
                result=past;
            }
        }
    } else {
        ++calc;
        if (calc>3) return ;
        cout<<result<<endl;
    }
}

int main() {
    memset(col,false,sizeof(col));
    memset(tl_br,false,sizeof(tl_br));
    memset(tr_bl,false,sizeof(tr_bl));
    scanf("%d",&n);
    dfs(0);
    printf("%d",calc);
    return 0;
}

// ¿ªO2²Å¹ýQWQ