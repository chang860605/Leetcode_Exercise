class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int area = min(height[l],height[r])*(r-l);
        int max_area = -1;
        while(l<r)
        {
            area = min(height[l],height[r])*(r-l);
            max_area = max(max_area,area);
            if( height[l] > height[r] ) r--;
            else l++;
        }
        return max_area;
    }
};


// Time  Complexity: O(n)
// Space Complexity: O(1)
// 歷遍所有組合即可
// 假設左邊比右邊高度高 => 代表右邊要向左移，才有可能會有更大的答案，反之則是左邊向右移
// 用一個 Max_Area變數紀錄最後的答案即可