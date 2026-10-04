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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        vector<int> arr;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        int n = arr.size() - 1;
        int i = 0;
        swap(arr[k - 1], arr[n - k + 1]);
        curr = head;
        while (curr != nullptr) {
            curr->val = arr[i];
            curr = curr->next;
            i++;
        }
        return head;
    }
};