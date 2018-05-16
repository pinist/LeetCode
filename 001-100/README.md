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
nums.erase(unique(nums.begin(),nums.end()),nums.end());
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



