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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> buf;
        for (auto cur : lists) {
            for (; cur; cur = cur->next) {
                buf.insert(cur->val);
            }
        }
        auto dummy = ListNode(0);
        auto cur = &dummy;
        for (auto& val : buf) {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        return dummy.next;
    }
};