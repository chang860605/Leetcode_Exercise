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
// ����sorting
// �D�n���ٲ��j����case
// 1. �ѲĤ@�Ӽƶ}�lfor loop�A�]����sorting �ҥH�p�G nums[i]�]�j��0 �N��᭱���ٲ�
// 2. �ۦP��nums[i]�۵M���ݭn�A���A��continue���L
// 3. �@�ˬۦP�� start, end ������skip��
// 4. �ѤU�N�O�`�M >0 �� <0 �i��վ