class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        addCombination(candidates,curr,0,target);
        return res;
    }
    
    void addCombination(vector<int>& candidates, vector<int>& curr,int idx, int target)
    {
        if(target==0) 
        {
            res.push_back(curr);
            return;   
        }
        if(idx == candidates.size() ) return ;
        for(int i = idx; i < candidates.size(); i++)
        {
            //if(i != idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] <= target){
                curr.push_back(candidates[i]);
                addCombination(candidates, curr, i, target - candidates[i]);
                curr.pop_back();
            }
            else return;
        }
    }
};

// Time  Complexity: O(2^n)
// Space Complexity: O(n)

// DFS去解決，幾乎DFS的問題都是相同使用backtracking的解法，時間複雜度為 (中間拓展的數量*每次操作的複雜度) => 2^n*n
// 由於可重複利用，在for loop中的addCombination參數idx也從同一個地方開始