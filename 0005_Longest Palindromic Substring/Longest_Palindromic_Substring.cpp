class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int length = 0;
        string res = s.substr(0,1);
        for(int i = 0; i < n ; i++ )
        {
            // 奇數展開
            int odd = 1;
            int even = 1;
            while(i-odd>=0 && i+odd <= n-1 && s[i-odd] == s[i+odd])
            {
                if( 2*odd+1 > length)
                {
                    length = 2*odd + 1;
                    res = s.substr(i-odd,2*odd+1);
                }
                odd++;
            }
            // 偶數展開
            while(i-even>=0 && i+even-1 <= n-1 && s[i-even]==s[i+even-1])
            {
                //cout << s[i-even] << ",";
                if(2*even > length)
                {
                    length = 2*even;
                    res = s.substr(i-even,2*even);
                }
                even++;
            }
            
        }
        return res;
    }
};

// Time  Complexity: O(n^2)
// Space Complexity: O(1)
// 核心思想: 既然是回文，只要從現在這個點開始往外擴展即可
// 擴展分為：奇數、偶數 兩種
// 用一個length紀錄最長的substr
// 更新也將res更新即可