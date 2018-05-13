class Solution {
public:
    string maskPII(string S) {
        string res;
        int n=S.size();
        if('a'<=S[0]&&S[0]<='z'||'A'<=S[0]&&S[0]<='Z'){
            char c=tolower(S[0]);
            res.append(1,c);
            res.append(5,'*');
            int i=0,f=1;
            while(i<n){
                if(S[i+1]=='@'&&f) {
                    res.append(1,tolower(S[i++]));
                    res.append(1,'@');
                    f=0;i++;
                }
                if(!f) {
                    if('A'<=S[i]&&S[i]<='Z') {
                        char c=tolower(S[i]); res.append(1,c);}
                    else res.append(1,S[i]);
                }
                i++;
            }
        }
        else{
            string tmp;
            for(int i=0;i<n;i++) if(S[i]>='0'&&S[i]<='9') tmp.append(1,S[i]);
            if(tmp.size()>10){
                res.append(1,'+');
                res.append(tmp.size()-10,'*');
                res.append(1,'-');
            }
            int m=tmp.length();
            //cout<<tmp<<endl<<m<<endl;
            res.append(3,'*');res.append(1,'-');res.append(3,'*');res.append(1,'-');            
            for(int i=m-4;i<m;i++) res.append(1,tmp[i]);
        }
        return res;
    }
};