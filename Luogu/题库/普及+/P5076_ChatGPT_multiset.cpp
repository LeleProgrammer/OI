#include <iostream>
#include <set>
using namespace std;

multiset<int> numSet;

// 查询x数的排名
int getRank(int x) {
    int count = 0;
    for (auto it = numSet.begin(); it != numSet.end(); ++it) {
        if (*it == x)
            break;
        count++;
    }
    return count + 1;
}

// 查询排名为x的数
int getNumber(int x) {
    auto it = numSet.begin();
    advance(it, x - 1);
    return *it;
}

// 求x的前驱
int getPredecessor(int x) {
    auto it = numSet.lower_bound(x);
    if (it == numSet.begin())
        return -2147483647;
    --it;
    return *it;
}

// 求x的后继
int getSuccessor(int x) {
    auto it = numSet.upper_bound(x);
    if (it == numSet.end())
        return 2147483647;
    return *it;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int op, x;
        cin >> op >> x;
        
        if (op == 1)
            cout << getRank(x) << endl;
        else if (op == 2)
            cout << getNumber(x) << endl;
        else if (op == 3)
            cout << getPredecessor(x) << endl;
        else if (op == 4)
            cout << getSuccessor(x) << endl;
        else if (op == 5)
            numSet.insert(x);
    }
    
    return 0;
}
