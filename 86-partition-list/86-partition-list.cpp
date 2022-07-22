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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* left=new ListNode(0);
        ListNode*  right=new ListNode(0);
        ListNode *leftend,*rightend;
        leftend=left;
        rightend=right;
        
        while(head!=NULL)
        {
            if(head->val<x)
            {
                leftend->next=head;
                leftend=leftend->next;
            }
            else
            {
                rightend->next=head;
                rightend=rightend->next;
            }
            
            head=head->next;
        }
        
        leftend->next=right->next;
        rightend->next=NULL;
        
        return left->next;
    }
};