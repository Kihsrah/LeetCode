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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* one = l1;
        ListNode* two = l2;
        ListNode* prev = nullptr;
        while (one != nullptr && two != nullptr) {
            int sum = one->val + two->val + carry;
            if (sum > 9) {
                carry = 1;
                one->val = sum % 10;
            } else {
                one->val = sum;
                carry = 0;
            }
            prev = one;
            one = one->next;
            two = two->next;
        }

        if (two != nullptr) {
            prev->next = two;
            one = two;
        }

        while (one != nullptr) {
            int sum = one->val + carry;
            one->val = sum % 10;
            carry = sum / 10;
            prev = one;
            one = one->next;
        }

        if (carry == 1) {
            prev->next = new ListNode(1);
        }
        return l1;
    }
};