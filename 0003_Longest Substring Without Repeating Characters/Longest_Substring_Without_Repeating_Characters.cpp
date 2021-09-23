class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> visited(256,-1);
        if(s.length()<=1) return s.length();
        int res = 0;
        int left = -1;
        for(int right = 0 ; right < s.length(); right++)
        {
            if(visited[s[right]] > left)
                left = visited[s[right]];
            
            visited[s[right]] = right;
            res = max(res,right-left);
        }
        return res;
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(1)
// 用vector去紀錄上一次出現同一個char的位置
// 如果重複 => ex: visited: (a,2)，而現在是 (a,5) 代表至多5-2=> 3個字元的sub string
// 每一個字元藉由right都會被經過一過 => 再由一個max維護result即可