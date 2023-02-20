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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        
        ListNode* p1 = dummy;
        for (int i = 0; i < n + 1; i++) {
            p1 = p1->next;
        }
        ListNode* p2 = dummy;
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode* tmp = p2->next;
        p2->next = tmp->next;
        delete tmp;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
