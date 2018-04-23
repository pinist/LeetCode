/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
 */
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
       ListNode *deleteDuplicates(ListNode *head) {  
           if(head==NULL||head->next==NULL)  
               return head;  
           ListNode* p=head;  
           ListNode* q=head->next;  
           while(q!=NULL){  
               if(q->val==p->val) {  
                   q=q->next;  
               }
               else{  
                   p->next=q;  
                   p=q;  
                   q=q->next;  
               }  
           }  
           p->next=NULL;  
           return head;  
    } 
};