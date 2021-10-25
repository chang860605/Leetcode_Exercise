class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = 0;   
        int n = nums.size();
        for(int i = 0 ; i < n; i++ )
        {
            if(flag<i) return false;
            flag = max(flag,i+nums[i]);
        }
        return true;
    }
};


// Time  Complexity: O(n)
// Space Complexity: O(1)

// 運用DP解決
// flag表示能到哪裡，假設flag有超過當前的index，代表可以利用當前的index再多走nums[i]步=>因此得到規則
// 如果flag走不到當前index，即直接return false