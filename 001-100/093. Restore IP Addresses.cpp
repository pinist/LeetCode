/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
class Solution {
public:
    vector<string> ans,tmp;
    string s;
    bool valid(string s){
        int n=s.length();
        if(n==2)
        {   
            if(s[0]=='0')
                return false;
        }
        if(n==3)
        {
            if(s[0]=='0'||atoi(s.c_str())>255)
                return false;
        }
        return true;
    }
    
    void dfs(int dep,int pos){        
        int n=s.length()-pos;
        if((4-dep)*3<n) return;
        
        if(pos==s.length()&&dep==4){           
            string ip;
            for(int i=0;i<tmp.size();i++)
            {
                ip+=(tmp[i]+'.');
            }
            ip.pop_back();
            ans.push_back(ip);
        }
        if(pos<s.length()){
            for(int i=1;i<=3;i++){
                string ct=s.substr(pos,i);
                
                if(valid(ct)==true) 
                {   tmp.push_back(ct);dfs(dep+1,pos+i);   
                    tmp.pop_back();
                }
            }
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        this->s=s; 
        dfs(0,0);
        return ans;
    }
};
