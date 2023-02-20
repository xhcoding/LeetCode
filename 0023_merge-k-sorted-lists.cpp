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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode;
        auto cmp = [](ListNode* left, ListNode* right) { return left->val > right->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_queue(cmp);
        
        for (const auto& list : lists) {
            if (list != nullptr) {
                min_queue.push(list);
            }
        }
        
        ListNode* p = dummy;
        
        while (!min_queue.empty()) {
            ListNode* top = min_queue.top();
            min_queue.pop();
            p->next = top;
            if (top->next != nullptr) {
                min_queue.push(top->next);
            }
            p = p->next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
