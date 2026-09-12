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
        // I misunderstood the problem; what I need to do is break the list into its first and second halves, then only reverse the second half, then interlink
        // 1, 2, 3
        // 1, 2, 3, 4
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy, *slow = head, *fast = head;
        while (fast) {
            slow = slow->next;
            prev = prev->next;
            if (!fast->next) break;
            fast = fast->next->next;
        }

        // slow now points to the first node in the second half of the list
        ListNode *cur = slow;
        prev->next = nullptr;
        prev = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode *i = dummy->next, *j = prev;
        while (i && j) {
            ListNode *next1 = i->next, *next2 = j->next;
            i->next = j;
            j->next = next1;
            i = next1;
            j = next2;
        }
    }
};
