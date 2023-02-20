/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    // 将新生成的节点放到原节点后面，不需要额外的空间
    // 需要扫描三次链表
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        // 生成节点
        Node* cur = head;
        while (cur != nullptr) {
            Node* tmp = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = tmp;
            cur = tmp;
        }
        
        cur = head;
        // 处理 random
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 分离链表
        cur = head;
        Node* new_head = head->next;
        Node* new_cur = new_head;

        while (cur != nullptr) {
            cur->next = new_cur->next;
            cur = new_cur->next;
            if (cur != nullptr) {
                new_cur->next = cur->next;
                new_cur = cur->next;
            }
        }
        return new_head;
    }
    
    // 一趟扫描，空间使用会多
//     Node* copyRandomList(Node* head) {

//         Node* dummy = new Node(0);
//         Node* pre = dummy;
        
//         unordered_multimap<Node*, Node*> uncopy;
//         unordered_map<Node*, Node*> copied;
        
//         while (head != nullptr) {
//             Node* cur = new Node(head->val);
//             pre->next = cur;
//             pre = cur;
//             // handle random
//             if (head->random != nullptr) {
//                 auto iter = copied.find(head->random);
//                 if (iter != copied.end()) {
//                     cur->random = iter->second;
//                 } else {
//                     uncopy.emplace(head->random, cur);
//                 }
//             }
            
//             // handle uncopy
//             auto [first, second] = uncopy.equal_range(head);
//             for (auto iter = first; iter != second; ++iter) {
//                 iter->second->random = cur;
//             }
//             uncopy.erase(first, second);
            
//             copied.emplace(head, cur);
//             head = head->next;
//         }
        
//         Node* res = dummy->next;
//         delete dummy;
        
//         return res;
//     }
};
