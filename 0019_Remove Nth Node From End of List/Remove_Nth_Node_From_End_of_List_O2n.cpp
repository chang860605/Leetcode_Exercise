/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int count = 0; // count how many node
        while(ptr)
        {
            ptr = ptr->next;
            count++;
        }
        if(count==n) return head->next;
        count = count - n - 1; 
        ptr = head;
        while(count--)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(1)
// 先用一個ptr實際歷遍一次紀錄在count得到有幾個node
// 接著將ptr回到head再實際next下去直到ptr的next是要砍掉的那個點 => ptr->next = ptr->next->next
// 此方法時間為2個n，可以利用2個ptr達到一個n完成的效果