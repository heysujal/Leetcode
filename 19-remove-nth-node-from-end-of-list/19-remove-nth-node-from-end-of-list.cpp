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
    
int getLen(ListNode *head)
{
    int len = 0;

    if (head == NULL)
        return len;

    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

ListNode* nthNodeFromLast(ListNode *head, int n)
{
    int len = getLen(head);
    
    if (head == nullptr or n > len)
            return NULL;

    int times = len - n;
    if(times==0)
        return head->next;
    ListNode *curr = head;

    ListNode *ptr = head;
    while (times--)
    {   ptr = curr;
        curr = curr->next;
      
    }
    
    ptr -> next = curr->next;
    return head;
     
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return nthNodeFromLast(head, n);
        
    }
};