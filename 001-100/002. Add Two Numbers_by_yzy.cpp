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