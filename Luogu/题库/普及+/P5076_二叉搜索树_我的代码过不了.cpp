#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    int times;
    node *l;
    node *r;
};

// create a node
// return: the node
node* createNode(int x) {
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->l=NULL;
    newnode->r=NULL;
    newnode->times=1;
    return newnode;
}

// insert into a tree
// return: the node
node* createTree(node* n,int x) {
    if (!n) {
        // node is empty
        node* root=createNode(x); // create a root node
        return root;
    } else {
        if (x<n->data) {
            // smaller, so go to the left sub-tree
            n->l=createTree(n->l,x);
        } else if (x>n->data) {
            // bigger, so go to the right sub-tree
            n->r=createTree(n->r,x);
        } else {
            n->times++;
        }
        return n;
    }
}

// an array which is used to save the traversal data
vector<node*> tra_data;

// traversal
void traversal(node* root) {
    // left sub-tree
    if (root->l) {
        traversal(root->l);
    }
    // root
    tra_data.push_back(root);
    // right sub-tree
    if (root->r) {
        traversal(root->r);
    }
    return ;
}

// find max
// return: the node with the max data but smaller then x
int findMax(node* n,int x) {
    tra_data.clear();
    traversal(n);
    for (int i=0;i<tra_data.size();++i) {
        if (tra_data[i]->data==x) {
            if (i==0) {
                return -0x7fffffff;
            } else {
                return tra_data[i-1]->data;
            }
        }
    }
    return -0x7fffffff;
}

// find min
// return: the node with the smallest data but bigger then x
int findMin(node* n,int x) {
    tra_data.clear();
    traversal(n);
    for (int i=0;i<tra_data.size();++i) {
        if (tra_data[i]->data==x) {
            if (i==tra_data.size()-1) {
                return 0x7fffffff;
            } else {
                return tra_data[i+1]->data;
            }
        }
    }
    return 0x7fffffff;
}

// find node
// return: the node we find
node* find(node* n,int x) {
    if (!n) {
        return NULL;
    } else {
        if (x<n->data) {
            // smaller, so go to the left sub-tree
            return find(n->l,x);
        } else if (x>n->data) {
            // bigger, so go to the right sub-tree
            return find(n->r,x);
        } else {
            // the same, so return the node
            return n;
        }
    }
}

// // a sort method
// bool cmp(node* a,node* b) {
//     if (a->data<b->data) {
//         return true;
//     } else {
//         return false;
//     }
// }

int main() {
    node* root=NULL;
    int q,op,x;
    scanf("%d",&q);
    for (int i=0;i<q;++i) {
        scanf("%d %d",&op,&x);
        switch (op) {
            case 5: {
                // insert the number x
                root=createTree(root,x);
                break;
            }
            case 3: {
                // find the number which is smaller than x
                // but the biggest
                int n=findMax(root,x);
                // we found the number!
                printf("%d\n",n);
                break;
            }
            case 4: {
                // like case 3
                // find the number which is bigger than x
                // but the smallest
                int n=findMin(root,x);
                // we found the number!
                printf("%d\n",n);
                break;
            }
            case 1: {
                // first, we need to know all the values
                tra_data.clear();
                traversal(root);
                int rank=0;
                for (int i=0;i<tra_data.size();++i) {
                    if (tra_data[i]->data<x) {
                        rank=rank+tra_data[i]->times;
                    } else {
                        rank++;
                        printf("%d\n",rank);
                        break;
                    }
                }
                break;
            }
            case 2: {
                // first, we need to know all the values
                // (like case 1)
                tra_data.clear();
                traversal(root);
                int rank=0;
                int i=0;
                for (int i=0;i<tra_data.size();++i) {
                    rank=rank+tra_data[i]->times;
                    if (rank>=x) {
                        // arrived!
                        printf("%d\n",tra_data[i]->data);
                        break;
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}