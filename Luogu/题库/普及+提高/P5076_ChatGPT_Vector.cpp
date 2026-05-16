#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numSet;

// 查询x数的排名
int getRank(int x) {
    int count = 0;
    for (int num : numSet) {
        if (num < x)
            count++;
    }
    return count + 1;
}

// 查询排名为x的数
int getNumber(int x) {
    sort(numSet.begin(), numSet.end());
    return numSet[x - 1];
}

// 求x的前驱
int getPredecessor(int x) {
    sort(numSet.begin(), numSet.end());
    auto it = lower_bound(numSet.begin(), numSet.end(), x);
    if (it == numSet.begin())
        return -2147483647;
    --it;
    return *it;
}

// 求x的后继
int getSuccessor(int x) {
    sort(numSet.begin(), numSet.end());
    auto it = upper_bound(numSet.begin(), numSet.end(), x);
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
            numSet.push_back(x);
    }
    
    return 0;
}
