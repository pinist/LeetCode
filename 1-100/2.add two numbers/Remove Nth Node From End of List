/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {  
        ListNode*ptr1 = head;  
        int count =1;  
        while(ptr1->next != NULL)  
        {  
            ptr1 = ptr1->next;  
            count ++;  
        }  
        n= count - n;  
        if(n == 0)  
        {  
            ptr1=head;  
            head=head->next;  
            delete ptr1;  
            return head;  
        }  
        ptr1 = head;  
        ListNode*ptr2=head;  
        while(n --)  
        {  
            ptr1= ptr1->next;  
        }  
        while(ptr2!=ptr1&&ptr2->next != ptr1)  
        {  
            ptr2=ptr2->next;  
        }  
        ptr2->next = ptr1->next;  
        delete ptr1;  
        return head;  
    }  
};