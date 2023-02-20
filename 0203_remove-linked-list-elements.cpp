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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode;
        ListNode* pos = dummy;
        
        while (head) {
            if (head->val == val)  {
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            } else {
                pos->next = head;
                pos = pos->next;
                head = head->next;
            }
        }
        pos->next = head;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
