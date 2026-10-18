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
    ListNode* detectCycle(ListNode* head) {
        int ran = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow && ran == 0) {
                if (slow == head) {
                    return head;
                }
                slow = head;
                while (fast != nullptr && fast->next != nullptr) {
                    fast = fast->next;
                    slow = slow->next;
                    if (fast == slow) {
                        return slow;
                    }
                }
            }
        }
        return nullptr;
    }
};