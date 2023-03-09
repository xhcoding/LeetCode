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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nextSubHead = head;
        ListNode* newHead = nullptr;
        ListNode* preTail = nullptr;
        ListNode* cur = head;
        while (nextSubHead != nullptr) {
            int i = 0;
            for (; i < k; i++) {
                if (nextSubHead == nullptr) {
                    break;
                }
                nextSubHead = nextSubHead->next;
            }
            if (i != k) {
                break;
            }
            
            ListNode* pre = nextSubHead;
            ListNode* tail = cur;
            while (cur != nextSubHead) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            if (preTail != nullptr) {
                preTail->next = pre;
            }
            preTail = tail;
            if (newHead == nullptr) {
                newHead = pre;
            }
        }
        
        return newHead ? newHead : head;
    }
};
