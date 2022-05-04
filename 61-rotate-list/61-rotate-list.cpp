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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        if(k==0)
            return head;
        
        int count=0;
        ListNode *temp=head , *prev;
        
        while(temp!=NULL)
        {
            count++;
            if(temp->next==NULL)
            {
                prev=temp;
            }
            temp=temp->next;
        }
        
        prev->next=head;
        k=k%count;  // taking remainder
        k=count-k;
        
        while(k--)
        {
            prev=prev->next;
        }
        
        head=prev->next;
        prev->next=NULL;
       return head; 
    }
};