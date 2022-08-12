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
    int len =  getLen(head);
    if(len-n==0)
        return head->next;
    if (head == NULL or n > getLen(head) or n < 0)
            return head;

    ListNode *first = head;
    ListNode *second = head;

    while (n--)
    {

        first = first->next;
    }
    ListNode *ptr = NULL;

    while (first != NULL)
    {
        first = first->next;
        ptr = second;
        second = second->next;
    }

    ptr->next = second->next;
    return head;
    
   
     
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return nthNodeFromLast(head, n);
        
    }
};