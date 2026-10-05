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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* list3 = dummy;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                list3->next = l1;
                l1 = l1->next;
            } else {
                list3->next = l2;
                l2 = l2->next;
            }
            list3 = list3->next;
        }
        if (l1 != nullptr) {
            list3->next = l1;
        } else {
            list3->next = l2;
        }
        return dummy->next;
    }
};