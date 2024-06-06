// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1))
        return 1;
        int start = 1, end = n,prev,mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(isBadVersion(mid)){
            end = mid-1;
            }
            else if(!isBadVersion(mid))
            start = mid+1;
       }
    return start;
    }
};