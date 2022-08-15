/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        
        if(head==nullptr or head->next == nullptr)
            return NULL;
        
        
        ListNode* ptr = head;
        unordered_set<ListNode*> s;
        
        while(ptr!=NULL)
        {
            
            if(s.find(ptr)!=s.end())
            {
                return ptr;
            }
            
            s.insert(ptr);
            ptr = ptr->next;
            
            
        }
        
        
        return NULL;
    }
};