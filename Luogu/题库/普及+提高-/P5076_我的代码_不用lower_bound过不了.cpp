#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    int q;
    scanf("%d",&q);
    int op,x;
    for (int i=0;i<q;++i) {
        scanf("%d %d",&op,&x);
        if (op==5) {
            v.push_back(x);
        } else {
            sort(v.begin(),v.end());
            if (op==1) {
                int rank=0;
                for (int i=0;i<v.size();++i) {
                    if (v[i]==x) {
                        ++rank;
                        printf("%d\n",rank);
                        break;
                    } else {
                        ++rank;
                        if (i!=0) {
                            if (v[i-1]==v[i]) {
                                --rank;
                            }
                        }
                    }
                }
            } else if (op==2) {
                int rank=0;
                for (int i=0;i<v.size();++i) {
                    ++rank;
                    if (i!=0) {
                        if (v[i]==v[i-1]) {
                            --rank;
                        }
                    }
                    if (rank==x) {
                        printf("%d\n",v[i]);
                        break;
                    }
                }
            } else if (op==3) {
                bool found=false;
                for (int i=0;i<v.size();++i) {
                    if (v[i]>=x) {
                        if (i==0) {
                            printf("%d\n",-0x7fffffff);
                        } else {
                            printf("%d\n",v[i-1]);
                        }
                        found=true;
                        break;
                    }
                }
                if (!found) {
                    if (x>v[v.size()-1]) {
                        printf("%d\n",v[v.size()-1]);
                    } else {
                        printf("%d\n",-0x7fffffff);
                    }
                }
            } else if (op==4) {
                bool found=false;
                for (int i=0;i<v.size();++i) {
                    if (v[i]>x) {
                        printf("%d\n",v[i]);
                        found=true;
                        break;
                    }
                }
                if (!found) printf("%d\n",-0x7fffffff);
            }
        }
    }
    return 0;
}