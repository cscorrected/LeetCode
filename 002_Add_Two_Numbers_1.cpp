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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = ListNode(0);
        auto curr = &dummy, p = l1, q = l2;
        int carry = 0;
        while (p || q) {
            int x = (p ? p->val : 0);
            int y = (q ? q->val : 0);
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry) prev->next = new ListNode(carry);
        return dummy.next;
    }
};