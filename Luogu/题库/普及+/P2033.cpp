#include <bits/stdc++.h>
using namespace std;

char arr[9][9];
int x,y,face; // 1,2,3,4: ^>v<
string op;
string turnface;
int dis;

void move(int i,int j,int f) {
    if (i==x && j==y) {
        if (f==1) {
            if (i==1) return;
            if (arr[i-1][j]=='.') {
                x--;
                return;
            }
            move(i-1,j,f);
            x--;
            return;
        } else if (f==2) {
            if (j==8) return;
            if (arr[i][j+1]=='.') {
                y++;
                return;
            }
            move(i,j+1,f);
            y++;
            return;
        } else if (f==3) {
            if (i==8) return;
            if (arr[i+1][j]=='.') {
                x++;
                return;
            }
            move(i+1,j,f);
            x++;
            return;
        } else {
            if (j==1) return;
            if (arr[i][j-1]=='.') {
                y--;
                return;
            }
            move(i,j-1,f);
            y--;
            return;
        }
    } else {
        if (f==1) {
            if (i==1) {arr[i][j]='.'; return;}
            if (arr[i-1][j]=='.') {
                swap(arr[i][j],arr[i-1][j]);
                return;
            }
            move(i-1,j,f);
            swap(arr[i][j],arr[i-1][j]);
            return;
        } else if (f==2) {
            if (j==8) {arr[i][j]='.'; return;}
            if (arr[i][j+1]=='.') {
                swap(arr[i][j],arr[i][j+1]);
                return;
            }
            move(i,j+1,f);
            swap(arr[i][j],arr[i][j+1]);
            return;
        } else if (f==3) {
            if (i==8) {arr[i][j]='.'; return;}
            if (arr[i+1][j]=='.') {
                swap(arr[i][j],arr[i+1][j]);
                return;
            }
            move(i+1,j,f);
            swap(arr[i][j],arr[i+1][j]);
            return;
        } else {
            if (j==1) {arr[i][j]='.'; return;}
            if (arr[i][j-1]=='.') {
                swap(arr[i][j],arr[i][j-1]);
                return;
            }
            move(i,j-1,f);
            swap(arr[i][j],arr[i][j-1]);
            return;
        }
    }
}

int main() {
    for (int i=1;i<=8;++i) {
        for (int j=1;j<=8;++j) {
            cin>>arr[i][j];
            if (arr[i][j]=='^' || arr[i][j]=='<' || arr[i][j]=='>' || arr[i][j]=='v') {
                x=i; y=j;
                if (arr[i][j]=='^') face=1;
                else if (arr[i][j]=='>') face=2;
                else if (arr[i][j]=='v') face=3;
                else face=4;
                arr[i][j]='.';
            }
        }
    }
    while (true) {
        cin>>op;
        if (op=="#") break;
        if (op=="turn") {
            cin>>turnface;
            if (turnface=="left") {
                face--;
                if (face==0) face=4;
            } else if (turnface=="right") {
                face++;
                if (face==5) face=1;
            } else if (turnface=="back") {
                if (face==1) face=3;
                else if (face==3) face=1;
                else if (face==2) face=4;
                else face=2;
            }
        } else {
            cin>>dis;
            while (dis--) move(x,y,face);
        }
    }
    for (int i=1;i<=8;++i) {
        for (int j=1;j<=8;++j) {
            if (i==x && j==y) {
                if (face==1) printf("^");
                else if (face==2) printf(">");
                else if (face==3) printf("v");
                else printf("<");
            } else {
                printf("%c",arr[i][j]);
            }
        }
        putchar(10);
    }
    return 0;
}