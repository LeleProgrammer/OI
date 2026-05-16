#include <bits/stdc++.h>
using namespace std;

const int N=40005;
const int M=205;

int n,m,len;
int arr[N];
int last;
vector<int> nums;
int cnt[M][N];
int mos[M][M];
int app[N];
bool flag[N];

int get(int x) {
    return (x-1)/len;
}

int getl(int x) {
    return x*len+1;
}

int getr(int x) {
    return x*len+len;
}

bool cmp(const int& a,const int& b) {
    return a<b;
}

void init() {
    for (int i=1;i<=n;++i) {
        // cout<<"TESTTEST: "<<i<<" "<<get(i)<<" "<<arr[i]<<endl;
        cnt[get(i)][arr[i]]++;
    }
    for (int i=1;i<n/len+(n%len!=0);++i) {
        for (int j=1;j<=n;++j) {
            flag[arr[j]]=false;
        }
        for (int j=1;j<=n;++j) {
            if (flag[arr[j]]) continue;
            cnt[i][arr[j]]+=cnt[i-1][arr[j]];
            flag[arr[j]]=true;
            // printf("cnt[%lld][%lld]=%lld\n",i,arr[j],cnt[i][arr[j]]);
        }
    }
    for (int i=0;i<n/len+(n%len!=0);++i) {
        for (int j=0;j<N;++j) app[j]=0;
        int ans=0,ansNum=N;
        for (int j=i;j<n/len+(n%len!=0);++j) {
            for (int k=getl(j);k<=getr(j);++k) {
                app[arr[k]]++;
                if (app[arr[k]]>ans) {
                    ans=app[arr[k]];
                    ansNum=arr[k];
                } else if (app[arr[k]]==ans && arr[k]<ansNum) {
                    ansNum=arr[k];
                }
            }
            mos[i][j]=ansNum;
        }
    }
}

int query(int l,int r) {
    if (get(l)==get(r) || get(l)+1==get(r)) {
        for (int i=l;i<=r;++i) {
            app[arr[i]]=0;
        }
        int ans=0,ansNum=N;
        for (int i=l;i<=r;++i) {
            app[arr[i]]++;
            if (app[arr[i]]>ans) {
                ans=app[arr[i]];
                ansNum=arr[i];
            } else if (app[arr[i]]==ans && arr[i]<ansNum) {
                ansNum=arr[i];
            }
        }
        return ansNum;
    } else {
        // cout<<"TEST: "<<l<<" "<<getr(get(l))<<" "<<getl(get(r))<<" "<<r<<" "<<mos[get(l)+1][get(r)-1]<<" "<<cnt[get(r)-1][mos[get(l)+1][get(r)-1]]-cnt[get(l)][mos[get(l)+1][get(r)-1]]<<endl;
        for (int i=l;i<=getr(get(l));++i) {
            app[arr[i]]=0;
        }
        for (int i=getl(get(r));i<=r;++i) {
            app[arr[i]]=0;
        }
        int ans=0,ansNum=N;
        for (int i=l;i<=getr(get(l));++i) {
            app[arr[i]]++;
            int tmp=app[arr[i]]+cnt[get(r)-1][arr[i]]-cnt[get(l)][arr[i]];
            if (tmp>ans) {
                ans=tmp;
                ansNum=arr[i];
            } else if (tmp==ans && arr[i]<ansNum) {
                ansNum=arr[i];
            }
        }
        for (int i=getl(get(r));i<=r;++i) {
            app[arr[i]]++;
            int tmp=app[arr[i]]+cnt[get(r)-1][arr[i]]-cnt[get(l)][arr[i]];
            if (tmp>ans) {
                ans=tmp;
                ansNum=arr[i];
            } else if (tmp==ans && arr[i]<ansNum) {
                ansNum=arr[i];
            }
        }
        int tmp=cnt[get(r)-1][mos[get(l)+1][get(r)-1]]-cnt[get(l)][mos[get(l)+1][get(r)-1]];
        if (tmp>ans) {
            ansNum=mos[get(l)+1][get(r)-1];
        } else if (tmp==ans && mos[get(l)+1][get(r)-1]<ansNum) {
            ansNum=mos[get(l)+1][get(r)-1];
        }
        return ansNum;
    }
}

int main() {
    // freopen("P4168_1.in","r",stdin);
    // freopen("P4168.out","w",stdout);
    scanf("%d %d",&n,&m);
    len=sqrt(n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
        nums.push_back(arr[i]);
    }
    sort(nums.begin(),nums.end(),cmp);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for (int i=1;i<=n;++i) {
        arr[i]=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin();
    }
    init();
    while (m--) {
        int l,r;
        scanf("%d %d",&l,&r);
        l=((l+last-1)%n)+1;
        r=((r+last-1)%n)+1;
        if (l>r) swap(l,r);
        int ans=query(l,r);
        last=nums[ans];
        // cout<<l<<" "<<r<<endl;
        printf("%d\n",last);
    }
    return 0;
}