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
     ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        
        
        if(head==NULL or head->next == NULL)
        {   
            return head;
            
        }
         ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        // reverse first k nodes
        int count = 0 ;
        
        
        ListNode* prev =NULL;
        ListNode* curr =head;
        ListNode* next=NULL;
        
        while(count<k and curr!=NULL)
        {
            count++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        
        }
        
        if(curr!=NULL)
        {
            
            ListNode* rest_head = reverseKGroup(curr, k);
            
            head->next = rest_head;
            
            
            
        }
            
        
    
        return prev;
        
       
        
    }
    ListNode* swapPairs(ListNode* head) {
    
      
        
     int k = 2;
        
        return reverseKGroup(head , k);
        
    }
    
    
};