class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prevMax(n), nextMax(n);
        int pMax = height[0], nMax = height[n-1];
        prevMax[0] = -1, nextMax[n-1] = -1;
        for(int i = 1, j = n - 2 ; i < n ; i++, j--){ // i've done this so i can track previous & next maximum to calculate how much amount of water can be hold by the current block. 
            if(height[i] >= pMax){
                pMax = height[i];
                prevMax[i] = -1;
            }
            else if(height[i] < pMax){
                prevMax[i] = pMax;
            }
            if(height[j] >= nMax){
                nMax = height[j];
                nextMax[j] = -1;
            }
            else if(height[j] < nMax){
                nextMax[j] = nMax;
            }
        }
        int totalAmount = 0;
        for(int i = 0 ; i < n ; i++){
            if(prevMax[i] == -1 || nextMax[i] == -1) continue;
            totalAmount+=(min(prevMax[i], nextMax[i]) - height[i]);
        }
        return totalAmount;


        
    }
};