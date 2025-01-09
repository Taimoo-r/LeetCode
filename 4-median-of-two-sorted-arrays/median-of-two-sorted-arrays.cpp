
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     nums1.insert(nums1.end(),nums1.end(),nums2.end());
    //     int n = nums1.size();
    //     for(int i=0;i<nums1.size()-1;i++){
    //         for(int j=i+1;j<nums1.size();j++){
    //             if(nums1[i]>nums1[j]){
    //                 int temp = nums1[i];
    // nums1[i] = nums1[j];
    // nums1[j] = temp;
    //             }

    //         }
    //     }
    //     if(nums1.size()/2!=0){
    //         return nums1[nums1.size()+1];
    //     }
    //     else
    //     return (double)(nums1[nums1.size()/2] + (nums1[(nums1.size()/2)+1])/2.0);
    // }
    
    vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }
        
        // Determine the median(s) index/indices
        int n = merged.size();
        int mid = n / 2;
        if (n % 2 == 0) { // Even number of elements
            return (merged[mid - 1] + merged[mid]) / 2.0;
        } else { // Odd number of elements
            return merged[mid];
        }
    }
};