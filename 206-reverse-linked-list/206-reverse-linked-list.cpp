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
    ListNode* reverseList(ListNode* head) {
         
        if(head==NULL)
                return nullptr;
        ListNode* next = head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        
        while(next!=NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
            
        }
        
        curr->next = prev;
        
        return curr;
        
        
        
    }
};