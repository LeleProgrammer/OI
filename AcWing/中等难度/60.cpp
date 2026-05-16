class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int m,n;
        int dp[100][100];
        m=grid.size();
        n=grid[0].size();
        for (int i=1;i<=m;++i) {
            for (int j=1;j<=n;++j) {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        int maxx=-1;
        for (int j=1;j<=n;++j) {
            if (dp[m][j]>maxx) {
                maxx=dp[m][j];
            }
        }
        return maxx;
    }
};