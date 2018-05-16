# LeetCode 001-100



[TOC]

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


## 006. ZigZag Conversion

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

