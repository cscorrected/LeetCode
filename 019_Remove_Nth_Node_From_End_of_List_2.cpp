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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = ListNode(0);
        dummy.next = head;
        auto p = &dummy, q = &dummy;
        for (int i = 1; i <= n + 1; ++i) {
            p = p->next;
        }
        for (; p; p = p->next) {
            q = q->next;
        }
        q->next = q->next->next;
        return dummy.next;
    }
};