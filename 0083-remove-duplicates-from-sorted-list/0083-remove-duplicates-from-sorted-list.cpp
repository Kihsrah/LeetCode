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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;
        if (prev == nullptr) {
            return head;
        }
        ListNode* curr = prev->next;
        if (curr == nullptr) {
            return head;
        }

        while (curr != nullptr) {
            if (prev->val == curr->val) {
                while (curr != nullptr && curr->val == prev->val) {
                    curr = curr->next;
                }
                if (curr == nullptr) {
                    prev->next = nullptr;
                } else {
                    prev->next = curr;
                }
            } else {
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};