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
    ListNode* partition(ListNode* head, int x) {
        ListNode leastDummy(0);
        ListNode highestDummy(0);
        ListNode* curr = head;
        ListNode* least = &leastDummy;
        ListNode* highest = &highestDummy;
        while (curr != nullptr) {
            if (curr->val < x) {
                least->next = curr;
                least = least->next;
            }
            else {
                highest->next = curr;
                highest = highest->next;
            }
            curr = curr->next;
        }

        highest->next = nullptr;
        least->next = highestDummy.next;

        return leastDummy.next;
    }
};