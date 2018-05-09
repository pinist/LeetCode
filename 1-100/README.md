# LeetCode 001-100



[TOC]



## 48. Rotate Image

**Tag: Ad-Hoc**

**Solution:**

An algorithm of image processing

2x2:  
$$
\alpha*\beta=\sum p
$$
$\alpha+\beta$

$ \begin{matrix}a&b\\c&d \end{matrix}​$  -> $ \begin{matrix}c&a\\d&b\end{matrix} ​$ 


3x3:  $\begin{matrix}a&b&c\\d&e&f\\g&h&i\end{matrix}$ -> $\begin{matrix}g&d&a\\h&e&b\\i&f&c\end{matrix}$ 

​          $\begin{matrix}A&B&c\\d&e&f\\g&h&i\end{matrix}$ ->  $\begin{matrix}g&d&A\\h&e&B\\i&f&c\end{matrix}$



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

