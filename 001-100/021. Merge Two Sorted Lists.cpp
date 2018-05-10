/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL, *now=NULL;
        while(l1!=NULL||l2!=NULL)
        {
            if(head==NULL)
            {
                if(l2==NULL&&l1!=NULL)
                {
                    now=head=l1;
                    l1=l1->next;
                }
                else if(l1!=NULL&&l2!=NULL&&l1->val<l2->val){
                    now=head=l1;
                    l1=l1->next;
                }
                else if(l2!=NULL&&l1==NULL)
                {
                    now=head=l2;
                    l2=l2->next;
                }
                else if(l1!=NULL&&l2!=NULL&&l1->val>=l2->val){
                    now=head=l2;
                    l2=l2->next;
                }
            }
            else
            {
                if(l2==NULL&&l1!=NULL)
                {
                    now->next=l1;
                    l1=l1->next;
                }
                else if(l1!=NULL&&l2!=NULL&&l1->val<l2->val){
                    now->next=l1;
                    l1=l1->next;
                }
                else if(l2!=NULL&&l1==NULL)
                {
                    now->next=l2;
                    l2=l2->next;
                }
                else if(l1!=NULL&&l2!=NULL&&l1->val>=l2->val){
                    now->next=l2;
                    l2=l2->next;
                }
                now=now->next;
            }
        }
        return head;
    }
};