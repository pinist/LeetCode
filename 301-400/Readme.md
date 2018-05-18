# LeetCode 301-400

[TOC]

## 303. Range Sum Query - Immutable

**Tag: Prefix sum**

**Code:**

```c++
NumArray(vector<int> nums) {
	sum.push_back(0);
	for(int i=0;i<nums.size();i++)
		sum.push_back(nums[i]+sum[i]);
}
```



## 307. Range Sum Query - Mutable

**Tag: Binary Indexed Tree**

**Code:**

```c++
NumArray(vector<int>nums) {
	sum.push_back(0);
	for(int i=0;i<nums.size();i++)
		sum.push_back(nums[i]+sum[i]);
}
```

