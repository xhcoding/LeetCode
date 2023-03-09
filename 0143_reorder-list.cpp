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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            pre = slow;
            slow = slow->next;
        }
        if (pre != nullptr) {
            pre->next = nullptr;
        }
        
        ListNode* first = head;
        ListNode* second = reverseList(slow);
        
        while (second != nullptr) {
            ListNode* secondNext = second->next;
            second->next = first->next;
            first->next = second;
            first = first->next->next;
            second = secondNext;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
