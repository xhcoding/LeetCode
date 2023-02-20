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
    // 模拟版本
    // ListNode* swapPairs(ListNode* head) {
    //     ListNode* dummy = new ListNode;
    //     ListNode* pos = dummy;
    //     pos->next = head;

    //     ListNode* p1 = head;
    //     ListNode* p2 = nullptr;

    //     while (p1 != nullptr && p1->next != nullptr) {
    //         p2 = p1->next;
            
    //         pos->next = p2;
            
    //         ListNode* tmp = p2->next;
    //         p2->next = p1;
            
    //         p1 = tmp;
            
    //         pos = pos->next->next;
    //         pos->next = p1;
    //     }
        
    //     ListNode* res = dummy->next;
    //     delete dummy;
    //     return res;
    // }
    
    // 递归版本
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }

};
