# LeetCode 601-700

[TOC]

## 684.Redundant Connection

**Tag: Union Find**

**Solution:**

This problem is aimed at erase any edge which can help to connect one friend circle.

**Code:**

```c++
for(int i=0;i<edges.size();i++){
 	int p1=find(edges[i][0]);
 	int p2=find(edges[i][1]);
 	if(p1!=p2) uf[p2]=p1;
 	else return edges[i];
}
return vector<int>(0,0);
```

