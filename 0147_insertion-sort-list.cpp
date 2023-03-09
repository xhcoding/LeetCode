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
    
    // O(n^2)
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* sorted = insertionSortList(head->next);
        ListNode* cur = sorted;
        ListNode* curPre = nullptr;
        while (cur != nullptr) {
            if (cur->val < head->val) {
                curPre = cur;
                cur = curPre->next;
            } else {
                break;
            }
        }
        head->next = cur;
        if (curPre != nullptr) {
            curPre->next = head;
            return sorted;
        } else {
            return head;
        }
    }
    
    // while
//     ListNode* insertionSortList(ListNode* head) {
//         if (head == nullptr) {
//             return head;
//         }
//         ListNode dummy(-10000, head);
        
//         ListNode* pre = &dummy;
//         ListNode* cur = pre->next;
//         while (cur != nullptr) {
//             ListNode* visPre = &dummy;
//             ListNode* vis = visPre->next;
//             bool changePre = true;
//             while (vis != cur) {
//                 if (vis->val < cur->val) {
//                     visPre = vis;
//                     vis = visPre->next;
//                 } else {
//                     pre->next = cur->next;
//                     cur->next = vis;
//                     visPre->next = cur;
//                     changePre = false;
//                     break;
//                 }
//             }
//             if (changePre) {
//                 pre = cur;
//             }
//             cur = pre->next;
//         }
        
//         return dummy.next;
//     }
};
