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



## 836. Rectangle Overlap

**Tag: Ad-Hoc**

**Solution:**

Enumerate the situation that are not overlap

**Code:**

```c++
if(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]) return false;
if(rec1[3]<=rec2[1]||rec1[1]>=rec2[3]) return false;
```



## 838. Push Dominoes

**Tag:  Ad-Hoc**

**Solution:**

Search the nearest the pair of RL. If the number of their distance is even, it will be RRLL. Otherwise. it will be RR.LL.

Pay attention to the case of ..R..

Use the preIndex and prechar to help to solve problem.

**Code:**

```c++
class Solution {
public:
    string domi;
    void handleL(int sat,int end){
        for(int i=sat;i<=end;i++) domi[i]='L';
    }    
    void handleR(int sat, int end){
        for(int i=sat;i<=end;i++) domi[i]='R';
    }    
    string pushDominoes(string domin){
        this->domi=domin;
        int n=domi.length();
        int preIn=-1;char pre='.';
        for(int i=0;i<n;i++){
            if(domi[i]=='L'){
                if(pre=='R'){
                    int mid=preIn+(i-preIn)/2;
                    if((i-preIn)%2){             
                        handleR(preIn+1,mid);
                        handleL(mid+1,i-1);
                    }
                    else{
                        handleR(preIn+1,mid-1);
                        handleL(mid+1,i-1);
                    }
                }
                else {
                    handleL(preIn+1,i-1);
                }
                pre='L';
                preIn=i;
            }
            else if(domi[i]=='R'){
                if(pre=='R'){
                    handleR(preIn+1,i-1);
                }
                pre='R';
                preIn=i;
            }
            else continue;        
        }
        if(pre=='R'&&preIn<(n-1)) {
            for(int i=preIn;i<n;i++) domi[i]='R';
        }
        return domi;
    }
};
```



## 839. Similar String Groups

**Tag: Union-find**

**Solution:**

If two strings are similar, that means one string of which two letters swapped  equals to the other string.

```c++
bool issimilar(string A,string B){
 	int alen=A.length(),blen=B.length();
 	int cnt=0;
 	if(alen!=blen) return false;       
  	else{
  		for(int i=0;i<alen;i++)
 			if(A[i]!=B[i]) cnt++;}
    return cnt==2;
}
```

