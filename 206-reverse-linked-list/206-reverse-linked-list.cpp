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
            return head;
        
        if(head->next==NULL)
            return head;
        
        ListNode *prev,*next;
        next=head;
        prev=0;
        
        while(head!=NULL)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next; //note that here head=head->next can not be used bcoz link has been broken we cant access next element
        }
        
        return prev;
    }
};