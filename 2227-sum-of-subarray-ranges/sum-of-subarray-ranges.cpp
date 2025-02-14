class Solution {
    long long mini, maxi;
public:
    void Minimums(vector<int> &nums){
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            left[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right[i] = st.empty() ? n - i :st.top() - i; 
            st.push(i);
        }
        for(int i = 0 ; i < n ; i++){
            mini+=left[i]*right[i]*(long long)nums[i]; 
        }

    }    
    void Maximums(vector<int> &nums){
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            left[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            right[i] = st.empty() ? n - i :st.top() - i; 
            st.push(i);
        }
        for(int i = 0 ; i < n ; i++){
            maxi+=left[i]*right[i]*(long long)nums[i]; 
        }

    }
    long long subArrayRanges(vector<int>& nums) {
        maxi = 0, mini = 0;
        Maximums(nums);
        Minimums(nums);
        return maxi - mini;
        
    }
};