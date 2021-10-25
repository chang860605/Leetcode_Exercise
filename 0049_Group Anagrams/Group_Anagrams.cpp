class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(int i = 0 ; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        for(auto c:m)
        {
            res.push_back(c.second);
        }
        return res;
    }
};

// Time  Complexity: O(nlogn)
// Space Complextiy: O(n)

// 利用map去儲存
// 先將其中的字串sort 
// sort後一樣的組合就被當成map的first，原本的字串自然push_back到後面
// 剩下將second的vector加入result即可
