class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 1;j*j<=i;j++)
            {
                dp[i] = min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n];
    }
};

// Time  Complexity: O(n^(3/2))
// Space Complexity: O(n)
// 單純利用dp
// 比較規則為原本的dp[i] v.s dp[i-其中一個square]+1 (+1為為了這個square需要的一次)
