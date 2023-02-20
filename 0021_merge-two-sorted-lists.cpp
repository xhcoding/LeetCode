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
    // no head node
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if (list1 == nullptr) {
    //         return list2;
    //     }
    //     if (list2 == nullptr) {
    //         return list1;
    //     }
    //     ListNode* pos1 = nullptr;
    //     ListNode* pos2 = nullptr;
    //     ListNode* res = nullptr;
    //     if (list1->val < list2->val) {
    //         pos1 = list1;
    //         res = list1;
    //         pos2 = list2;
    //     } else {
    //         pos1 = list2;
    //         res = list2;
    //         pos2 = list1;
    //     }
    //     while (true) {
    //         if (pos1->next == nullptr) {
    //             pos1->next = pos2;
    //             return res;
    //         }
    //         if (pos2 == nullptr) {
    //             return res;
    //         }
            
    //         if (pos1->next->val < pos2->val) {
    //             pos1 = pos1->next;
    //         } else {
    //             ListNode* tmp = pos1->next;
    //             pos1->next = pos2;
    //             pos2 = pos2->next;
    //             pos1->next->next = tmp;
    //             pos1 = pos1->next;
    //         }
    //     }
    // }
    
    // head node
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* pos = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                pos->next = list1;
                list1 = list1->next;
            } else {
                pos->next = list2;
                list2 = list2->next;
            }
            pos = pos->next;
        }
        if (list1 == nullptr) {
            pos->next = list2;
        }
        if (list2 == nullptr) {
            pos->next = list1;
        }
        ListNode* res = head->next;
        delete head;
        return res;
    }
};
