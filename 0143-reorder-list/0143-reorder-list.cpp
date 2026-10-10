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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* temp = nullptr;
        while (second != nullptr) {
            ListNode* next_node = second->next;
            second->next = temp;
            temp = second;
            second = next_node;
        }

        fast = head;
        while (fast != nullptr && temp != nullptr) {
            ListNode* next_fast = fast->next;
            ListNode* next_temp = temp->next;

            fast->next = temp;
            temp->next = next_fast;

            fast = next_fast;
            temp = next_temp;
        }
    }
};