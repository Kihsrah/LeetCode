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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = nullptr;
        while (slow != nullptr) {
            ListNode* next_node = slow->next;
            slow->next = fast;
            fast = slow;
            slow = next_node;
        }
        ListNode* prev = fast;
        fast = head;
        while(prev != nullptr){
            if(fast->val != prev->val){
                return false;
            }
            fast = fast->next;
            prev = prev->next;
        }
        return true;
    }
};
