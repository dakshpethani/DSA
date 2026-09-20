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
    void insertCopy(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            copy->next= nextElement;
            temp->next=copy;

            temp = temp->next->next;
        }
    }
    void connectRandom(Node* head)
    {
        Node* temp = head;
        while(temp!= nullptr)
        {
            Node* copy = temp->next;
            if(temp->random)
            {
                copy->random = temp->random->next;
            }
            else
            {
                copy->random =nullptr;
            }
            temp= temp->next->next;

        }
    }
    Node* getDeepCopy(Node * head)
    {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp!= nullptr)
        {
            res->next = temp->next;
            res=res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        insertCopy(head);
        connectRandom(head);
        return getDeepCopy(head);

        
         
        
    }
};
