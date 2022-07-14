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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return NULL;
        
        vector<int> ans;
        
        for(auto head : lists){
            //for empty LL
            if(head==NULL)
                continue;
            ListNode* temp = head;
            
            while(temp!=NULL){
                ans.push_back(temp->val);
                temp = temp->next;
                
                
            }        
        }
        
        sort(ans.begin(), ans.end());
        
        
        ListNode* ptr = new ListNode();
        ListNode* aux  = ptr;
        
         
        
        for(auto x: ans){
           
            ListNode* newNode = new ListNode(x);
            ptr -> next = newNode;
            ptr = ptr->next;
        
        }
//         //Join all lists
        
//         int k = lists.size();
//         k--; // we don't need to do process below for last list
//         int i  = 0;
        
//         while(k--)
//         {
//             ListNode* temp =  lists[i];
//             while(temp->next!=NULL){
//                 temp = temp->next;
                
//             }
            
//             temp -> next = lists[i+1];
            
            
//         }
        
        
//         ListNode* finHead = lists[0];
//         int idx = 0;
        
//         while(finHead != NULL){
//             finHead->val = ans[idx++];
//             finHead = finHead -> next;
            
//         }
        
        
//         for(auto x : ans){
//         cout<<x<<" ";
            
//         }
        
        
        
        
        return aux->next;
        
        
    }
};