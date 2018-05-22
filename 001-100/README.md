# LeetCode 001-100



[TOC]

## 002. Add Two Numbers   

**Tag: List**

**Solution:**

Comply with the principle of adder

**Code:**

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


## 003. Longest Substring Without Repeating Characters

**Tag:Ad-Hoc**

**Solution:**

Using map to store the position of the last character



**Code:**

```c++
pre=(ma.find(s[i])->second)+1;
remax=max(remax,i-pre+1);
ma.clear();
ma[s[pre]]=pre;
i=pre;
```


## 006. Zigzag Conversion

**Tag: Ad-Hoc**

**Solution:**

$\begin{matrix}P& &A& &H& &N \\A&P&L&S&I&I&G\\Y& &I& & R \end{matrix}$

The nth rows in the transformed string matrix is: 1->2->3->2->1...



**Code:**

```c++
int p=0,f=0,i=0;
while(i<s.size()){
	while(p<numRows&&!f){
	ans[++p].push_back(s[i++]);
	if(i==s.size()) break;
	if(p==numRows) f=1;
    }
while(p>0&&f){
	ans[--p].push_back(s[i++]);
	if(i==s.size()) break;
	if(p==1) f=0;
	}
}
```


## 009. Palindrome Number

**Tag: Ad-Hoc**

**Solution:**

When reverse Palindrome Number, it  equals to the previous number.

**Code:**

```c++
while(x){
	after=(after*10)+(x%10);
     x/=10;
}
return before==after;
```


## 019. Remove Nth Node From End of List

**Tag:list**

**Solution:**

Maintain two pointers,and the distance of these two pointers is N. Because they move together, When the second pointer arrives at the end, the first one approaches to the Nth Node From end of list.

**Code:**

 

```c++
ListNode** t1=&head,*t2=head;
for(int i=1;i<n;++i)  
	t2 = t2->next;
	while(t2->next != NULL){
 		t1 = &((*t1)->next);
		t2 = t2->next;
    }
	*t1 = (*t1)->next;
 
```


## 020. Valid Parentheses

**Tag: stack**

**Solution:**

If s[i] is left parenthesis,put it into stack. If s[i] is the right parenthesis and it matches the top element of the stack, the top of the stack will be removed. Otherwise, an error value will be returned. Finally, stack need to be checked whether it is empty or not.

**Code:**

```c++
 for(int i=0;i<si;i++){
 	if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
	else{
		if(st.empty()) return false;
		else {
			if(s[i]==')'&&st.top()=='('||s[i]==']'&&st.top()=='['||s[i]=='}'&&st.top()=='{')
				st.pop();
			else return false;
		}
	}
}
```


## 026. Remove Duplicates from Sorted Array

**Tag: Ad-Hoc**

**Solution:**

The function of unique removes several adjacent repeating elements.

unique Time:$O(n)$

**Code:**

```c++
nums.erase(unique(nums.begin(),nums.end()),nums.end())
```



## 034. Search for a Range

**Tag: Binary-Search**

**Solution:**

Upper_bound(target)=lower_bound(target+1)-1

**Code:**

```c++
while(start<=end){
	mid=start+(end-start)/2;
 	if(target<=nums[mid]){
 	ans=min(ans,mid);
 	end=mid-1;
 	}
 	else start=mid+1;
 }
 return start;
```



## 035. Search Insert Position##

**Tag: Ad-Hoc**

**Solution:**

using lower-bound. Time: $O(logN) $

```c++
lower_bound(nums.begin(),nums.end(),target)-nums.begin();
```



## 048. Rotate Image

**Tag: Ad-Hoc**

**Solution:**

An algorithm of image processing

2x2:

$ \begin{matrix}a&b\\c&d \end{matrix}$  -> $ \begin{matrix}c&a\\d&b\end{matrix} $ 

3x3:  

$\begin{matrix}a&b&c\\d&e&f\\g&h&i\end{matrix}$ -> $\begin{matrix}g&d&a\\h&e&b\\i&f&c\end{matrix}$ 

$\begin{matrix}A&B&c\\d&e&f\\g&H&I\end{matrix}$ ->  $\begin{matrix}g&d&A\\H&e&B\\I&f&c\end{matrix}$




**Code:**

```c++
for(int i=0;i<(n>>1);i++){
    for(int j=0;j<(n+1)/2;j++){
        int tmp=matrix[i][j];
        matrix[i][j]=matrix[n-1-j][i];
        matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
        matrix[j][n-1-i]=tmp;
    }
}
```



## 051. N-Queens 

**Tag:Backtracking**

**solution:**  C[cur]=i; cur means the current line. I means i th row which  accord with condition.

