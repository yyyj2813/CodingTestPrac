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
#include <vector> 
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<ListNode * >vec; 
        ListNode* iter=head; 
        while(iter!=nullptr){
            vec.push_back(iter);
            iter=iter->next; 
        }        
        
        int max_val=0; n
        int i=0; 
        
        while(i < vec.size()/2){
            int sum = vec[i]->val + vec[vec.size()-1-i]->val; 
            max_val=max(max_val, sum);
            ++i;
        }
        
        return max_val; 
        
    }
};