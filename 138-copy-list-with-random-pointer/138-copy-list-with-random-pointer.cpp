/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* newnode = new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        
        temp=head;
        
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
              temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
        
        Node* dummy = new Node(0);
        Node* itr=head ,*fast;
        temp=dummy;
        
        
        while(itr!=NULL)
        {
              fast=itr->next->next;
              temp->next=itr->next;
              itr->next=fast;
              itr=fast;
              temp=temp->next;
        }
        
        return dummy->next;
    }
};