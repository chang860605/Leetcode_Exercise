class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == nullptr)
            return b;
        if(b == nullptr)
            return a;
        ListNode* c;
        if(a->val < b->val){
            c = a;
            c->next = merge(a->next, b);
        }
        else{
            c = b;
            c->next = merge(a,b->next);
        }
        return c;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        
        for(int i=1;i<lists.size();i++){
            lists[0] = merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};

// Time  Complexity: O(nk)
// Space Complexity: O(1)
// 利用merge 2 lists的延伸，直接套用到 n 個的list上即可
// 此題還有Pirority Queue的做法