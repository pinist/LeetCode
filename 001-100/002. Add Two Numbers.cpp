/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//solution 1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp=0;
        ListNode * head,* now;
        now=head=NULL;
        while(l1!=NULL||l2!=NULL){
            if(head==NULL){
                now=head=new ListNode(0);
            }
            else{
                 now->next=new ListNode(0);
                 now=now->next;
            }
            
            if(l1!=NULL&&l2!=NULL)
            {
                if((l1->val)+(l2->val)+tmp>=10)
                {
                    now->val=(l1->val)+(l2->val)-10+tmp;
                    tmp=1;
                }
                else
                {
                    now->val=(l1->val)+(l2->val)+tmp;
                    tmp=0;
                }
                l1=l1->next;
                l2=l2->next;
            }
            else{
                if(l2!=NULL){
                    if((l2->val)+tmp>=10)
                    {
                        now->val=(l2->val)-10+tmp;
                        tmp=1;
                    }
                    else{
                        now->val=(l2->val)+tmp;
                        tmp=0;
                    }
                    l2=l2->next;
                }
                else
                {
                    if((l1->val)+tmp>=10)
                    {
                        now->val=(l1->val)-10+tmp;
                        tmp=1;
                    }
                    else{
                        now->val=(l1->val)+tmp;
                        tmp=0;
                    }
                    l1=l1->next;
                }
                
            }
            
        }
        if(tmp!=0){
            now->next=new ListNode(0);
            now=now->next;
            now->val=tmp;
        }
        return head;
    }
};

solution 2：
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*now=NULL;
        int tmp=0;
        while(l1!=NULL||l2!=NULL)
        {
            if(head==NULL)
                now=head=new ListNode(0);
            else
            {
                now->next=new ListNode(0);
                now=now->next;
            }
            now->val=tmp;
            if(l1!=NULL)
            {
                now->val+=l1->val;
                l1=l1->next;
            }  
            if(l2!=NULL)
            {
                now->val+=l2->val;
                l2=l2->next;
            }
            tmp=now->val/10;
            now->val%=10;
        }
        if(tmp)
            now->next=new ListNode(tmp);
        return head;
    }
};