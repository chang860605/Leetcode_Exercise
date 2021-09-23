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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a == nullptr)
            return b;
        if(b == nullptr)
            return a;
        ListNode* head;
        if(a->val < b->val){
            head = a;
            head->next = mergeTwoLists(a->next,b);
        }
        else{
            head = b;
            head->next = mergeTwoLists(a,b->next);
        }
        return head;
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(1)
// Recursive
// 如果 a->value 小，變將head = a，然後讓head->next由剩下的兩個去merge的recursive 
// 此方法較iterative更好，連需要記錄一個頭的ptr都省略掉