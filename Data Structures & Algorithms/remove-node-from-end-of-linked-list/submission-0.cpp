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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Iterate with 2 points n apart. When the first reaches the end, the second will be on the nth element from the end
        ListNode *cur = head;
        for (int i = 0; i < n; ++i) {
            cur = cur->next;
        }
        ListNode dummy = ListNode(0, head);
        ListNode *prev = &dummy;
        while (cur) {
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = prev->next->next;
        return dummy.next;
    }
};
