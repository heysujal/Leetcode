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
    
    void reverseList(ListNode *head)
    {
        if(head==NULL or head->next == NULL)
            return ;
        
       reverseList(head->next);
        
        ListNode *tail = head->next;
        tail->next = head;
        head->next  = NULL;
        // return rest_head;
        
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // first find the node from which all of this starts
        // just one node before it
        if(!head or left==right)
            return head;

        ListNode *ptr1 =head;
        int s = 1;
        ListNode *prev = NULL;
        while(ptr1 and s!=left)
        {   
            prev = ptr1;
            ptr1 = ptr1 -> next;
            s++;
            
            
        }
        
        // now either ptr1 will be null or we 
        // will be ptr1 will be pointing to left
        // prev is pointing to before left
        
       ListNode *ptr2 = ptr1;
        
        while(s!=right and ptr2)
        {
            s++;
            ptr2=ptr2->next;
            
        }
        // ListNode *following = NULL;
        
         
         ListNode *following = ptr2 -> next;
        
        
        ptr2->next = NULL;
        
    
         
        reverseList(ptr1);
        // ListNode *revHead = reverseList(ptr1);
        
        
        
        ptr1 -> next = following;
        if(prev)
        {
            prev->next = ptr2;
            return head;
        }
       
        
        return ptr2;
        
    }
};