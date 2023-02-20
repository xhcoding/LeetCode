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
static ListNode* last = nullptr;

class Solution {
public:
    // 递归版本
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || right == 1) {
            last = head->next; // 记录后面不需要翻转的节点
            return head;
        }
        
        auto newHead = reverseBetween(head->next, left - 1, right - 1);
        if (left <= 1) {
            head->next->next = head;
            head->next = last;
            return newHead;
        } else {
            head->next = newHead;
            return head;
        }
    }
};
