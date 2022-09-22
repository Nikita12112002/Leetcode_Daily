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
    
    ListNode* reverse(ListNode *temp)
    {
        if(temp==NULL || temp->next==NULL)
            return temp;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            ListNode* nextnode = temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
            
        }
        return prev;
    }
        
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow=slow->next;
        
        ListNode* dummy = head;
        
        while(slow!=NULL)
        {
            if(slow->val!=dummy->val)
                return false;
            slow=slow->next;
            dummy=dummy->next;
        }
        return true;
    }
};