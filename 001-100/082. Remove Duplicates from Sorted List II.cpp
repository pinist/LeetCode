/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5
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
        ListNode **runner=&head;        
        if(!head||!head->next)return head;       
        while(*runner)
        {
            if((*runner)->next&&(*runner)->next->val==(*runner)->val)
            {
                ListNode *temp=*runner;
                while(temp&&(*runner)->val==temp->val)
                    temp=temp->next;                
                *runner=temp;
            }
            else
                runner=&((*runner)->next);
        }
        
        return head;
    }
};