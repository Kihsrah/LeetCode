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
    ListNode* oddEvenList(ListNode* head) {
        ListNode evenDummy(0);
        ListNode oddDummy(0);
        ListNode* even = &evenDummy;
        ListNode* odd = &oddDummy;
        int count = 1;
        while (head != nullptr) {
            if (count % 2 == 0) {
                even->next = head;
                head = head->next;
                even = even->next;
            }
            else {
                odd->next = head;
                head = head->next;
                odd = odd->next;
            }
            count++;
        }
        even->next = nullptr;
        odd->next = evenDummy.next;

        return oddDummy.next; 
    }
};