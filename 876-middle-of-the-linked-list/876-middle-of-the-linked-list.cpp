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
    int getLen(ListNode* head)
{
    int len = 0;

    if(head==NULL)
        return len;

    while (head!=NULL)
    {
        head=head->next;
        len++;

    }
    return len;

    
}
ListNode* getMiddle(ListNode* head)
{
    int toTraverse = getLen(head)/2;
    ListNode* curr = head;
    while(toTraverse--)
    {
        curr = curr->next;

    }

    return curr;
}
    
    
    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
        
    }
};