class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int res = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < i ; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};



// Time  Complexity: O(n^2)
// Space Complexity: O(n)
// 建立dp數組 
// 如果 nums[i] 比 nums[j] 前的sub solution都大，代表要+1
// 最後回傳最大的即為答案