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
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
      
        if(!p and !q)
            return p;
        if(!p and q)
            return q;
        if(p and !q)
            return p;
        
        ListNode *ans = new ListNode;
        ListNode *temp = ans;
        while(p and q)
        {
            
            if(p->val <= q->val)
            {
                temp->next = p;
                temp = temp->next;
                
                p = p->next;
                
            }
            else{
                temp->next = q;
                temp=temp->next;
                q= q->next;
            }
            
        }
        
        if(p)
            temp->next = p;
        if(q)
            temp->next = q;
        
        
        return ans->next;
            
    }
};