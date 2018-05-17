/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:    
    void connect(TreeLinkNode *root) {
        TreeLinkNode *queue=root;
        TreeLinkNode *level=new TreeLinkNode(0);
        while(queue!=NULL){
            level->next=NULL;
            TreeLinkNode* current=level;
            while(queue!=NULL){
                if(queue->left!=NULL) {
                    current->next=queue->left;
                    current=current->next;
                }
                if(queue->right!=NULL) {
                    current->next=queue->right;
                    current=current->next;
                }
                queue=queue->next;
            }
            queue=level->next;
        }   
    }
};
