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
    
    // 迭代版本
    // ListNode* reverseList(ListNode* head) {
    //     if (head == nullptr) {
    //         return head;
    //     }
        
    //     ListNode* newTail = head;
    //     ListNode* newHead = head;
    //     ListNode* visit = head->next;
                  
    //     while (visit) {
    //         ListNode* oldHead = newHead;
    //         newHead = visit;
    //         newTail->next = visit->next;
    //         visit = newHead->next;
    //         newHead->next = oldHead;
    //     }
        
    //     return newHead;
    // }   
    
    // 递归版本
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
