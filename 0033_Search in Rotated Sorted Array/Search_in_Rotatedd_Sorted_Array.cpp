class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid]==target) return mid;
            if(nums[start] <= nums[mid])
            {
                if(target < nums[mid] && target >= nums[start]) end = mid - 1;
                else start = mid + 1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};

// Time  Complexity: O(logn)
// Space Complexity: O(1)

// https://www.cnblogs.com/grandyang/p/4325648.html
// 用binary search
// 找哪一段是有序的，再進行尋找target的過程
// nums[start] <= nums[mid] => 代表這一段是有序的，反之則是mid~end
// 而  start<=target<mid => 原本的binary search調整位置
