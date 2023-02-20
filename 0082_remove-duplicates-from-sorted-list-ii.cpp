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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode;
        ListNode* pos = dummy;

        ListNode* slow = head;
        while (slow != nullptr) {
            ListNode* fast = slow->next;
            bool dup = false;
            while (fast != nullptr && slow->val == fast->val) {
                dup = true;
                ListNode* tmp = fast;
                fast = fast->next;
                delete tmp;
            }
            if (dup) {
                ListNode* tmp = slow;
                slow = fast;
                delete tmp;
            } else {
                pos->next = slow;
                pos = pos->next;
                slow = fast;
            }
        }
        pos->next = nullptr;
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
