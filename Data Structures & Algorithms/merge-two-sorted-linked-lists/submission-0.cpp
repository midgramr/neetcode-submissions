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
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy, *i = list1, *j = list2;
        while (i || j) {
            if (!i) {
                cur->next = j;
                j = j->next;
            } else if (!j) {
                cur->next = i;
                i = i->next;
            } else {
                if (i->val <= j->val) {
                    cur->next = i;
                    i = i->next;
                } else {
                    cur->next = j;
                    j = j->next;
                }
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
