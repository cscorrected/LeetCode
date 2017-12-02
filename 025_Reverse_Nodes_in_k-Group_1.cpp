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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int len = 0;
        for (auto p = head; p; p = p->next) {
            ++len;
        }
        auto dummy = ListNode(0);
        dummy.next = head;
        auto pre = &dummy, cur = pre, nex = pre;
        while (len >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                nex = cur->next;
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
            }
            pre = cur;
            len -= k;
        }
        return dummy.next;
    }
};