/*
Write an iterator that iterates through a run-length encoded sequence.
The iterator is initialized by RLEIterator(int[] A), where A is a run-length encoding of some sequence.  More specifically, for all even i, A[i] tells us the number of times that the non-negative integer value A[i+1] is repeated in the sequence.
The iterator supports one function: next(int n), which exhausts the next n elements (n >= 1) and returns the last element exhausted in this way.  If there is no element left to exhaust, next returns -1 instead.
For example, we start with A = [3,8,0,9,2,5], which is a run-length encoding of the sequence [8,8,8,5,5].  This is because the sequence can be read as "three eights, zero nines, two fives".
*/
class RLEIterator {
public:
    vector<int> T;
    int p;
    RLEIterator(vector<int> A) {
        T=A;
        p=0;
    }
    
    int next(int n) {
        int cnt=T.size();
        int ans=0;
        for(int i=0;i<cnt;i+=2){
            if(T[i]>=n) {
                ans=T[i+1];
                T[i]-=n;
                return ans;
            }
            else{               
                n-=T[i];T[i]=0;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */