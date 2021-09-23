/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            tmp->next = l1;
            l1 = l1->next;
        }
        else
        {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    if(l1) tmp->next = l1;
    else tmp->next = l2;
    return head->next;//first value 
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(1)
// 將兩個node都放進去比較即可
// 讓tmp去走訪，tmp比對值後放去tmp->next之中，自然用到的l1或l2點去next，依序走訪
// 出while迴圈後剩下還有值的點當作next即可
// 由於head沒有值，我們return第一個有放值的點為head->next