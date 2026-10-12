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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }
        curr = head;
        if (count == k) {
            return head;
        }
        k = k % count;
        if (k == 0) {
            return head;
        }
        count -= k;
        for (int i = 0; i < count - 1; i++) {
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        ListNode* temp = prev;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = head;
        return prev->next;
    }
};