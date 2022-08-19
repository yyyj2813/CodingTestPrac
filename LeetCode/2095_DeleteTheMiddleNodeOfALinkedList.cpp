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
    pair<ListNode *, ListNode *> FindMiddle(ListNode* head){
        ListNode * fp=head;
        ListNode * sp=head;
        ListNode * bfp=nullptr; 
        while( fp!=nullptr && fp->next!=nullptr){
            fp=fp->next->next; 
            bfp=sp; 
            sp=sp->next; 
        }
        return {bfp,sp}; 
        
    }
    ListNode* deleteMiddle(ListNode* head) {
        auto ps= FindMiddle(head);
        ListNode * bf= ps.first; 
        ListNode * af= ps.second->next;
        if(ps.second==head) return nullptr; //하나짜리
        
        bf->next=af; 
        return head; 
    }
};