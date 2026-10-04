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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* mid = head;
        for(int i = 1; i < k; i++) {
            slow = slow->next;
        }
        if(slow == nullptr) {
            return head;
        } 
        fast = slow;
        while(fast->next != nullptr) {
            fast = fast->next;
            mid = mid->next;
        }
        swap(slow->val, mid->val);
        return head;
    }
};