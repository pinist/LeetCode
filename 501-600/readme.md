# LeetCode 501-600

[TOC]

## 513. Find Bottom Left Tree Value

**Tag: BFS**

**Solution:**

Put the element of queue into vector when doing the second while-loop.



**Code:**

```c++
 while(!tmp.empty()){
     vec.push_back(tmp.front()->val);
     qu.push(tmp.front());
     tmp.pop();
}
ans=(vec.size()==0?ans:vec[0]);vec.clear();
```



## 515. Find Largest Value in Each Tree Row

**Tag: BFS**

**Solution:**

Get the maximum element of queue  when doing the second while-loop.

This problem is similar to 513.

**Code:**

```c++
while(!tmp.empty()){
 	res=max(res,tmp.front()->val);
 	qu.push(tmp.front());
 	tmp.pop();
}
ans.push_back(res);
```



## 542.  01 Matrix

**Tag: BFS**

**Solution:**

1. count the coordinate whose value is 1 and set $vis[x][y]$=1;
2. BFS

**Code:**

```c++
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(!matrix[i][j]) {
			qu.push(make_pair(i,j));
			vis[i][j]=0;
     	}
     }
}
while(!qu.empty()){
	int x=qu.front().first; 
	int y=qu.front().second;qu.pop();
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(0<=nx&&nx<n&&0<=ny&&ny<m&&matrix[nx][ny]&&vis[nx][ny]==-1){
			vis[nx][ny]=vis[x][y]+1;
			qu.push(make_pair(nx,ny));
         }
	}
}
```



## 547. Friend Circles

**Tag: Union Find**

**Solution:**

This problem is aimed at count the number of friend circles.

**Code:**

```c++
int cnt(int size){
 	int sum=0;
 	for(int i=1;i<=size;i++){
 		if(vec[i]==i) sum++;                
	}
	return sum;
}
```





