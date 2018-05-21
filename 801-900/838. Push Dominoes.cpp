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