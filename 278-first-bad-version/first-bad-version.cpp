// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1))
        return 1;
        long start = 1, end = n,prev,mid;
        while(start<=end){
            mid = (start+end)/2;
            if(isBadVersion(mid)){
            prev = mid;
            break;
            }
            else if(!isBadVersion(mid))
            start = mid+1;
       }
       for(int i= prev-1;i>=1;i--){
        if(!isBadVersion(i)){
            return i+1;
        }
    }
    return -1;
    }
};