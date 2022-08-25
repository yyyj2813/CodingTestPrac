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
    pair<ListNode *,ListNode *> FindStartPoint(ListNode* head){
        ListNode * fp=head; 
        ListNode * sp=head; 
        while( fp!=nullptr && fp->next!=nullptr ){
            fp=fp->next->next;
            sp=sp->next; 
        }
        return {fp, sp}; 
    }
    bool isPalindrome(ListNode* head) {
        stack<ListNode *> st; 
        auto  ret = FindStartPoint(head); 
        ListNode * it=head; 
        
        ListNode * mi= ret.second; 
        while(it!=mi){
            st.push(it); 
            it=it->next; 
        }
        
        if(ret.first!=nullptr) mi=mi->next;  //홀수 개 일때 
            
        while(!st.empty() &&(mi!=nullptr)){ 
            auto now= st.top(); 
            if(now->val==mi->val) st.pop(); 
            else return false; 
            
            mi=mi->next; 
        }
        if(!st.empty()) return false; 
        return true; 
        
    }
};