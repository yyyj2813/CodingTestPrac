/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    unordered_set<ListNode *> s; 
    bool hasCycle1(ListNode *head) {
        if(head==nullptr) return false; 
        
        if(s.find(head)!=s.end()) return true;
        s.insert(head);
        
        return hasCycle(head->next);
        
    }
    bool hasCycle(ListNode *head) {
        ListNode * fp=head; 
        ListNode * sp=head; 
        while(!(fp==nullptr ||fp->next==nullptr)){
            sp = sp->next; 
            fp = fp->next->next;
            if(sp==fp) return true; 
        }
        return false; 
    }
};