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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp1 , *temp2 , *nextnode;
        
        int count=0 , i=1;
        
        temp1=head;
        temp2=head;
        
        while(temp1!=0)
        {
            temp1=temp1->next;
            count++;
        }
        
        if(count==n)
        {
            temp1=head;
            head=temp1->next;
            delete(temp1);
        }
        
        else {
            
            while(temp2!=0)
            {
                if(i== count-n)
                {
                    nextnode = temp2->next;
                    temp2->next = temp2->next->next;
                    delete(nextnode);
                    break;
                }
            
                temp2 = temp2->next;
                i++;
                    
            }
        }
        
        return head;
        
    }
};