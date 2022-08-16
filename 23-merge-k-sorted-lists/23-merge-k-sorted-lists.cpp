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
    
      ListNode *merge(ListNode *p, ListNode *q)
    {
        
        if(!p )
            return q;
        if(!q)
            return p;
        
        if(p->val <= q->val)
        {
            p->next = merge(p->next, q);
            return p;
            
        }
        else 
        {
            q->next = merge(p, q->next);
            return q;
        }
        
        
        
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int val = -10001;
        ListNode *dummy = new ListNode(val);
        
        for(auto list : lists)
        {
            dummy = merge(dummy, list);
            
        }
        return dummy->next;
        
    }
};