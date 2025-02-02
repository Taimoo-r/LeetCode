class Solution {
public:
    
    int minFlips(int a, int b, int c) {
        int checker = (a | b) ^ c;
        int cnt = 0;
        for(int i = 0 ; i < 32 ; i++){
            if((checker&(1<<i))!=0){
                int whatWeNeed = c&(1<<i);
                cout<<i<<" : "<<whatWeNeed<<endl;
                if(whatWeNeed){
                    cnt++;
                }
                else if(whatWeNeed == 0){
                    if((a&(1<<i))) cnt++;
                    if((b&(1<<i))) cnt++;
                }
            }
        }
        return cnt;
        
    }
};