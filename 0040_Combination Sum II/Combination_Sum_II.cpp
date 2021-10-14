class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i!=idx && candidates[i]==candidates[i-1]) continue; 
            //刪除重複result，例如test case的 1,1 利用這個可直接跳過第二個1，但是第一個1還是會去利用到，
            //所以 [1,1,.....,1] , 30 這種case也不會衝突，剩下的1都是i==idx的狀況，並非重複
            if(candidates[i] <= target){
                curr.push_back(candidates[i]);
                addCombination(candidates, curr, i+1, target - candidates[i]); //index不重複利用
                curr.pop_back();
            }
            else return;
        }
    }
};


// Time  Complexity: O(2^n)
// Space Complexity: O(n)

// 跟上一題只差兩行，差別在解決重複case以及index不重複利用 
// index不重複利用 => 利用 i+1 解決
// 解決重複case　　=> 上面使用到i+1來到下一個迴圈，假設數組為1,3,3,3
//                   [1,] => 下一個foor loop會有3個[1,3]出現 
//                   i+1讓第1個3加入迴圈中(i==idx)，剩下的就會在數組長度為2的時候重複而剔除掉
//                   剩下的3會加入只有在數組更長的時候 => ex: [1,3,3]，最後的3為下一圈loop的i==idx