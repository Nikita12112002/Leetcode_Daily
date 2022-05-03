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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        //Brute_force-TC:O(m*n)
        
        ListNode *temp1=head1;
        ListNode *temp2=head2;
        
        while(temp2!=NULL)
        {
            temp1=head1;
            while(temp1!=NULL)
            {
                if(temp2==temp1)
                  return temp1;
                else
                  temp1=temp1->next;
            }  
            temp2=temp2->next;
        }   
        
        
        return NULL;
    }
};