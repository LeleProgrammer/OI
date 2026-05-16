#include <iostream>
using namespace std;

struct Node {
    int data;
    int count;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        count = 1;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        root->count++;
    
    return root;
}

int getRank(Node* root, int val) {
    if (root == nullptr)
        return 0;
    
    if (val < root->data)
        return getRank(root->left, val);
    else if (val > root->data)
        return root->count + getRank(root->right, val);
    else
        return root->count - 1 + getRank(root->left, val);
}

Node* findNode(Node* root, int rank) {
    if (root == nullptr || rank < 0)
        return nullptr;
    
    int leftCount = root->left ? root->left->count : 0;
    if (rank < leftCount)
        return findNode(root->left, rank);
    else if (rank >= leftCount + root->count)
        return findNode(root->right, rank - leftCount - root->count);
    else
        return root;
}

Node* findPredecessor(Node* root, int val) {
    Node* pre = nullptr;
    
    while (root != nullptr) {
        if (val <= root->data)
            root = root->left;
        else {
            pre = root;
            root = root->right;
        }
    }
    
    return pre;
}

Node* findSuccessor(Node* root, int val) {
    Node* suc = nullptr;
    
    while (root != nullptr) {
        if (val < root->data) {
            suc = root;
            root = root->left;
        } else
            root = root->right;
    }
    
    return suc;
}

int main() {
    int q;
    cin >> q;
    
    Node* root = nullptr;
    
    while (q--) {
        int op, x;
        cin >> op >> x;
        
        if (op == 1)
            cout << getRank(root, x) + 1 << endl;
        else if (op == 2) {
            Node* node = findNode(root, x - 1);
            if (node != nullptr)
                cout << node->data << endl;
        }
        else if (op == 3) {
            Node* node = findPredecessor(root, x);
            if (node != nullptr)
                cout << node->data << endl;
            else
                cout << -2147483647 << endl;
        }
        else if (op == 4) {
            Node* node = findSuccessor(root, x);
            if (node != nullptr)
                cout << node->data << endl;
            else
                cout << 2147483647 << endl;
        }
        else if (op == 5)
            root = insert(root, x);
    }
    
    return 0;
}
