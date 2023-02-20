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
        while (head && head->next != nullptr) {
            if (head->val == head->next->val) {
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            } else {
                pos->next = head;
                head = head->next;
                pos = pos->next;
            }
        }
        pos->next = head;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
    
// 使用 set
//     ListNode* deleteDuplicates(ListNode* head) {
//         set<int> values;
//         ListNode* dummy = new ListNode;
        
//         ListNode* pos = dummy;
//         while (head != nullptr) {
//             if (values.count(head->val)) {
//                 ListNode* tmp = head;
//                 head = head->next;
//                 delete tmp;
//             } else {
//                 values.emplace(head->val);
//                 pos->next = head;
//                 head = head->next;
//                 pos = pos->next;
//             }
//         }
//         pos->next = nullptr;
//         ListNode* res = dummy->next;
//         delete dummy;
//         return res;
//     }
};
