#include <bits/stdc++.h>
using namespace std;

const int N=45;
const int M=100005;

int tt,n;
char king;
string arr[N];
bool flag[N];

unordered_map< string,int > hs;
int cnt;

vector< pair<string,string> > ans;

int main() {
    scanf("%d",&tt);
    while (tt--) {
        hs.clear();
        scanf("%d",&n); n*=2;
        scanf(" %c",&king);
        cnt=0;
        memset(flag,0,sizeof(flag));
        ans.clear();
        for (int i=1;i<=n;++i) {
            string s;
            cin>>s;
            arr[i]=s;
            hs.insert(make_pair(s,++cnt));
        }
        for (int i=1;i<=n;++i) { // same -> same
            for (int j=1;j<=n;++j) {
                if (i==j) continue;
                if (flag[i] || flag[j]) continue;
                if (arr[i][1]==arr[j][1] && arr[i][1]!=king) {
                    if (arr[j][0]>arr[i][0]) swap(arr[j],arr[i]);
                    // cout<<arr[j]<<" "<<arr[i]<<endl;
                    ans.push_back(make_pair(arr[j],arr[i]));
                    flag[i]=true;
                    flag[j]=true;
                }
            }
        }
        for (int i=1;i<=n;++i) { // king -> other
            for (int j=1;j<=n;++j) {
                if (i==j) continue;
                if (flag[i] || flag[j]) continue;
                if (arr[i][1]!=arr[j][1] && (arr[i][1]==king ^ arr[j][1]==king)) {
                    if (arr[j][1]==king) swap(arr[i],arr[j]);
                    // cout<<arr[j]<<" "<<arr[i]<<endl;
                    ans.push_back(make_pair(arr[j],arr[i]));
                    flag[i]=true;
                    flag[j]=true;
                }
            }
        }
        for (int i=1;i<=n;++i) { // king -> king
            for (int j=1;j<=n;++j) {
                if (i==j) continue;
                if (flag[i] || flag[j]) continue;
                if (arr[i][1]==arr[j][1] && arr[i][1]==king) {
                    if (arr[j][0]>arr[i][0]) swap(arr[j],arr[i]);
                    // cout<<arr[j]<<" "<<arr[i]<<endl;
                    ans.push_back(make_pair(arr[j],arr[i]));
                    flag[i]=true;
                    flag[j]=true;
                }
            }
        }
        bool ok=true;
        for (int i=1;i<=n && ok;++i) ok&=flag[i];
        if (ok) {
            for (int i=0;i<ans.size();++i) {
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        } else {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}