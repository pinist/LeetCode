# LeetCode 201-300

[TOC]

## 207. Course Schedule

**Tag: Topological-sort**

**Solution:**

Topological-sort to judge the directed graph have loop. Pay attention to DFS for every node.

**Code:**

```c++
bool hasloop(int u){
    if(vis[u]==1) return 1;
    if(vis[u]==2) return 0;
    vis[u]=1;
    for(auto v: g[u]) if(hasloop(v)) return 1;
    vis[u]=2;
    return 0;
}

for(int i=0;i<numCourses;i++) {
	if(!vis[i]&&hasloop(i)) return 0;
}
```



## 210. Course Schedule II

**Tag: Topological-sort**

**Solution:**

Output the path of topological sort. Remember to reverse res(vector<int>).

**Code:**

```c++
bool dfs(int u){      //return true if has loop
    if(vis[u]==1) return 1;
    if(vis[u]==2) return 0;
    vis[u]=1;
    for(auto v:g[u]){
        if(dfs(v)) return 1;}
    vis[u]=2;
    res.push_back(u);
    return 0;
}
```



## 226. Invert Binary Tree

**Tag:DFS**

**Solution:**

This problem is similar to preorder of binary tree.  Pay attention to discuss the pointers of sub tree.

**Code:** 

```c++
if(root->left!=NULL&&root->right!=NULL) {
    TreeNode* tmp;
	tmp=root->left;
	root->left=root->right;
	root->right=tmp;
}
else if(root->left!=NULL&&root->right==NULL){
    root->right=root->left;
    root->left=NULL;
}
else if(root->left==NULL&&root->right!=NULL){
	root->left=root->right;
	root->right=NULL;
}
else return;
```



## 300. Longest Increasing Subsequence

**Tag: Dynamic processing**

**Solution:**

using lower-bound to save time complexity.

**Code:** 

```c++
for(int i=0; i<n;i++){
	int k=lower_bound(nlis.begin(),nlis.begin()+ans,nums[i])-nlis.begin();
	if(k==ans) ans++;
	nlis[k]=nums[i];
	dp[i]=ans+1;
}
```

