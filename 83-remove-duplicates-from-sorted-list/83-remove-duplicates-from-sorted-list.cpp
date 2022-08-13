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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL or head->next == NULL)
                return head;
        
        
        ListNode* ptr = head;
        
        while(ptr != NULL)
        {
            ListNode* temp = ptr;
            while(temp->next!=NULL and temp->val==temp->next->val)
            {
                temp = temp->next;
                
            }
            
            ptr->next = temp->next;
            ptr = ptr->next;
            
            
        }
        
        return head;
        
    }
};