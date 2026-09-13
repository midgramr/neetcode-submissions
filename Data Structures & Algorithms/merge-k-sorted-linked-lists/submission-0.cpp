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

#define sz(a) (int)(a).size()

class Solution {
    // Intuition tells me merge sort is the most efficient; can be implemented iteratively
public:
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (l1 || l2) {
            if (!l2) {
                cur->next = l1;
                l1 = l1->next;
            } else if (!l1) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                if (l1->val <= l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                }
            }
            cur = cur->next;
        }
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        vector<ListNode*> cur{lists}, next;
        while (sz(cur) > 1) {
            for (int i = 0; i < sz(cur) - 1; i += 2) {
                next.push_back(merge(cur[i], cur[i + 1]));
            }
            if (sz(cur) % 2 != 0) next.push_back(cur.back());
            std::swap(cur, next);
            next.clear();
        }
        return cur[0];
    }
};
