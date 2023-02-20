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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* preSlow = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            preSlow = slow;
            slow = slow->next;
        }
        
        
        ListNode* reversed = reverse(slow);
        
        
        ListNode* first = head;
        ListNode* second = reversed;
        bool result = true;
        while (second != nullptr) {
            if (first->val != second->val) {
                result = false;
                break;
            }
            first = first->next;
            second = second->next;
        }
        
        reversed = reverse(reversed);
        preSlow->next = reversed;
        
        return result;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
