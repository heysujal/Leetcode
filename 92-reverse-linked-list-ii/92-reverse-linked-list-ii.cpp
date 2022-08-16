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
        while(s!=left)
        {   
            prev = ptr1;
            ptr1 = ptr1 -> next;
            s++;
            
            
        }
        
        //  ptr1 will be pointing to left
        // prev is pointing to before left
        
       ListNode *ptr2 = ptr1;
        
        while(s!=right)
        {
            s++;
            ptr2=ptr2->next;
            
        }
        // ptr2 points to right
        
        // following is node present after right(MAY BE NULL)
       ListNode *following = ptr2 -> next;
        
        // isolating left to right sublist 
       ptr2->next = NULL;
        
       //reversing the sublist 
       reverseList(ptr1);
       
        
       ptr1 -> next = following;
        if(prev)
        {
            prev->next = ptr2;
            return head;
        }
        return ptr2;
        
    }
};