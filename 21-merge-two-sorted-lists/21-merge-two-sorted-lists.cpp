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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *temp1=l1 , *temp2=l2  ;
        ListNode *temp3 = new ListNode();
        
        ListNode *dummy = new ListNode();
        ListNode *prev;
        
        if(l1==NULL && l2 !=NULL)
        {
            return l2;
        }
        
       else if(l1!=NULL && l2==NULL)
        {
            return l1;
        }
        
        else if(l1==NULL && l2==NULL)
        {
            return l1;
        }
        
        else{
        
        while(temp1!=NULL && temp2!=NULL)
        {
            if(dummy->next==NULL)
            {
                if(temp1->val <= temp2->val)
             {
                ListNode *node= new ListNode(temp1->val);
                node->next= NULL;
                dummy->next = node;
                temp3 = node;
                prev = node;
                temp1 = temp1->next;
                 
               
            }
            
            else
            {
                ListNode *node= new ListNode(temp2->val);
                node->next= NULL;
                dummy->next=node;
                temp3 = node;
                prev = node;
                temp2 = temp2->next;
               
            }
                       
    }
            
    else{
            if(temp1->val <= temp2->val)
            {
                ListNode *node= new ListNode(temp1->val);
                node->next= NULL;
                dummy->next = node;
                prev->next = node;
                prev = node;
                temp1 = temp1->next;
                 
               
            }
            
            else
            {
                ListNode *node= new ListNode(temp2->val);
                node->next= NULL;
                dummy->next=node;
                prev->next = node;
                prev = node;
                temp2 = temp2->next;
               
            }
        }
        }
        
       while(temp1!=NULL)
       {
                ListNode *node= new ListNode(temp1->val);
                node->next= NULL;
                dummy->next=node;
                prev->next = node;
                prev = node;
                temp1 = temp1->next;
       }
        
        while(temp2!=NULL)
        {
            ListNode *node= new ListNode(temp2->val);
                node->next= NULL;
                dummy->next=node;
                prev->next = node;
                prev = node;
                temp2 = temp2->next;
        }
        
       return temp3 ;
        }
    }
};