class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
        return "";
        unordered_map<char,int> original;
        for(auto& it : t){
            original[it]++;   
        }
        
        unordered_map<char,int> copy;
        int l, r;
        l = r = 0;
        int start = 0;
        int n = s.size();
        int required = original.size();
        int formed = 0;
        int minLength = INT_MAX;
        while(r < n){
            char c = s[r];
            copy[c]++;
            if(original.count(c) && original[c] == copy[c]){
                formed++;
            }

            while(l <= r && formed==required){
                if(r - l + 1 < minLength){
                    minLength = r - l + 1;
                    start = l;
                }
                char ch = s[l];
                copy[ch]--;
                if(original.count(ch) && original[ch] > copy[ch])
                    formed--;
                l++;
            }
            r++;
        }
        return minLength==INT_MAX ? "" : s.substr(start, minLength);
    }
};

















        // char c;
        // if(s.size()>0){
        //     if((int)s[0] > 96 && (int)s[0] <= 122)
        //     c = 'a';
        //     else
        //     c = 'A';
        // }
        // string res="";
        // vector<int> S(26,0), T(26,0);
        // set<char> set;
        // for(auto it : t){
        //     set.insert(it);
        //     T[it - c]++;
        // }
        
        // string temp = "";
        // int start = 0,end = 0;
        // while(  end < s.size()){
        //     if(S==T){
        //         if(res=="")
        //         res = temp;
        //         else
        //         res.size() < temp.size() ? res : res = temp;
        //         cout<<res<<" ";
        //         temp = temp.substr(start+1, end - start);
        //         cout<<temp;
        //         if(set.find(s[start])!=set.end())
        //         S[s[start]]--;
        //         start++;
        //     }
        //     else if(set.find(s[end])!=set.end())
        //     S[s[end] - c]++;
        //     else
        //     temp+=s[end++];
        // }
        // return res;
