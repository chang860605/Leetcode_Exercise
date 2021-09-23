class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n-2 && nums[i]<=0 ; i++)
        {
            if( i !=0 && nums[i] == nums[i-1])
                continue;
            int start = i + 1;
            int end   = n - 1;
            int target =  0 - nums[i];
            
            while( start < end )
            {
                if(nums[start] + nums[end] == target)
                {
                    res.push_back({nums[i],nums[start],nums[end]});
                    while(start < end && nums[start]==nums[start+1]) start++;
                    while(start < end && nums[end]==nums[end-1]) end--;
                    start++;
                    end--;
                }
                else if(nums[start]+nums[end] < target) start++;
                else end--;
            }
        }
        return res;
    }
};

// Time Complexity  : O(n^2) + O(nlogn)
// Space Complexity : O(number of triplets)
// 先做sorting
// 主要為省略大部分case
// 1. 由第一個數開始for loop，因為有sorting 所以如果 nums[i]也大於0 代表後面都省略
// 2. 相同的nums[i]自然不需要再比對，用continue跳過
// 3. 一樣相同的 start, end 都直接skip掉
// 4. 剩下就是總和 >0 或 <0 進行調整