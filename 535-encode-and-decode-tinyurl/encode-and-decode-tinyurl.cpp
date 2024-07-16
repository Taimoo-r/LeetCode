class Solution {
public:
    unordered_map<string,string> mp;

    string hashing(string longUrl){
        string res = "";
        for(int i = 0 ; i < 6 ; i++){
        int random = rand() % 3;
        if(random==1)
        res+=('0' + random % 10);
        else if(random==2)
        res+=('a' + random % 26);
        else
        res+=('A' + random % 26);
        }
        mp[res] = longUrl;
        return res;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tinyUrl = "http://tinyurl.com/";
        string hashed = hashing(longUrl);
        return tinyUrl+=hashed;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl.substr(shortUrl.size()-6,6)];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));