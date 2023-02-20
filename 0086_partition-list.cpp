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
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode;
        ListNode* list2 = new ListNode;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        
        while (head != nullptr) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = list2->next;
        p2->next = nullptr;
        ListNode* res = list1->next;
        delete list1;
        delete list2;
        return res;
    }
};
