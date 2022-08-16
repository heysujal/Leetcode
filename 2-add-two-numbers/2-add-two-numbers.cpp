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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        if(!l1->next and !l2->next and l1->val + l2->val ==0)
        {
            return l1;
        }
        
        
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *ans = new ListNode;
        ListNode *temp = ans;
        int carry = 0;
        int sum = 0;
        while(p and q)
        {
            sum = p->val + q->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            p=p->next;
            q=q->next;    
        }
        
        while(p)
        {   
            sum = p->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            p=p->next;
        }
        
        while(q)
        {
            sum = q->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            q=q->next;
        }
        
        
        if(carry!=0)
            temp->next = new ListNode(carry);
        
        
        return ans->next;
    }
};