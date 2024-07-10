class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1;
        int mid=(start+end)/2;
        while(start<end){
            if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=(start+end)/2;
        }
        return start;
        // vector<int> v;
        // v = arr;
        // sort(v.begin(),v.end());
        // int peak = v.back();

        // int start = 0,end = v.size()-1; 
        // while(start < end){
        //     int mid = (start + end) / 2;
        //     if(arr[mid]==peak)
        //     return mid;
        //     else if(arr[mid] < peak)
        //     start = mid + 1;
        //     else
        //     end = mid-1; 
        // }
        // return 0;

        //  vector<int> v;
        // v = arr;
        // sort(v.begin(),v.end());
        // int peak = v.back();
        // map<int,int> mp;
        // for(int i = 0 ; i < arr.size(); i ++){
        //     mp[arr[i]] = i;
        // }
        // return mp[peak];
    }
};