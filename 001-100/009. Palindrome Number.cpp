/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Example 1:
Input: 121
Output: true
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int before=x,after=0;
        while(x){
            after=(after*10)+(x%10);
            x/=10;
        }
        return before==after;
    }
};