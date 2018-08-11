/*
Given an input string, reverse the string word by word.
Example:  
Input: "the sky is blue",
Output: "blue is sky the".
 */
class Solution {
public:
    void reverseWords(string &s) {
        stringstream buf(s);
        s="";
        string tmp;
        while(buf>>tmp) s=s==""?tmp:(tmp+" "+s);
    }
};