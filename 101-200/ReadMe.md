## 102. Binary Tree Level Order Traversal

**Tag: BFS**

**Solution:**

using two queue 

```c++
while(!qu.empty()){
 	vec.clear();
	while(!qu.empty()){
		if(qu.front()->left!=NULL) tmp.push(qu.front()->left);
		if(qu.front()->right!=NULL) tmp.push(qu.front()->right);
		vec.push_back(qu.front()->val);
		qu.pop();
	}
	while(!tmp.empty()){
		qu.push(tmp.front());
		tmp.pop();
	}
	res.push_back(vec);
}
```

## 103. Binary Tree Zigzag Level Order Traversal

**Tag: BFS**

**Solution:**

using two queue and reverse function of vector

```c++
if(i) res.push_back(vec);
else{
	reverse(vec.begin(), vec.end());
    res.push_back(vec);
}
i=!i;
```



## 104. Maximum Depth of Binary Tree 

**Tag: DFS**

**Solution:**

The recursive termination condition is a empty node, otherwise it returns the maximum height of the sub tree +1.

**Remark:**

This problem is similar to 110.



**Code:**

```c++
if(!root)  return 0;
return max(maxDepth(root->left),maxDepth(root->right))+1;
```



## 105. Binary Tree Zigzag Level Order Traversal

**Tag: DFS**

**Solution:**

Maintaining four position:  the start and end position of preorder and inorder

**Pay attention to the return value. Only if the return value is pointer, the tree can be set and connected.**

**Code:**

```c++
TreeNode* build(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2) 
        return NULL;        
    TreeNode *tmp;
    int cnt=0;
    tmp=new TreeNode(pre[l1]);
    for(int i=l2;i<=r2;i++){
        if(in[i]==tmp->val) {
            cnt=i-l2;break;
        }
    }
    tmp->left=build(l1+1,l1+cnt,l2,l2+cnt-1);
    tmp->right=build(l1+cnt+1,r1,l2+cnt+1,r2);
    return tmp;
}
```



**Test Data:**  

$preorder = [3,9,20,15,7]$

$inorder = [9,3,15,20,7]$



## 107. Binary Tree Level Order Traversal II

**Tag: DFS**

**Solution:** 

Using DFS, $vector<int>, vector<vector<int>> $  to solve the problem,

**Code:**

```c++
vector<vector<int>> res;
void pushlevel(TreeNode* root,int depth){
	if(root==NULL) return;
	if(res.size()==depth) res.emplace_back();
	res[depth].push_back(root->val);
	pushlevel(root->left,depth+1);
	pushlevel(root->right,depth+1);
	return;
}
```



## 110. Balanced Binary Tree

**Tag: DFS**

**Solution:** 

This problem is similar to 104.

**Code:**

```c++
if(abs(istree(root->left)-istree(root->right);)>1)  f=0;
```



## 112. Path Sum

**Tag: DFS**

**Solution:** 

Use depth information

```c++
void hassum(TreeNode* root, int sum1){
	if(!root||f) return;
	else if(!root->left&&!root->right){
		sum1+=root->val;
		if(sum1>s) return;
		else if(sum1==s){
			f=1;return;
        }
    }
    else{
		hassum(root->left,sum1+root->val);
		hassum(root->right,sum1+root->val);
    }return;
}
```



## 114. Flatten Binary Tree to Linked List

**Tag: DFS**

**Solution:** 

Using DFS to store the preorder result and then construct new Tree.

**Code:**

```c++
void dfs(TreeNode* root){
	if(root==NULL) return;
	tmp.push_back(root->val);
	dfs(root->left);dfs(root->right);
	return;
}
TreeNode* convert(TreeNode *root,int dep){
	if(dep==tmp.size()) return NULL;  
	if(dep) root=new TreeNode(tmp[dep]);
	root->left=NULL;
	root->right=convert(root->right,dep+1);
	return root;
}
```



## 116. Populating Next Right Pointers in Each Node

**Tag: BFS**

**Solution:** 

If the left child of the current node is not empty, the next point of the left child points to the right child of the current node.

If the right child of the current node is not empty and the next node of the current node is not empty, the right child of current node points to the left child of the next node of the current node.

```c++
TreeLinkNode* lstart;lstart=root;
	while(lstart!=NULL){
	TreeLinkNode* cur;cur=lstart;
	while(cur!=NULL){
		if(cur->left!=NULL) cur->left->next=cur->right;
         if(cur->right!=NULL&&cur->next!=NULL) cur->right->next=cur->next->left;
         cur=cur->next;
    }
    lstart=lstart->left;
}
```



## 129. Sum Root to Leaf Numbers

**Tag: DFS**

**Solution:**

Use depth information.

**Code:**

```c++
 void dfs(TreeNode* root, int c){        
        if(root==NULL) {
            return;
        }
        int tmp=c*10+(root->val);
        if(root->left==NULL&&root->right==NULL) ans+=tmp;
        
        dfs(root->left,tmp);
        dfs(root->right,tmp);
        return;
    }
```



## 141. Linked List Cycle

**Tag: DFS**

**Solution:**

Use two pointers. One moves one step every time, the other moves two steps.

**Code:**

```c++
while(first!=NULL&&second!=NULL&&second->next!=NULL){ 
	first=first->next;  
	second=second->next->next;  
	if(first==second)  return true;  
}  
```



## 141. Linked List Cycle

**Tag: DFS**

**Solution:**

Use two pointers. One moves one step every time, the other moves two steps.

**Code:**

