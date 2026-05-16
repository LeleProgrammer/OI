#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=200005;

int n,m;
int las[N];

struct Segment {
    int l,r;
};

vector<int> nums;
vector<Segment> vec[N];

struct SegmentTree {
    int l,r;
    int sum;
} tr[N*4];

int main() {
    scanf("%d %d",&n,&m);
    while (m--) {
        int t,p;
        scanf("%d %d",&t,&p);
        nums.push_back(t);
        if (!las[p]) {
            las=t;
            continue;
        }
        vec[p].push_back(las[p],t);
        las[p]=0;
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
}