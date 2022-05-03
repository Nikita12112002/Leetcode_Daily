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
    ListNode* middleNode(ListNode* head) {
 // approach 1- counting length
//         int count=0;
//         ListNode *temp=head;
//         while(temp!=NULL)
//         {
//             count++;
//             temp=temp->next;
            
//         }
        
//         for(int i=0 ;i<count/2 ;i++)
//         {
//             head=head->next;
//         }
//         return head;
        
     //approach 2- slow and fast pointer     
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    
    }
};