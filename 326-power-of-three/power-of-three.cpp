class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
        return false;
        else if(n<0){
            for(int i=-1;i<-20;i--){
                if(pow(3,i)==n)
                return true;
            }
            return false;
        }
        else{
            for(int i=0;i<20;i++){
                if(pow(3,i)==n)
                return true;
            }
            return false;
        }
    }
};