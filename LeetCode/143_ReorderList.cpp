
class Solution {
public:
    
    ListNode * getLast(ListNode * head){
        if( head == nullptr || head->next==nullptr ) return head; 
        
        ListNode * iter= head; 
        
        while( (iter->next)!=nullptr && (iter->next->next) != nullptr){
            iter=iter->next; 
        }
        
        auto tmp = iter->next;
        
        iter->next=nullptr; 
        
        return tmp; 
        
    }
    void reorderList(ListNode* head) {
        // reorderList1(head);
        reorderList2(head);
    }
    void reorderList1(ListNode* head) {
        
        if(head==nullptr) return ;
        ListNode * n2 = head->next; //2
        if(n2==nullptr) return; 
        
        ListNode * last = getLast(head); //3
        head->next=last; 
        
        if(last==n2) return; //이거 안하면 recursive
        
        last->next=n2; 
        
        reorderList(n2);
        
    }
}