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
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2; 
        if(list2==nullptr) return list1; 
        if(list1->val>list2->val) return mergeTwoLists(list2,list1);
        
        ListNode * l1=list1;
        ListNode * l2= list2;
        
        while( !(l1->next==nullptr)){
            if(l2==nullptr)  l1 = l1->next; 
            else if( l1->val <= l2->val){
                if(l2->val <= l1->next->val){
                    ListNode *tmp1 =l1->next;
                    ListNode *tmp2 =l2->next;
                    l1->next = l2; 
                    l2->next = tmp1;
                    l2 = tmp2; 
                }
                else {
                    l1=l1->next; 
                }
            }
        }
        
        l1->next=l2; 
        l1 = l2; 
        return list1; 
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeTwoLists1(list1, list2);
        //return mergeTwoLists2(list1, list2);
    }
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        
        if(list1==nullptr) return list2; 
        if(list2==nullptr) return list1; 
        
        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1; 
        }
        
        else {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2; 
        }
    }
};