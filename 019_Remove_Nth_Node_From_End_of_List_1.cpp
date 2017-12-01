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
        int len = 0;
        for (auto p = head; p; p = p->next) {
            ++len;
        }
        auto q = &dummy;
        for (; len > n; --len) {
            q = q->next;
        }
        q->next = q->next->next;
        return dummy.next;
    }
};