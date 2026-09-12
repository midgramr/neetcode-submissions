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
        ListNode dummy;
        ListNode *i = l1, *j = l2, *cur = &dummy;
        while (carry || i || j) {
            int sm = (i ? i->val : 0) + (j ? j->val : 0) + carry;
            cur->next = new ListNode(sm % 10);
            cur = cur->next;
            carry = sm / 10;
            if (i) i = i->next;
            if (j) j = j->next;
        }
        return dummy.next;
    }
};
