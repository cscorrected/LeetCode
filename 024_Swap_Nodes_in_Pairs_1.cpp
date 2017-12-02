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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        auto dummy = ListNode(0);
        dummy.next = head;
        auto pre = &dummy, cur = pre, nex = cur;
        while (pre->next && pre->next->next) {
            cur = pre->next;
            nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            pre = cur;
        }
        return dummy.next;
    }
};