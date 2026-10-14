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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* sub_prev = nullptr;
        for(int i = 0 ; i <= right - left; i++) {
            ListNode* next_node = curr->next;
            curr->next = sub_prev;
            sub_prev = curr;
            curr = next_node;
        }
        prev->next->next = curr;
        prev->next = sub_prev;
        return dummy.next;
    }
};