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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* one = headA;
        ListNode* two = headB;
        ListNode* ans = nullptr;
        int count1 = 0;
        int count2 = 0;
        while (one != nullptr) {
            one = one->next;
            count1++;
        }
        while (two != nullptr) {
            two = two->next;
            count2++;
        }

        one = headA;
        two = headB;

        if (count1 > count2) {
            for (int i = 0; i < count1 - count2; i++) {
                one = one->next;
            }
        } else {
            for (int i = 0; i < count2 - count1; i++) {
                two = two->next;
            }
        }

        while (one != nullptr && two != nullptr) {
            if (one == two) {
                return one;
            } else {
                one = one->next;
                two = two->next;
            }
        }
        return ans;
    }
};