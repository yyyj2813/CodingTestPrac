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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> vec; 
        ListNode* it =head;
        
        while(it!=nullptr){
            vec.push_back(it);
            it=it->next; 
        }
        
        ListNode * rmv = vec[vec.size()-n];
        if(vec.size()-n == 0){
            return head->next; 
        }
        else {
            vec[vec.size()-n-1]->next=rmv->next; 
        }
        
        return head; 
    }
};