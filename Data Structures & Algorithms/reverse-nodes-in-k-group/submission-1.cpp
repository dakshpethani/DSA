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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode;
        while(temp!= nullptr)
        {
            ListNode* kthNode = findKthNode(temp,k);
            if(!kthNode)
            {
                if(prevNode)
                {
                    
                    prevNode->next = temp;
                    break;
                }
            }
            nextNode= kthNode->next;
            kthNode->next= nullptr;
            ListNode* prev = nullptr;
            ListNode* curr = temp;

            while(curr !=nullptr)
            {
                ListNode* next = curr->next;
                curr->next =prev;
                prev= curr;
                curr= next;
            }
            if(temp==head)
            {
                head= kthNode;
            }
            else
            {
                prevNode->next = kthNode;
                
            }
            prevNode = temp;
            temp=nextNode;
        }
        return head;

        

    }

private: 
    ListNode* findKthNode(ListNode* temp, int k )
    {
        k-=1;
        while(temp!=nullptr && k>0)
        {
            k--;
            temp= temp->next;
        }
        return temp;
    }
};
