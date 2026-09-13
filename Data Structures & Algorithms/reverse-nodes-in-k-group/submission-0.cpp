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

// Break the problem into 2 parts: check if there are >= k nodes remaining, then do the actual reverse
// When reversing, we need to maintain pointers to the nodes that come before/after the group. We also need references to the first/last node in the reversed group

class Solution {
public:
    bool hasK(ListNode *cur, int k) {
        int cnt = 0;
        while (cur) {
            ++cnt;
            if (cnt >= k) return true;
            cur = cur->next;
        }
        return false;
    }

    vector<ListNode*> reverse(ListNode *cur, int k) {
        ListNode *tail = cur;
        ListNode *prev = nullptr;
        for (int i = 0; i < k; ++i) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // head of group, tail of group, node after group
        return {prev, tail, cur};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur && hasK(cur->next, k)) {
            auto res = reverse(cur->next, k);
            ListNode *front = res[0], *back = res[1], *next = res[2];
            cur->next = front;
            back->next = next;
            cur = back;
        }
        return dummy.next;
    }
};
