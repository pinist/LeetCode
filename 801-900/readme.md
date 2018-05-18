# LeetCode 801-900



[TOC]

## 829.Consecutive Numbers Sum

**Tag: Ad-Hoc**

**Solution:**

$sum N=(i-1)*j+\frac{j(j+1)}{2}$

$N=1+2+...+n$

$N=2+3+...+n+n+1$

$N=1+2+...+n+n$

or $N=1+2+...+n+n+n$

```c++
int ans=0;
for(int k=2;(k*(k+1))/2<=N;k++){
	for(int i=max(N/k-k/2,1),t=0;t<N;i++){
		t=(i-1)*k+(k*(k+1))/2;
 		if(t==N) ans++;
	}       
}
```



## 830. Positions of Large Groups 

**Tag: Ad-Hoc**

**Solution:**

This problem is similar to 443(string compression)

**Code:**

```c++
while(i<n){
 	if(S[i]!=S[i+1]||i==n-1){
 	i++;continue;
 }
 else{
 	int mark=i;
 	ans.push_back(i);
 	while(S[i]==S[mark]&&i<n) i++;
 	if((i-mark)>=3){
 		ans.push_back(i-1);
 		res.push_back(ans);
	}
 	ans.clear();
 	}
}
```



## 835.Image Overlap

**Tag: Ad-Hoc**

**Solution:**

sliding the matrix A left one step and placing it on top of matrix B means overlap A and B from the second row of matrix A 

**Code:**

```c++
for(int i=-n+1;i<n;i++){
	for(int j=-n+1;j<n;j++){
	int count=0;
		for(int k=max(i,0);k<min(n+i,n);k++){
			for(int l=max(j,0);l<min(n+j,n);l++){
				if(A[k-i][l-j]&&B[k][l]) count++;
			}
   		}
	res=max(res,count);
	}
}
```



