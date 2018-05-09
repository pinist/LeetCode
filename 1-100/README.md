# LeetCode 001-100



[TOC]



## 48. Rotate Image

**Tag: Ad-Hoc**

**Solution:**

An algorithm of image processing

2x2: $ab\\cd$ -> $ca\\db$

3x3 $abc\\def\\ghi$ -> $gda\\heb\\ifc$

$\begin{matrix}A&B&c\\d&e&f\\g&h&i\end{matrix}​$ ->  $gdA\\heB\\ifc​$

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

