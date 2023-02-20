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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        int length = 0;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            length++;
            tail = tail->next;
        }
        length++;
        
        int actual_k = k % length;
        if (actual_k == 0) {
            return head;
        }
        ListNode* visit = head;
        for (int i = 1; i < length - actual_k; i++) {
            visit = visit->next;
        }
        ListNode* new_head = visit->next;
        visit->next = nullptr;
        tail->next = head;
        return new_head;
    }
};
