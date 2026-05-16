#include <bits/stdc++.h>
using namespace std;

int n;

struct node {
    char type;
    bool init;
    node* left;
    node* right;
};

node* tree_root;

char s[2048];
char types[2048][2048];

int pows[11]={1,2,4,8,16,32,64,128,256,512,1024};

void traversal(node* root) {
    if (root->left->init) traversal(root->left);
    if (root->right->init) traversal(root->right);
    cout<<root->type;
}

void create_tree(node* root,int l,int r) {
    root->init=true;
    root->type=types[l][r];
    root->left=new node;
    root->right=new node;
    root->left->init=false;
    root->right->init=false;
    if (l<r) {
        create_tree(root->left,l,(l+r)/2);
        create_tree(root->right,(l+r)/2+1,r);
    }
}

void init_types() {
    for (int i=1;i<=pows[n];++i) {
        if (s[i]=='1') types[i][i]='I';
        else if (s[i]=='0') types[i][i]='B';
    }
    for (int len=2;len<=pows[n];++len) {
        for (int l=1,r=l+len-1;r<=pows[n];++l,++r) {
            bool zero=false,one=false;
            for (int k=l;k<=r-1;++k) {
                if (types[l][k]=='F' || types[k+1][r]=='F') {
                    types[l][r]='F';
                    break;
                }
                if (types[l][k]=='B' || types[k+1][r]=='B') {
                    zero=true;
                }
                if (types[l][k]=='I' || types[k+1][r]=='I') {
                    one=true;
                }
                if (one && zero) {
                    types[l][r]='F';
                    break;
                }
            }
            if (zero && !one) types[l][r]='B';
            else if (!zero && one) types[l][r]='I';
        }
    }
}

void input() {
    scanf("%d",&n);
    cin>>s+1;
}

int main() {
    input();
    init_types();
    tree_root=new node;
    tree_root->init=false;
    create_tree(tree_root,1,pows[n]);
    traversal(tree_root);
    return 0;
}

/*
10001011
1000 || 1011
10 | 00    ||    10 | 11
FBI Tree:
                    F
        F                       F
    F       B               F       I
  I   B   B   B           I   B   I   I
traversal: IBFBBBFIBFIIIFF
*/