```c++
if(cur==n){            
	tmp.assign(n,string(n,'.'));
	for(int i=0;i<n;i++)
		tmp[i][C[i]]='Q';
	ans.push_back(tmp);
}
```



## 052. N-Queens II

**Tag:Backtracking **

**Solution:**

l2 means the main diagonal, l1 means minor diagonal;

**Code:**

```c++
void dfs(int cur){
       if(cur==n) { 
           ans++;
           return;
       } 
       for(int i=0;i<n;i++){
           if(!vis[i]&&!l1[cur+i]&&!l2[cur-i+n]){
               vis[i]=l1[cur+i]=l2[cur-i+n]=1;
               dfs(cur+1);
               vis[i]=l1[cur+i]=l2[cur-i+n]=0;
           }
       }
        return;     
    }
```



## 053.Maximum Subarray

**Tag:Dynamic Processing**

**Solution:**

If($dp[i-1]<0$), $dp[i]=nums[i]$;

else $dp[i]=dp[i-1]+1$

**Code:**

```c++
for(int i=0;i<n;i++) dp.push_back(nums[i]);
int res=dp[0];
for(int i=1;i<n;i++) {
 	if(dp[i-1]>0) dp[i]=dp[i-1]+nums[i];
 	res=max(res,dp[i]);
}
```



## 062. Unique Paths 

**Tag: Dynamic Programming**

**Solution:**

DP$[i][j]$  means The number of paths to a $i,j$

$DP$$[i][j]$ =DP$[i-1][j]$+DP$[i][j-1]$

```c++
for (int i=0;i<n;i++){
	for (int j=0;j<m;j++){
		if (i==0||j==0) dp[i][j]=1;
		else dp[i][j]= dp[i-1][j]+dp[i][j-1];
	}
}
```



## 063. Unique Paths II

**Tag: Dynamic Programming**

**Solution:**

DP$[i][j]$  means The number of paths to a $i,j$

$DP$$[i][j]$ =DP$[i-1][j]$+DP$[i][j-1]$ 

Need to handle the corner case that when $i=0||j=0$



```c++
for(int i=0;i<m;i++){
	if(g[0][i]==0) dp[0][i]=1;
	else break;
}
for(int i=0;i<n;i++) {
	if(!g[i][0]) dp[i][0]=1;
	else break;
}
```



## 064. Minimum Path Sum

**Tag: Dynamic Programming**

**Solution:**

DP$[i][j]$  means The minimum number of paths to a $i,j$ 

Because the $dp[i][j]$ is conducted by the previous row, it can be compressed to $ dp[i]$

$dp[i]=min(dp[j]+grid[i][j],dp[j-1]+grid[i][j]);$

```c++
for(int i=1;i<m;i++){
	for(int j=0;j<n;j++){
		if(j==0) dp[j]=dp[j]+grid[i][j];
		else dp[j]=min(dp[j]+grid[i][j],dp[j-1]+grid[i][j]);
	}
}
```



## 069. Sqrt(x)

**Tag:Binary Search **

**Solution:**

Using the binary search to find sqrt(x);

**Code:**

```c++
int start=0,end=x;
	while(start+1<end){
		int mid=start+(end-start)/2;
		if(x/mid==mid) return mid;
		else if(x/mid>mid) start=mid;
		else end = mid;
	}
    if(x/end==end) return end;
	return start;
```



## 091. Decode Ways

**Tag: Dynamic Processing**

**Solution:**

If only a single s[i] is translated, then the type of translation is DP[i]. If the value of the string formed by s[i-1] and s[i] is less than or equal to 26, then there may be another DP[i-1] translation method. 

If the string formed by s[i-1] and s[i] is greater than 26, then obviously the number of translation methods is the same as that of s[i-1].

Because 01 is not valid, set the dp[i]=0;

**Code:**

```c++
dp[0]=dp[1]=1;
for(int i=1;i<n;++i){
 	int t=(int)atoi(s.substr(i-1,2).c_str());
 	if(s[i]=='0') dp[i]=0;            
 	if(t>=1&&t<=26) dp[i+1]=dp[i]+dp[i-1];
 	else dp[i+1]=dp[i];
}
```





## 098. Validate Binary Search Tree

**Tag:DFS**

**Solution:**

using pair to solve problem

**Code:**

```
if(root==NULL) return make_pair((LL)INT_MAX+1,(LL)INT_MIN-1);
pair<LL,LL> l=dfs(root->left),r=dfs(root->right);
if(!(l.second < root->val && root->val < r.first)) f=0;
return make_pair(min(l.first,(LL)root->val),max((LL)root->val,r.second));
```



