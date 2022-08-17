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
    ListNode* merge(ListNode *h1, ListNode *h2)
    {   
        // if(!h1)
        //     return h2;
        // if(!h2)
        //     return h1;
        ListNode *dummy = new ListNode;
        ListNode *temp= dummy;
        
        while(h1 and h2)
        {
            
            if(h1->val <= h2->val)
            {
                temp->next = h1;
                h1 = h1->next;
                
                
            }
            else{
                temp->next = h2;
                h2 = h2->next;
                
                
            }
            
            temp = temp->next;
            
            
        }
        if(h1)
            temp->next = h1;
        if(h2) 
            temp->next = h2;
        
        
        
        
        
        return dummy->next;
        
    }
    ListNode* sortList(ListNode* head) {
        
        
        if(!head or !head->next)
            return head;
        
      ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //divide the list into two parts 
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
         
        
        
    }
};